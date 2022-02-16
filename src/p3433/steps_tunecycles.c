int steps_guess(long long *bs,long long *gs,long long l)
{
  /* l=3: bs=0 gs=0 bench=6202 baseline=6202 */
  /* l=5: bs=0 gs=0 bench=7916 baseline=8016 */
  /* l=7: bs=0 gs=0 bench=11006 baseline=10944 */
  /* l=11: bs=0 gs=0 bench=16862 baseline=16604 */
  /* l=17: bs=0 gs=0 bench=24830 baseline=24462 */
  /* l=29: bs=0 gs=0 bench=41662 baseline=41358 */
  /* l=37: bs=0 gs=0 bench=52236 baseline=51822 */
  /* l=43: bs=0 gs=0 bench=60742 baseline=60114 */
  /* l=59: bs=0 gs=0 bench=82496 baseline=82492 */
  /* l=61: bs=0 gs=0 bench=85146 baseline=84628 */
  /* l=89: bs=0 gs=0 bench=122254 baseline=122180 */
  /* l=109: bs=0 gs=0 bench=149324 baseline=148518 */
  /* l=151: bs=0 gs=0 bench=205438 baseline=204446 */
  /* l=157: bs=0 gs=0 bench=213492 baseline=212978 */
  /* l=173: bs=0 gs=0 bench=234972 baseline=233648 */
  if (l <= 173) { *bs = 0; *gs = 0; return 1; }
  /* l=251: bs=10 gs=6 bench=329916 baseline=340518 */
  if (l <= 251) { *bs = 10; *gs = 6; return 1; }
  /* l=347: bs=12 gs=7 bench=425334 baseline=468938 */
  /* l=383: bs=12 gs=7 bench=473552 baseline=514294 */
  if (l <= 383) { *bs = 12; *gs = 7; return 1; }
  /* l=443: bs=12 gs=9 bench=515806 baseline=597690 */
  if (l <= 443) { *bs = 12; *gs = 9; return 1; }
  /* l=463: bs=14 gs=8 bench=509864 baseline=619572 */
  /* l=467: bs=14 gs=8 bench=514676 baseline=623962 */
  if (l <= 467) { *bs = 14; *gs = 8; return 1; }
  /* l=593: bs=16 gs=9 bench=624680 baseline=791700 */
  if (l <= 593) { *bs = 16; *gs = 9; return 1; }
  /* l=659: bs=16 gs=10 bench=681076 baseline=879784 */
  /* l=673: bs=16 gs=10 bench=699668 baseline=900148 */
  if (l <= 673) { *bs = 16; *gs = 10; return 1; }
  /* l=739: bs=18 gs=10 bench=768474 baseline=992240 */
  if (l <= 739) { *bs = 18; *gs = 10; return 1; }
  /* l=787: bs=16 gs=12 bench=790000 baseline=1049678 */
  if (l <= 787) { *bs = 16; *gs = 12; return 1; }
  /* l=877: bs=18 gs=12 bench=871094 baseline=1169794 */
  /* l=887: bs=18 gs=12 bench=885824 baseline=1191188 */
  if (l <= 887) { *bs = 18; *gs = 12; return 1; }
  /* l=967: bs=20 gs=12 bench=934108 baseline=1289556 */
  if (l <= 967) { *bs = 20; *gs = 12; return 1; }
  /* l=1999: bs=30 gs=16 bench=1654414 baseline=2662062 */
  if (l <= 1999) { *bs = 30; *gs = 16; return 1; }
  /* l=3433: bs=32 gs=26 bench=2619228 baseline=4683120 */
  if (l <= 3433) { *bs = 32; *gs = 26; return 1; }
  return 0;
}
