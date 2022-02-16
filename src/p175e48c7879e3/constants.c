// p = 65859329255626014122673067371248499252655857645798864279006971710635195236351
//
// p-1 = 2 * 5^2 * 13 * 17 * 29 * 37 * 41 * 103 * 109 * 149 * 191 * 269 * 313 * 367 * 379 * 503 * 587 * 683 * 1217 * 1487 * 13523 * 14249 * 514873364354603358413793457
// p+1 = 2^61 * 3^4 * 31^4 * 127^4 * 307^4 * 353^4 * 509^4 * 631^4

#include "constants.h"

const long class_mod_4 = 3;
const long two_tors_height = 61;

const long security_level = 128;
const long signing_length = 1000 ;
const long signing_length_two_tors_height_step = 17;
const long last_step_length = 24;
const long len_tail = 0;
const bool need_even_commit = false;
const bool need_even_chall = true;

const char* p_str =
  "65859329255626014122673067371248499252655857645798864279006971710635195236351";
const char* all_the_torsion_str =
  "4337451250000956595472202903129490595653938098091330531015363032308213942702063579676391246754051450274367343364740782860562733306223914248703002751795200";

const uintbig p_plus_odd_cofactor =
  {0x2000000000000000};
const uintbig p_minus_odd_cofactor =
  {0x7d2a2bff5013bfb6, 0x2636ea644199a7};
const uintbig p_even_cofactor =
  {0xad351999daa742d1, 0xcdc0927359205f30, 0x8cd8799c68c6cf72, 0x4};

#define M_LEN 19
const long p_minus_len = M_LEN;
const long p_minus_fact[M_LEN] =
  {5, 13, 17, 29, 37, 41, 103, 109, 149, 191, 269, 313, 367, 379, 503, 587, 683, 1217, 1487};
const long p_minus_mult[M_LEN] =
  {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

#define P_LEN 7
const long p_plus_len = P_LEN;
const long p_plus_fact[P_LEN] =
  {3, 31, 127, 307, 353, 509, 631};
const long p_plus_mult[P_LEN] =
  {4, 4, 4, 4, 4, 4, 4};

// TODO: Adjust the parameters below!
//
// the multiplicities to take to obtain log2(p) bits of torsion (for commitment)
const long p_minus_mult_com[M_LEN] =
  {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const long p_plus_mult_com[P_LEN] =
  {0, 0, 0, 0, 0, 4, 4};

// the multiplicities to take to obtain log2(p)/2 bits of torsion (for challenge)
const long p_minus_mult_cha[M_LEN] =
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const long p_plus_mult_cha[P_LEN] =
  {4, 4, 4, 4, 4, 0, 0};
