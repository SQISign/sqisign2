// p = 42948926403468349749074747890536837397505730522093546474444185102642149588991
//
// p-1 = 2 * 5 * 7 * 13 * 17^2 * 79 * 97 * 101 * 349 * 487 * 499 * 521 * 619 * 647 * 733 * 863 * 997 * 1427 * 1877 * 15358097 * 79150597 * 164027047 * 35399738117
// p+1 = 2^61 * 3^24 * 43^4 * 131^4 * 223^4 * 569^4 * 709^4

#include "constants.h"

const long class_mod_4 = 3;
const long two_tors_height = 61;

const long security_level = 127;
const long signing_length = 1000 ;
const long signing_length_two_tors_height_step = 17;
const long last_step_length = 24;
const long len_tail = 0;
const bool need_even_commit = false;
const bool need_even_chall = true;

const char* p_str =
  "42948926403468349749074747890536837397505730522093546474444185102642149588991";
const char* all_the_torsion_str =
  "1844610279210540756216969080480350638404251353716183937282256639131255812787793643891433942043490653500185708951047310527674531501250806918805310228398080";

const uintbig p_plus_odd_cofactor =
  {0x2000000000000000};
const uintbig p_minus_odd_cofactor =
  {0xc4dfe1fdba71c37e, 0x2b8036a386fc6};
const uintbig p_even_cofactor =
  {0xebad6bbfe798d931, 0x48b6a6c1334cdd76, 0xf7a1d8de7e489e76, 0x2};

#define M_LEN 18
const long p_minus_len = M_LEN;
const long p_minus_fact[M_LEN] =
  {5, 7, 13, 17, 79, 97, 101, 349, 487, 499, 521, 619, 647, 733, 863, 997, 1427, 1877};
const long p_minus_mult[M_LEN] =
  {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

#define P_LEN 6
const long p_plus_len = P_LEN;
const long p_plus_fact[P_LEN] =
  {3, 43, 131, 223, 569, 709};
const long p_plus_mult[P_LEN] =
  {24, 4, 4, 4, 4, 4};

// TODO: Adjust the parameters below!
//
// the multiplicities to take to obtain log2(p) bits of torsion (for commitment)
const long p_minus_mult_com[M_LEN] =
  {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
const long p_plus_mult_com[P_LEN] =
  { 0, 0, 4, 4, 4, 4};


// the multiplicities to take to obtain log2(p)/2 bits of torsion (for challenge)
const long p_minus_mult_cha[M_LEN] =
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const long p_plus_mult_cha[P_LEN] =
  {24, 4, 0, 0, 0, 0};
