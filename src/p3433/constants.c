// p = 78760160831068261177251736046316660478966855093437012785336308302484099563521
//
// p-1 = 2^67 * 5 * 7 * 11 * 29 * 37 * 89 * 157 * 251 * 383 * 443 * 787 * 967 * 49043 * 3120671 * 28240013 * 660053958977639
// p+1 = 2 * 3^63 * 17 * 43 * 59^2 * 61 * 109 * 151 * 173 * 347 * 463 * 467 * 593 * 659 * 673 * 739 * 877 * 887 * 1999 * 3433

#include "constants.h"

const long class_mod_4 = 1;
const long two_tors_height = 67;

const long security_level = 128;
const long signing_length = 1000 ;
const long signing_length_two_tors_height_step = 15;
const long last_step_length = 62;
const bool need_even_commit = true;
const long len_tail = 0;

const char* p_str =
  "78760160831068261177251736046316660478966855093437012785336308302484099563521";
const char* all_the_torsion_str =
  "6203162934135739133158724918752040281883195174309763785457814189982571872751674419711191406131664202840997573155982212536168929840617729690085222713917440";

const uintbig p_plus_odd_cofactor =
  {0x2};
const uintbig p_minus_odd_cofactor =
  {0x0000000000000000, 0x174ab5329ffb8df8, 0x46539df773234};
const uintbig p_even_cofactor =
  {0xe8f2fc177f66fb31, 0xa4f6809b61705a53, 0x15c4157b3acb12cf};

#define M_LEN 12
const long p_minus_len = M_LEN;
const long p_minus_fact[M_LEN] =
  {5, 7, 11, 29, 37, 89, 157, 251, 383, 443, 787, 967};
const long p_minus_mult[M_LEN] =
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

#define P_LEN 19
const long p_plus_len = P_LEN;
const long p_plus_fact[P_LEN] =
  {3, 17, 43, 59, 61, 109, 151, 173, 347, 463, 467, 593, 659, 673, 739, 877, 887, 1999, 3433};
const long p_plus_mult[P_LEN] =
  {63, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// TODO: Adjust the parameters below!
//
// the multiplicities to take to obtain log2(p) bits of torsion (for commitment)
const long p_minus_mult_com[M_LEN] =
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const long p_plus_mult_com[P_LEN] =
  {63, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// the multiplicities to take to obtain log2(p)/2 bits of torsion (for challenge)
const long p_minus_mult_cha[M_LEN] =
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const long p_plus_mult_cha[P_LEN] =
  {63, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
