int steps_guess(long long *bs,long long *gs,long long l)
{
  /* l=3: bs=0 gs=0 bench=5300 baseline=5230 */
  /* l=5: bs=0 gs=0 bench=8276 baseline=9254 */
  /* l=7: bs=0 gs=0 bench=10364 baseline=11216 */
  /* l=13: bs=0 gs=0 bench=17836 baseline=18830 */
  /* l=17: bs=0 gs=0 bench=21760 baseline=21560 */
  /* l=43: bs=0 gs=0 bench=53716 baseline=53262 */
  /* l=79: bs=0 gs=0 bench=97158 baseline=97040 */
  /* l=97: bs=0 gs=0 bench=117698 baseline=117266 */
  /* l=101: bs=0 gs=0 bench=122860 baseline=122436 */
  /* l=131: bs=0 gs=0 bench=158290 baseline=158364 */
  /* l=223: bs=0 gs=0 bench=269062 baseline=269068 */
  if (l <= 223) { *bs = 0; *gs = 0; return 1; }
  /* l=349: bs=14 gs=6 bench=392262 baseline=419910 */
  if (l <= 349) { *bs = 14; *gs = 6; return 1; }
  /* l=487: bs=14 gs=8 bench=495596 baseline=583146 */
  /* l=499: bs=14 gs=8 bench=509988 baseline=596674 */
  if (l <= 499) { *bs = 14; *gs = 8; return 1; }
  /* l=521: bs=16 gs=8 bench=516598 baseline=623788 */
  if (l <= 521) { *bs = 16; *gs = 8; return 1; }
  /* l=569: bs=14 gs=10 bench=557192 baseline=688204 */
  if (l <= 569) { *bs = 14; *gs = 10; return 1; }
  /* l=619: bs=14 gs=11 bench=601778 baseline=742268 */
  /* l=647: bs=14 gs=11 bench=635992 baseline=773142 */
  if (l <= 647) { *bs = 14; *gs = 11; return 1; }
  /* l=709: bs=16 gs=11 bench=662008 baseline=846350 */
  /* l=733: bs=16 gs=11 bench=691648 baseline=879254 */
  if (l <= 733) { *bs = 16; *gs = 11; return 1; }
  /* l=863: bs=16 gs=13 bench=803006 baseline=1031756 */
  if (l <= 863) { *bs = 16; *gs = 13; return 1; }
  /* l=997: bs=22 gs=11 bench=894930 baseline=1189820 */
  if (l <= 997) { *bs = 22; *gs = 11; return 1; }
  /* l=1427: bs=22 gs=16 bench=1174848 baseline=1705084 */
  if (l <= 1427) { *bs = 22; *gs = 16; return 1; }
  /* l=1877: bs=30 gs=15 bench=1426414 baseline=2237252 */
  if (l <= 1877) { *bs = 30; *gs = 15; return 1; }
  return 0;
}
