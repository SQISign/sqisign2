#include "precomputed.h"

// Field constants
fp minus_one_half =
  { 0xa8652148ffffffffULL, 0xe8d8027ca52ca964ULL, 0x592e3b521bb9479dULL, 0x51848ab2db3c54c8ULL };
fp minus_one_third =
  { 0x1aee1630aaaaaaaaULL, 0xf09001a86e1dc643ULL, 0x3b74278c127b8513ULL, 0x36585c773cd2e330ULL };
// fp2_non_residue()^((p-1)/2)
fp2 non_residue_p_minus_1_halves = {
  { 0x6ac6dad604e67ebdULL, 0x1f3b219e21a6b591ULL, 0xa93d7bef6dcc52e7ULL, 0xee2e5b7107ab1ULL },
  { 0xc88f698a0759be1bULL, 0x97b0b4e9d7a6b9beULL, 0xd70a7539406bc3f8ULL, 0x519adf0b6dd50cd2ULL }
};
