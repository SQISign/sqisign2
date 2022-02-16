#include "fp.h"
#include "rng.h"
#include "constants.h"

#define FP_LIMBS (4 * 64 / GMP_LIMB_BITS)

const fp fp_0 = {0, 0, 0, 0};
const fp fp_1 = {1, 0, 0, 0};
const uintbig p = { 0x0000000000000001, 0x4797e0bbfb37d988,
                    0x27b404db0b82d29f, 0xae20abd9d658967d };
// 2^256 - p
const uintbig mp = { 0xffffffffffffffff, 0xb8681f4404c82677,
                     0xd84bfb24f47d2d60, 0x51df542629a76982 };

void fp_set(fp *x, uint64_t y) {
  x->x.c[0] = y;
  x->x.c[1] = x->x.c[2] = x->x.c[3] = 0;
}

void fp_cswap(fp *x, fp *y, bool c) {
  uint64_t tmp;
  for (int i = 0; i < 4*c; i++) {
    tmp = y->x.c[i];
    y->x.c[i] = x->x.c[i];
    x->x.c[i] = tmp;
  }
}

void fp_enc(fp *x, uintbig const *y) {
  x->x.c[0] = y->c[0]; x->x.c[1] = y->c[1];
  x->x.c[2] = y->c[2]; x->x.c[3] = y->c[3];
}
void fp_dec(uintbig *x, fp const *y) {
  x->c[0] = y->x.c[0]; x->c[1] = y->x.c[1];
  x->c[2] = y->x.c[2]; x->c[3] = y->x.c[3];
}

void fp_add2(fp *x, fp const *y) { fp_add3(x, x, y); }
void fp_sub2(fp *x, fp const *y) { fp_sub3(x, x, y); }
void fp_mul2(fp *x, fp const *y) { fp_mul3(x, x, y); }

void fp_add3(fp *x, fp const *y, fp const *z) {
  mp_limb_t carry = mpn_add_n(x->x.c, y->x.c, z->x.c, FP_LIMBS);
  if (carry) {
    mpn_add_n(x->x.c, x->x.c, mp.c, FP_LIMBS);
  } else if (x->x.c[3] > p.c[3] ||
	     (x->x.c[3] == p.c[3] && x->x.c[2] > p.c[2]) ||
	     (x->x.c[3] == p.c[3] && x->x.c[2] == p.c[2] && x->x.c[1] > p.c[1]) ||
	     (x->x.c[3] == p.c[3] && x->x.c[2] == p.c[2] && x->x.c[1] == p.c[1] && x->x.c[0] >= p.c[0])
	     ) {
    mpn_sub_n(x->x.c, x->x.c, p.c, FP_LIMBS);
  }
}

void fp_sub3(fp *x, fp const *y, fp const *z) {
  mp_limb_t borrow = mpn_sub_n(x->x.c, y->x.c, z->x.c, FP_LIMBS);
  if (borrow) {
    mpn_sub_n(x->x.c, x->x.c, mp.c, FP_LIMBS);
  }
}

void fp_mul3(fp *x, fp const *y, fp const *z) {
  uint64_t tmp[8], thrash[5];
  mpn_mul_n(tmp, y->x.c, z->x.c, FP_LIMBS);
  mpn_tdiv_qr(thrash, x->x.c, 0, tmp, 2 * FP_LIMBS, p.c, FP_LIMBS);
}

void fp_sq1(fp *x) { fp_sq2(x, x); }
void fp_sq2(fp *x, fp const *y) { fp_mul3(x, y, y); }
void fp_inv(fp *x) {
  mpz_t res, mpzx, mpzp;
  mpz_init(res);
  mpz_roinit_n(mpzx, x->x.c, FP_LIMBS);
  mpz_roinit_n(mpzp, p.c, FP_LIMBS);
  mpz_invert(res, mpzx, mpzp);
  int i = 0;
  for (; i < res->_mp_size; ++i) {
    x->x.c[i] = ((uint64_t*)res->_mp_d)[i];
  }
  for (; i < 4; ++i) {
    x->x.c[i] = 0;
  }
  mpz_clear(res);
}
bool fp_issquare(fp *x) {
  mpz_t mpzx, mpzp;
  mpz_roinit_n(mpzx, x->x.c, FP_LIMBS);
  mpz_roinit_n(mpzp, p.c, FP_LIMBS);
  int s = mpz_legendre(mpzx, mpzp);
  return s+1;
}


/* 
   Given:
   - t of order at most 2^ord,
   - g of exact order 2^(ord+Δ)

   return r such that r^(2^Δ) t = 1 (mod p).

   Recursive algorithm, quasi-linear in ord, much faster than standard
   T-S.
*/
static void tonelli(mpz_t r, const mpz_t t, uint ord, const mpz_t g, uint delta, const mpz_t p) {
  if (ord == 0) {
    mpz_set_ui(r, 1);
  } else if (ord == 1) {
    if (mpz_cmp_ui(t, 1) == 0)
      mpz_set_ui(r, 1);
    else
      mpz_set(r, g);
  } else {
    // τ = g^2m
    // ρ² τ = 1  ==> ρ = g^-m
    // σ² τ^f = 1  ==> σ = g^-mf = g^fa   a = -m (f*)
    // θ := g^2a τ = g^2(a + m) = g^2f*b
    // λ² θ = 1  ==>  (λ g^a)² τ = 1    
    uint h = ord / 2;
    mpz_t gg, tt, s;
    mpz_init_set(gg, g);
    mpz_init_set(tt, t);
    mpz_init(s);
    
    // s^(2^(Δ+h)) t^(2^h) = 1 (mod p)
    for (uint i = 0; i < h; i++) {
      mpz_mul(tt, tt, tt); mpz_mod(tt, tt, p);
    }
    tonelli(s, tt, ord - h, g, delta + h, p);

    // tt := s^(2^Δ) t
    // r^(2^Δ) tt = 1
    mpz_set(tt, s);
    for (uint i = 0; i < delta; i++) {
      mpz_mul(tt, tt, tt); mpz_mod(tt, tt, p);
    }
    mpz_mul(tt, tt, t); mpz_mod(tt, tt, p);
    for (uint i = 0; i < ord - h; i++) {
      mpz_mul(gg, gg, gg); mpz_mod(gg, gg, p);
    }
    tonelli(r, tt, h, gg, delta, p);

    // (r s)^(2^Δ) t = 1
    mpz_mul(r, r, s); mpz_mod(r, r, p);
    
    mpz_clears(gg, tt, s, NULL);
  }
}

void fp_sqrt(fp *x) {
  if (fp_iszero(x))
    return;
  
  // Tonelli-Shanks
  mpz_t mpzx, mpzp, mpzcof, mpzsqrt, mpzroot, mpzx2;
  mpz_init(mpzsqrt);
  mpz_init(mpzx2);

  mpz_roinit_n(mpzx, x->x.c, FP_LIMBS);
  mpz_roinit_n(mpzp, p.c, FP_LIMBS);
  mpz_roinit_n(mpzcof, p_even_cofactor.c, FP_LIMBS);
 
  mpz_init_set_si(mpzroot, -3);
  mpz_powm(mpzroot, mpzroot, mpzcof, mpzp); // 2^two_tors_height root of unity

  mpz_div_ui(mpzsqrt, mpzcof, 2);
  mpz_powm(mpzx2, mpzx, mpzsqrt, mpzp);  // x^(cof-1)/2
  mpz_mul(mpzsqrt, mpzx2, mpzx);
  mpz_mod(mpzsqrt, mpzsqrt, mpzp);       // x^(cof+1)/2
  mpz_mul(mpzx2, mpzx2, mpzsqrt);
  mpz_mod(mpzx2, mpzx2, mpzp);           // x^cof

  // x₂² x^cof = 1
  tonelli(mpzx2, mpzx2, two_tors_height - 1, mpzroot, 1, mpzp);

  mpz_mul(mpzsqrt, mpzsqrt, mpzx2);
  mpz_mod(mpzsqrt, mpzsqrt, mpzp);
  
  int i = 0;
  for (; i < mpzsqrt->_mp_size; ++i) {
    x->x.c[i] = ((uint64_t*)mpzsqrt->_mp_d)[i];
  }
  for (; i < 4; ++i) {
    x->x.c[i] = 0;
  }

  mpz_clear(mpzx2);
  mpz_clear(mpzsqrt);
  mpz_clear(mpzroot);
}

void fp_random(fp *x) {
  uint64_t thrash;
  randombytes(x->x.c + 0, 32);
  mpn_tdiv_qr(&thrash, x->x.c, 0, x->x.c, FP_LIMBS, p.c, FP_LIMBS);
}
