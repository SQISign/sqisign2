int steps_guess(long long *bs,long long *gs,long long l)
{
  /* l=3: bs=0 gs=0 bench=5310 baseline=5232 */
  /* l=5: bs=0 gs=0 bench=6808 baseline=6706 */
  /* l=13: bs=0 gs=0 bench=17126 baseline=17068 */
  /* l=17: bs=0 gs=0 bench=21758 baseline=21500 */
  /* l=29: bs=0 gs=0 bench=36788 baseline=36628 */
  /* l=31: bs=0 gs=0 bench=39560 baseline=39380 */
  /* l=37: bs=0 gs=0 bench=46172 baseline=45800 */
  /* l=41: bs=0 gs=0 bench=50948 baseline=50740 */
  /* l=103: bs=0 gs=0 bench=125520 baseline=125464 */
  /* l=109: bs=0 gs=0 bench=132906 baseline=132222 */
  /* l=127: bs=0 gs=0 bench=169516 baseline=168074 */
  /* l=149: bs=0 gs=0 bench=180148 baseline=179796 */
  /* l=191: bs=0 gs=0 bench=231286 baseline=230790 */
  if (l <= 191) { *bs = 0; *gs = 0; return 1; }
  /* l=269: bs=10 gs=6 bench=319912 baseline=322728 */
  if (l <= 269) { *bs = 10; *gs = 6; return 1; }
  /* l=307: bs=12 gs=6 bench=355488 baseline=367970 */
  /* l=313: bs=12 gs=6 bench=361472 baseline=378444 */
  if (l <= 313) { *bs = 12; *gs = 6; return 1; }
  /* l=353: bs=14 gs=6 bench=395702 baseline=423126 */
  /* l=367: bs=14 gs=6 bench=412530 baseline=439226 */
  /* l=379: bs=14 gs=6 bench=426858 baseline=458126 */
  if (l <= 379) { *bs = 14; *gs = 6; return 1; }
  /* l=503: bs=14 gs=8 bench=514430 baseline=602294 */
  if (l <= 503) { *bs = 14; *gs = 8; return 1; }
  /* l=509: bs=14 gs=9 bench=503188 baseline=611162 */
  if (l <= 509) { *bs = 14; *gs = 9; return 1; }
  /* l=587: bs=16 gs=9 bench=566678 baseline=704192 */
  if (l <= 587) { *bs = 16; *gs = 9; return 1; }
  /* l=631: bs=14 gs=11 bench=614788 baseline=755426 */
  if (l <= 631) { *bs = 14; *gs = 11; return 1; }
  /* l=683: bs=16 gs=10 bench=653824 baseline=819504 */
  if (l <= 683) { *bs = 16; *gs = 10; return 1; }
  /* l=1217: bs=24 gs=12 bench=1130058 baseline=1455464 */
  if (l <= 1217) { *bs = 24; *gs = 12; return 1; }
  /* l=1487: bs=24 gs=15 bench=1234536 baseline=1881838 */
  if (l <= 1487) { *bs = 24; *gs = 15; return 1; }
  return 0;
}
