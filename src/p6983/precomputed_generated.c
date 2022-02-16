#include "precomputed.h"

// each basis entry is a triple of the form P,Q,P+Q
// this is initializing the point using the classical representation {0,...,p-1} for elements in GF(p).
// We don't use this representation for actual computation but rather the montgomery representation (the conversion is made in init_precomputations using the fp_enc function)
// hence the ***_uintbig[] defined below should not be used in any actual piece of code.

const uintbig torsion_basis_sum_uintbig[3][2][2] = 
{ { { { 0x1cc1dd07ce1c9728ULL, 0x3e56271c55e1e02dULL, 0x91234c94bf2fc8b4ULL, 0xbfd741ad4ff82c5ULL },
  { 0x1605550c9b3f7799ULL, 0xd0094ccd748f458fULL, 0x972eb02f996c4d44ULL, 0x9ba6bd450484c605ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xcd37fdc313b9cdcaULL, 0x49fb00e29b142d4cULL, 0x16145f29a2735828ULL, 0x7986f9439b4b0c06ULL },
  { 0x161e0df26c3089e0ULL, 0xf9e06c592d4530e0ULL, 0x9b2081e1f85c1b2bULL, 0x9b667d9f0ea73a3bULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xa067d1ad27a8a441ULL, 0xa3b125af13e2da13ULL, 0xc54dcf5175ab54f8ULL, 0x7f00877cae86f6a1ULL },
  { 0x6f431a115c5066f4ULL, 0xfa2743637ccb0ffbULL, 0x9d6485dd2eb247bcULL, 0x38b38c5018b35c88ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } };
const uintbig torsion_basis_twist_sum_uintbig[3][2][2] = 
{ { { { 0xa2239bf83707260ULL, 0xa66a63baabd6dfebULL, 0xaaf617625f002841ULL, 0x4f4647590096bd0eULL },
  { 0xcdc0c5ca01e8b19eULL, 0x1979cccf68632bbeULL, 0xab8f1004a7f162d3ULL, 0x3a4db90828fff9e2ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x65bca2520a8202e7ULL, 0x191847c660f9aa5fULL, 0xd9d1856fb01a5f86ULL, 0x226722619f303af9ULL },
  { 0x6021e1df7caa09a6ULL, 0x53a996525efa036ULL, 0x34ccefb8f676a49aULL, 0xa144013eb23a9f69ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x7a88134ef9965daULL, 0x3b5f316a42412dd5ULL, 0x89017bd16fe55711ULL, 0xfc8d3ec71b83e7ULL },
  { 0xc4ca190d607db409ULL, 0x87a7e3deac876d9ULL, 0x37cd6c8bcad68381ULL, 0x4b1256839f031450ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } };

const uintbig torsion_basis_ted_sum_uintbig[3][4][2] = 
{ { { { 0x24b2f025ac2d1ab5ULL, 0x87c918e363d31864ULL, 0x75408a88791fbeeeULL, 0x5b4d5a849f1f1b02ULL },
  { 0xefc093f21cde5b8ULL, 0xb1743b97582d8ea3ULL, 0xbe788e317133ab18ULL, 0x7f2567ec2403452aULL } },
  { { 0x33c6649cf0effc0dULL, 0x68f7f867903455cfULL, 0xa3c325ae750d5813ULL, 0x377d8783386cd097ULL },
  { 0x7a57b20d848e9785ULL, 0x459ba84180880335ULL, 0x43b6771380c35d5ULL, 0x842d5aa402b368c4ULL } },
  { { 0xd94c425a0fc3b6ULL, 0xb1dd5c501e1a18a9ULL, 0x1370b9ea94f63680ULL, 0x4d9482e03bd6cb98ULL },
  { 0x56b04e929f861f17ULL, 0x223bd230d21d9cdeULL, 0xa78fdc9194cb74d9ULL, 0x8665fe7b63a2493fULL } },
  { { 0x84a08bdefe0a92c7ULL, 0x21cfd92c9ffce28eULL, 0xeb316e1be75f04ffULL, 0x26853905c42aaec1ULL },
  { 0x46ed85ade50e5412ULL, 0x4d5866f1d6712946ULL, 0x169fe9b4630d3b34ULL, 0x9c21d15883bd38aeULL } } },
 { { { 0x9e301617df0dfac1ULL, 0x185fb5135388d97eULL, 0xcb6ff4501ec012e7ULL, 0x43974085a75cf179ULL },
  { 0xbbf1d33c5565700aULL, 0x33fdc6c66e303769ULL, 0xbd51d7c2354e9548ULL, 0x7bc1c4abcc9ee20ULL } },
  { { 0xc67ebfe7201f1060ULL, 0x8b5d92fe95f58d44ULL, 0x53fcb1f0ca84c3beULL, 0xa2e04d514130450aULL },
  { 0x29c6acdf4b2e973fULL, 0x10584376a6649eeeULL, 0x70352dc43b327a58ULL, 0x909d1774b5b9052bULL } },
  { { 0x15b52be17ada1f4ULL, 0xee232df907c06079ULL, 0x123ed4e692bcab2eULL, 0x3285d7583535380fULL },
  { 0xf9261ccffa07259dULL, 0x9c56131a5bbb0a4aULL, 0xbfeb0c2bd25b50feULL, 0x807b498b758f58a3ULL } },
  { { 0x301c416a68481cf7ULL, 0xd58c8a0a0b2e4016ULL, 0xe79a85a28f10cf4cULL, 0x99a127b2a3bb2c69ULL },
  { 0xa4c0692088513e19ULL, 0x18376c631e5d772fULL, 0x4668d912b1faf68bULL, 0x928b2cfe91102979ULL } } },
 { { { 0x69c951e30e4eb757ULL, 0xd43138667ed73092ULL, 0xb303d8f5d20e61bbULL, 0x70d6d6ed71c237d1ULL },
  { 0xbaa73a465895c504ULL, 0x6690adeb713f23daULL, 0x88710aed9db3d783ULL, 0x345bf64f8e8e5d38ULL } },
  { { 0xd6f8f4ab42d4dd58ULL, 0x598ccc5f6b0039abULL, 0xff480859c2d2223eULL, 0x709611b4880a436ULL },
  { 0x32afdf30046320c9ULL, 0xf8b9dff4dae6544bULL, 0x39929a51918b2fbeULL, 0x4891088e526c6a56ULL } },
  { { 0x284937027977e11dULL, 0x9cebdfa7d937bd21ULL, 0xd1cac28501cdbf99ULL, 0x4cc348cc295cac0eULL },
  { 0xd31701375c0b5e37ULL, 0xa2ab7430d4f1cdc2ULL, 0xec7347556dfa6281ULL, 0x7ffab38e2da7932cULL } },
  { { 0x5cdad020c62620f0ULL, 0x7784c71974770ab6ULL, 0x96cb1ebd22870f4ULL, 0x696f40fbf99751fbULL },
  { 0xbe2381cec456c38cULL, 0x112f234c9ab79e76ULL, 0xac6578fdd0f12ca3ULL, 0x763041806f1697ebULL } } } };
const uintbig torsion_basis_twist_ted_sum_uintbig[3][4][2] = 
{ { { { 0x2276da23d70d53ceULL, 0x5c0f40968b3f31f4ULL, 0x35eef4ff0e681818ULL, 0x46882b6415b614b8ULL },
  { 0xff211c36691292a2ULL, 0x5b3c78df3a44d6caULL, 0x2d2f12583bb1e64fULL, 0x91200138508ede7aULL } },
  { { 0xb0a714b43964a89aULL, 0x563508b80ba41996ULL, 0x130d7760d9aea045ULL, 0x6fc0f5af1d75ddc6ULL },
  { 0xe8da28eb8e818aULL, 0x137812d5a7e8b6d0ULL, 0x4513146546094d21ULL, 0x58bd7a30a568a9acULL } },
  { { 0x8e003d5d8855dd36ULL, 0x684edd5108d79b1fULL, 0x9bcb8f0fe0d5315eULL, 0x6dedbce1aeb012b7ULL },
  { 0xf5a8cdde2574d7c3ULL, 0x2c879f7266b30606ULL, 0x572ffa87333e82b7ULL, 0x177312c7828c4f28ULL } },
  { { 0xebfd634b27361f6bULL, 0xa5586eea1e0423e1ULL, 0xe60ec89a84da58a2ULL, 0x416a7e0a95a7934fULL },
  { 0xf7d913fdd6d24c48ULL, 0xcef2b40d5a8beb8bULL, 0x1b3026dd124d966cULL, 0x1a53e474a7243834ULL } } },
 { { { 0x67958c7de8bfbc9dULL, 0x57424edff684202aULL, 0x387c54d40fb11e57ULL, 0x661941c99d99edb2ULL },
  { 0xd613dabafcd56948ULL, 0x240c337727c10d87ULL, 0x241c0bdc6d31cc47ULL, 0x50a523f04103ca56ULL } },
  { { 0xde122788ab2ded8fULL, 0x423d511f33246bc0ULL, 0xbe509db3f55de5deULL, 0x1eead13f22e15a75ULL },
  { 0x347621aab8ddcd23ULL, 0x606107f7a1ed2d09ULL, 0x4b95b0b3117626b1ULL, 0x21ff6792c4b1edb8ULL } },
  { { 0x61b48a756db1190ULL, 0x1f49b932d9f21288ULL, 0xa8db94b8b803cebcULL, 0x17d6463954cbb4dbULL },
  { 0x8565a29e742eaa63ULL, 0xa425c5a46fc99ba1ULL, 0x9efe3288853b6714ULL, 0x9f02d901595d2ac2ULL } },
  { { 0x30592194810a9e05ULL, 0xc960a1124e483facULL, 0x91b53e6961263d27ULL, 0x8e40a0ecca13b0f3ULL },
  { 0x3ce0e5a1b409d59bULL, 0x1a635eef8b226c4bULL, 0xa526a4fa2aeb188ULL, 0x41acb1d2b1fb40a0ULL } } },
 { { { 0xa87adea70ef64aabULL, 0x23ed82e88ac475e7ULL, 0x796e91d81633c5e0ULL, 0x78fdf318faf07edaULL },
  { 0x11f1b70c5e912d25ULL, 0x18037f2d03268fcdULL, 0x3ecc1cf3257315aaULL, 0x402ff9eaf82b4bc4ULL } },
  { { 0x5a55d9b3d9243170ULL, 0xfe6ba7b3ab6b2639ULL, 0x61d07a1c7d7a8e5dULL, 0x63d5f3507a946a65ULL },
  { 0x6349d3b39330eb65ULL, 0x2d0048b28bddbacfULL, 0x195c315b0287000ULL, 0x407d91f6c18fe9f6ULL } },
  { { 0x718528e5233c3d88ULL, 0xde524d2f565cbf75ULL, 0x6c07351a154bb63ULL, 0x8ad917cfe351f416ULL },
  { 0x4b59e9b3e3118a2fULL, 0x8e3c87362c3794ffULL, 0x3cb7aafe81d4a898ULL, 0xa8a7c84282b9671ULL } },
  { { 0x773f660437779990ULL, 0x38d40ffb6c1c849bULL, 0xfe5d52ba4584d50fULL, 0x3a21b8347dab94d5ULL },
  { 0x280336b8094a7610ULL, 0x8cfe8a987159ef2dULL, 0x7740232858b14db8ULL, 0x2efaa89f07341b54ULL } } } };

const uintbig torsion_basis_uintbig[12][3][2][2] = {
{ { { { 0x377686e79f0d0c0dULL, 0x4ae08f3792fc41b0ULL, 0xbc5dc36bb42c917eULL, 0x5438bfac1e92dd2bULL },
  { 0x4bc98a63ebf89cbULL, 0x927716f466a2557bULL, 0xebc4eb0c7e6e2a7eULL, 0x8de9ba175f4aa85eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xec3e98d80ee121eaULL, 0xb14b9e1cb3ee5aabULL, 0x176eebe22af504daULL, 0x48b75baf81b4262dULL },
  { 0x5c093cb53c3cd565ULL, 0xcf50bcaeae2f5ddeULL, 0x2eed2b4f1d1e2d87ULL, 0x717972816d8a977aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x6a46b5f1fda28cd7ULL, 0x255e18ce56691c1bULL, 0xdd1bdd0cb87335a4ULL, 0x5742aceaf97961a0ULL },
  { 0xac001d404738b1f7ULL, 0xea6ad6c76c16b874ULL, 0xbd37a0ccb99d3bb3ULL, 0x982c490a247a526cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x38539c0f0aae8fb9ULL, 0x4bd50c77e562edc4ULL, 0x3827ac122e9a2dc0ULL, 0x4a5e6d175c138b01ULL },
  { 0xa7407767669eb171ULL, 0x5a0e509a336046e1ULL, 0x990f958ab8630f00ULL, 0x605db99bb9d6b08cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x7958d52fdee9f696ULL, 0xddce5e5d4894e89cULL, 0xc32348cb1e17beb0ULL, 0x7039c4c7fa6c5dcaULL },
  { 0xc21608ac67b626eULL, 0x5f5112715fca37bULL, 0x2c8fdcd7eb3c15f1ULL, 0x4542b26737fc8be0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x76cd25c2d35ea9ddULL, 0x6f5acb363fd5e5fdULL, 0x5621c3cb53c0a49dULL, 0x676d4c86c76705d4ULL },
  { 0x914696bac27321a1ULL, 0x9caafc78f520710fULL, 0xddbc3913b818dc8cULL, 0x603132e074d8264dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xe233a34074ee77e5ULL, 0x1a8fd51af25d5c55ULL, 0xa6d30a7f3d2429a1ULL, 0x63ed90094b783b63ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xdddf5d39b8d0cb05ULL, 0xd3d54056fec4969aULL, 0x74fcf8dca771b83ULL, 0x9f3c55d2e45bf455ULL },
  { 0x8e01b4437d7cc5c2ULL, 0xb062c795dd894417ULL, 0xbf53fb6167ac941eULL, 0x200b950dde32e7beULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x148ceb5a60cfca0bULL, 0x72f3d6f11d22eb25ULL, 0xc8d20902f67134fbULL, 0x4e4fd0914e927294ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x8eeecf7bae1e4df1ULL, 0xde81d3ca2785b400ULL, 0x6fb55b547481244bULL, 0x6ad45ffc421bc3ddULL },
  { 0x4c9476533ceebf22ULL, 0x2c3a016eadedbd51ULL, 0xc8c43a2fcaa8c326ULL, 0x82060ad85172566fULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x4e24160cb1d95410ULL, 0x9c69a7f48da43732ULL, 0x1ba4a7f505810671ULL, 0x5ada54c4f5932350ULL },
  { 0x5282e45349cad6e4ULL, 0x129957d87bbed128ULL, 0x6783bbeabd141732ULL, 0x11080e5d16e803f8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x5539afa11f542054ULL, 0xa479c68a835f9eccULL, 0xbabb8f5c9d9cfb7dULL, 0x57b0fa91cd5d1160ULL },
  { 0x4bbf5e3f45bb8f83ULL, 0xadd3d7ebb30c5091ULL, 0xb9dac5724d7fbadaULL, 0x6aed61b915b0ae0dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x38c05c751d2e4332ULL, 0x9d0af5ba69bdebf1ULL, 0xf50f267c25cf0c3eULL, 0x8555e3165c20a50cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x8396717048cecf4bULL, 0xb1a3de3f6d766d33ULL, 0x743e4c711a5d05cfULL, 0x97f660cc277423a9ULL },
  { 0xeed4b4264bd827a9ULL, 0x60c0ef76a48ba327ULL, 0xb5e76448a7cff11dULL, 0x543d5db75ad52254ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x198e3b7f8ea700f7ULL, 0xd458a2583144d3ULL, 0xb0a2d13522e2145cULL, 0xb9b92c0abcf6edfULL },
  { 0x15c1c22a6bcba86ULL, 0x23fc99f2c687e2a4ULL, 0x21270c897cd26d4fULL, 0x4e8086ff703b017eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x490b753124617a04ULL, 0x46d30cb6fe1dfd30ULL, 0x7dc0041a5352c03eULL, 0x7d556459ead76f6aULL },
  { 0x68b28454179b36e4ULL, 0xda6fd17e24b27c5dULL, 0x23bb466d7a0bb440ULL, 0x344ac98adf8c18cdULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xdcdbf23c0062d58dULL, 0x57298cac4ead3e47ULL, 0x9607917a6805b0c9ULL, 0x581078055202f2cbULL },
  { 0x97fbfcf70c5eab51ULL, 0x5d48b00158a50aeeULL, 0x4d8f3edd40daa47dULL, 0x508fd483d519b81aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xc524e8a99a9b79ffULL, 0x12df088a3a7e5830ULL, 0xa406b819f795bc76ULL, 0x3c42d1f765356825ULL },
  { 0xcb19c19ddb6def5fULL, 0xb2c984a535487ed1ULL, 0x3d43f77a46608d58ULL, 0xa2ad9b6ccec4f155ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xbfad2db4b63693d4ULL, 0x7019ebf1aac00e93ULL, 0x520809dfb1185341ULL, 0x78c0de5335c57780ULL },
  { 0xb54de4dfefcb0f53ULL, 0xd09ccb9258e8e6f6ULL, 0x648e0431f5d0cdb9ULL, 0x6eb74a4eb0629057ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xdbcba231ba38266fULL, 0xe32b57fe57d2880bULL, 0x58cd5e1269a41ad9ULL, 0x3e42d1b530b40807ULL },
  { 0xa276a0e9b973b1ddULL, 0xfd455d1cdfea8693ULL, 0xe432270d79646c63ULL, 0x915e42774cb6beecULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xb5cf76965c7edf76ULL, 0x8aa0db303e164911ULL, 0xcb82a993a3c9de9cULL, 0x3a0a244cad647517ULL },
  { 0x7c1de3c1cca3784fULL, 0xe02f8091eba63495ULL, 0x66f9e6406bce86b8ULL, 0x409198819339f9dfULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x7e9fb05b5a1d8530ULL, 0xffb3b33f2b1b55deULL, 0x13f5d43bf90108c7ULL, 0x744f93a009fd8b8cULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xa831865c9684202ULL, 0xb0225d8202d3ea7dULL, 0xd819d94235cd1509ULL, 0x6da99fb128262214ULL },
  { 0x7368f43006dc89c4ULL, 0xcf6da2bb4a028716ULL, 0x98c5d39e066dad70ULL, 0x70a89cf4c0255a86ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x5407604f3529ee1bULL, 0x755aa16a6fea1b43ULL, 0x771efebfef2351f5ULL, 0x8d54d17ddc38720ULL },
  { 0x997a3525e75aff1cULL, 0xf0d65e0f2c0280feULL, 0xb6bcc1ba0b1bd28ULL, 0xe12948bf488b9eaULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x23d5c7f3b4172d97ULL, 0x492caf67d2b78c1ULL, 0x69332164bc58b983ULL, 0x63694bf1a6260e5cULL },
  { 0xb94b6d25082eea71ULL, 0x13b10e69c16d1591ULL, 0x629a055b576ac65aULL, 0xd089fc02ff884e2ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x640b0392254a7980ULL, 0x24c9707f7ce17a2aULL, 0x35476059305d4594ULL, 0x584e06664f6c8af3ULL },
  { 0x2d821833064fb45dULL, 0xd96046512cafe15fULL, 0xf99c39c25ab41f2aULL, 0x758f07827285a206ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x1f9be0688e0169adULL, 0x539a7f185bdb712cULL, 0x5cf4a61ceefba8f4ULL, 0x5d870001c504e435ULL },
  { 0xe12dcbc246db113bULL, 0x3ab15cea0a118497ULL, 0x98ff5bf26d5dcd5dULL, 0x55fb53ba762fc7fcULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x88df2a0321181f6ULL, 0x816cb1e747f89d9eULL, 0x608945ceb977b16eULL, 0x2b01813c46b1a123ULL },
  { 0x95e8b1f9a89caacbULL, 0xd6c3d2e060199d27ULL, 0xa497a4489640dd92ULL, 0x3efdeeeaeb08137aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x54f9a0773d145759ULL, 0x80e02c3f0daea4e8ULL, 0x56f51e9c78a61cefULL, 0x7b817e6a91c562b6ULL },
  { 0x19e7fb6ac7bb0a0bULL, 0xed5e93983fa372f3ULL, 0xc727faf71231f778ULL, 0x44fe68dc304033bbULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xe1d55930ed884fa5ULL, 0xd45b500a9bb6ce60ULL, 0x787fd3ff1976d92eULL, 0x5d20bedc3dea1c37ULL },
  { 0xc4e016fba73b1c33ULL, 0xec26d9c029894281ULL, 0xab623ee7a55f71f9ULL, 0x9f504c267080a7e1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x128a6dae02b47c36ULL, 0x9b943346c012ad85ULL, 0xfc170298f586f766ULL, 0xe9dbdbfea551c26ULL },
  { 0x8aa26ea650ec4470ULL, 0x24b80c87610e09f7ULL, 0xc504c01c861161ccULL, 0x1c4643fa12f5dbd1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x79fcecfbe2563e81ULL, 0x120e738dc69044f1ULL, 0xb75fbfc1c3c74eadULL, 0x28ffd918d5ceb847ULL },
  { 0xbdbe9a223fa60bb0ULL, 0x7381e26ce62a1e47ULL, 0x6ebc1ec9d0e00d35ULL, 0x2998058b47670774ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xfb656ae539e9917dULL, 0x9386bad0b845faa7ULL, 0x7c13bb86bae265f2ULL, 0x709df2f36dcab31cULL },
  { 0xaf5d91f3a3ccd7eULL, 0xf09e95a5ef22d52fULL, 0xc8070b85e6701ecfULL, 0x97aabb42ac269de6ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x5a8dba2e98d8fd29ULL, 0x61123ae4300b22dcULL, 0x360a334fc3006fbeULL, 0x4fb03ec50847198fULL },
  { 0x5206d577dcec67edULL, 0xd831183da63cc4a2ULL, 0x625f1eba6572f1edULL, 0x72b57179a1a498aeULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xc5d1042677c4108aULL, 0xf5c4dd91c6cc64c1ULL, 0x5f3007aadd6909a9ULL, 0x8e232ac0c82f9911ULL },
  { 0xcf680e12db30c895ULL, 0xcb909804ae4feefcULL, 0x535a33d64e8ac14aULL, 0x6088be1f73ab0e7eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x81a097e3abdaa7ddULL, 0xf7ed6819d59430f7ULL, 0x716c55be0e7ba49cULL, 0x5d123c9a75cc095dULL },
  { 0xa4a7836d0690037bULL, 0x928497930a8db144ULL, 0xcea0ec345efa9f33ULL, 0x16cd90676dc4317ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
};

const uintbig torsion_basis_twist_uintbig[19][3][2][2] = {
{ { { { 0xb59c81a7b8a3d358ULL, 0x2a83d8ef31d7d15dULL, 0x952499ec348c1803ULL, 0x55035018ec74add9ULL },
  { 0xab5ad67c32f4c320ULL, 0x5770044232c8faa9ULL, 0x8ce84929a0b20c21ULL, 0x4f54db693fef036aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x95307bd24304d4a9ULL, 0xdca7f4a9da0dc12eULL, 0xbf20f59d900f6a75ULL, 0x745f5c94e859f178ULL },
  { 0xee155aec52bf3d2fULL, 0x547fc6960c4f3027ULL, 0xa38c94c38bad409eULL, 0x7ffff5d66298bebeULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x4dc9b4cbd127b885ULL, 0x902724c66d4a4adaULL, 0xca40df39b6146078ULL, 0x60e92e575f2881eeULL },
  { 0x10c42d0360a6ddfeULL, 0x6a602073a1bd7bffULL, 0xa9dee15c2e104d93ULL, 0x88df448a8a5d3e7aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xe028659524cb3b13ULL, 0x5e2c461e906047f2ULL, 0xdb2b4520e1e782c2ULL, 0x8e83b8ea543e16c0ULL },
  { 0x4c7dd6ff621aafcfULL, 0xfc5908b702a90cc9ULL, 0x4e5995a4fb0fe5d1ULL, 0xa1bcb83d3373d6a1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x55579f20a9f9b259ULL, 0x4e15d88f3bc4c9b8ULL, 0xfd2b9fa7141173fULL, 0x65952b07a57f0fcdULL },
  { 0xf3a168c810882cd1ULL, 0x70f9b4aab3d0d5c0ULL, 0x7d7e60e2284dcd7eULL, 0x32b6c797ce6bda3ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x61da0ee323542de6ULL, 0x36d8bcbf9246c98eULL, 0xcaf92d2667480b48ULL, 0x67243e6aa69a0bbaULL },
  { 0x4019a76431f4ffb3ULL, 0xef0c7a29a3f55161ULL, 0xc18f0b9d4d727119ULL, 0x9aba8ed043916691ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x7a53a347e0dce5efULL, 0x8ee0d92d626508d4ULL, 0x682fb420eb707a81ULL, 0x11d0787a9bffd0e8ULL },
  { 0x7f6697c455f4984fULL, 0xbc79e024aaf62fa6ULL, 0xdfb4ae4afbad05adULL, 0x7b60932cc8b65ca1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xcfd7f8d48c1bddb1ULL, 0x592d7b8a3e15d1f0ULL, 0xfd7b7d9fa35ad4b6ULL, 0x3201318e20c5e20eULL },
  { 0x4f725408e8a557e8ULL, 0xc612b1625fec16b1ULL, 0xc0b7ae30cf3c8f7aULL, 0x84104022a4e576d9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x125734c3ca7ebccfULL, 0xc667df7d491eee5ULL, 0xb0be76ee05da5a48ULL, 0x66859006e203850bULL },
  { 0x921dc809f3d46689ULL, 0xd513cb7539696ab3ULL, 0x49811a1745792dd2ULL, 0x8e105947081791a2ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xb6d004166cb29998ULL, 0x2cd20b85e9a18802ULL, 0x121cb6a1d7589cd6ULL, 0x4dbfb4e1278e76ffULL },
  { 0x3b6f9809a094da47ULL, 0x7f0b26a360c877b4ULL, 0xeb45d2bbad8eaca3ULL, 0x817d03ed9d1193a8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xfaaaa3ea15003215ULL, 0x130298bcfff57224ULL, 0xb46c0b067bc75b3aULL, 0x9f3bbf5a11bb0d2ULL },
  { 0x6873810c171b4df1ULL, 0xcd61c3b02244d7b6ULL, 0xbec5b2e4cf1fc72bULL, 0x39cc220d028778a9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xe25df56aabd84e35ULL, 0xdbb84bff7741aee9ULL, 0xffb7867eeb12f5b5ULL, 0x569ea08afec95baaULL },
  { 0xb0a816ea9b7e7342ULL, 0x25ea73fa98055eeeULL, 0x78fc7f8dbe401c84ULL, 0x7f2599a7ee0d94b8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xb2b8548ac6663ebULL, 0xadd198843042e5ecULL, 0x3a5d4ba5a5a7da73ULL, 0x8ab1a909ea3f8b72ULL },
  { 0xc6bff853a39be95aULL, 0x493b913c1cacbf57ULL, 0xa1fa4873fc975556ULL, 0x4f6d6ee6da2e0b4cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xd983f284fb94ef2fULL, 0xbea70ad3078f1b52ULL, 0x23672563b4f60b18ULL, 0x72d977e89db8a5abULL },
  { 0x4ade5e22d58607eULL, 0xc3258514a0bd66b3ULL, 0xd6a33429f063db9dULL, 0x59d942cbbfc2f103ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x44652041a86c35a8ULL, 0x4a4e4ccb38690cefULL, 0x4e30b76a70c18b0aULL, 0x1f5578447686f256ULL },
  { 0x63315d95795b5b2cULL, 0xbd92f440db1111d7ULL, 0x5592a6922a18212fULL, 0x9ef275353da95396ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x4a95d01c49d72f22ULL, 0xcecbbf5ee74872cbULL, 0x7a13e7ad86597925ULL, 0x4d6bef7b97b01b23ULL },
  { 0x8ad8433fcaac745eULL, 0xe639d86f216e7501ULL, 0xddec7c028fd40228ULL, 0x71c0a310fe33611ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xeec520c8bfa11e4eULL, 0x2f1620d8cfca0b6fULL, 0xc0bd886540f7ccd4ULL, 0x4f54f2c13705aefbULL },
  { 0x4ae5d077f6080932ULL, 0xece3ca90bf9c26cULL, 0x759f1b5570a2d7c2ULL, 0x4f435fc103c6cf5fULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xf09ac65b46933214ULL, 0xaabedbfd228659e7ULL, 0x768405f06312afb8ULL, 0x74edbe440579226fULL },
  { 0x7227d8c188c49e02ULL, 0x8cb8919157b1cb6dULL, 0x6d322b66ee097d89ULL, 0x7050ff38a6f64933ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x3731c14e82748a5ULL, 0xe47b3cf46b3a37c8ULL, 0x3a3637d5caa77306ULL, 0x80c86aa0dc020e7aULL },
  { 0x7caa53324dab19a1ULL, 0x8e40217e156e68f4ULL, 0xdd2296c33cc324abULL, 0x2ab00d4ddc913194ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xc1089e92ad529849ULL, 0x84ef3eb79e47d413ULL, 0x744c4cf2fe45218fULL, 0xb2a3a8747e90ef6ULL },
  { 0x8c0f6a451512667cULL, 0x782b925b62ebda82ULL, 0x3fcaee9654be17afULL, 0xf6892bb6b861d9dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xe062178b3ec72659ULL, 0xc3daedde78cd7727ULL, 0x76cdb4d81fb7be75ULL, 0x45a300f8612bfc3cULL },
  { 0x12b8d2bd951275dbULL, 0x64b59e329247177eULL, 0x87fd12d41cfa8597ULL, 0x4f3e28a6d39cd538ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xa68a68e353f4c98fULL, 0xb1411464588e021dULL, 0x2b3549a5d4a54b2dULL, 0x4e318bc4aef678faULL },
  { 0xb584f4013dc90d54ULL, 0xa52e09092e7f4283ULL, 0xdb1248a5b7e3702cULL, 0x9d1f74bbee122fdbULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x4a4a1892997b0e11ULL, 0x136ece1e4df31fe6ULL, 0xd98dda3cf8e26169ULL, 0x1e3de9bd3f48f9d4ULL },
  { 0xfaf9c1a8766bc830ULL, 0xe48396c48d95f54fULL, 0x875df23c2d0d70d2ULL, 0x35eb430dfd8667aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x184bcd95857cb5f5ULL, 0xcf644bacb66c348bULL, 0x29db634463d4b393ULL, 0x4cd795989873b526ULL },
  { 0xe2294d95b75ffe97ULL, 0x153f2136fa66fdfbULL, 0xfc3e86b1bdf7cecdULL, 0x51364536025ba3c1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x9882ad952335f711ULL, 0x3b3734c8c7c895a5ULL, 0x6ed4322346114beeULL, 0x569857c8425438a4ULL },
  { 0x12c2f1ade760207ULL, 0xb6fd79a1a6b49c02ULL, 0x80c55bd6cf9783e3ULL, 0x40326f0935cff789ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xe340d4000b516c57ULL, 0xe4fee8fca896ecd7ULL, 0x2a6fbdc2dd6ec78eULL, 0x127965cad1eb3dc1ULL },
  { 0x92e2549ec65dc58bULL, 0x617ceab18a0fc5bdULL, 0xd3a8993d750ab8c0ULL, 0x23600a97a0062e30ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x188ec1fa78e69fe8ULL, 0x1b5e48d0c6fef68dULL, 0xc1c3e584bde91f1bULL, 0x61866f149da402b5ULL },
  { 0x810018b59b4406f8ULL, 0xb9e4f8736cdfe949ULL, 0x73ac19b61543fedeULL, 0x53abd49fea324922ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x147a7c850c8d9f26ULL, 0x473333d36c527972ULL, 0x482f74da0112f3b2ULL, 0x860a612e3b66d34fULL },
  { 0x9c62eea6d8010751ULL, 0xa93cda28f610577eULL, 0xe5cded84db6ebca8ULL, 0xc54eeee90d3f366ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x803183bf1893f3daULL, 0x3ef68f818d92be36ULL, 0x2ed610909b789432ULL, 0x7f19757c5eff3089ULL },
  { 0x804da9e045b7d40bULL, 0x576aaefc9c830a54ULL, 0x9cb3d6fc2c582cc5ULL, 0x68b80fa7e9af8d35ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x91a29ea6949881e1ULL, 0x9255908028c265e3ULL, 0x459e67f1b388427dULL, 0x2e741db38bd1e165ULL },
  { 0x9e466f7bb6b014feULL, 0x8e4d38e1b7632e24ULL, 0xf3eda866e94983d1ULL, 0x8d167dce27e23d35ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x1125d7ca667e46bfULL, 0x9fe1caf1e1128637ULL, 0xc66c971a9552aceeULL, 0x6070c0cf91093c3aULL },
  { 0x21a4ce606cbfedc9ULL, 0xca772f072e7a4479ULL, 0xd8e88241279edc7eULL, 0x29ad44049c36022dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xdf8ed6495899b2daULL, 0x4cd5c314591de9d5ULL, 0xd1b7ecfb3c635957ULL, 0x61292858b2c3ed15ULL },
  { 0x5e0261dd6bb8256dULL, 0x26883dd5cde63e90ULL, 0xb950f85ef6c6bc21ULL, 0x62e9575d3a9e453aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x4982991d4ac66502ULL, 0xac8261fb03d85513ULL, 0xbc2cde25196c17bbULL, 0x507a5b7cfcf0fc69ULL },
  { 0xf8d12c082243c356ULL, 0x30dbfa0878f33897ULL, 0x86b8fbf5c5f7e861ULL, 0x7175265842c153c9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x2a0dd97f24d780a5ULL, 0x4fc49449f4652e56ULL, 0x70bbb08cdc2330fcULL, 0x74235cbf9cf4d528ULL },
  { 0x88ce2e74fee6fa0dULL, 0xe3fa1b21a7c4b4f5ULL, 0x591dc58f1e3c9945ULL, 0x99b5dfc24a23593cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xf33de0a7499f80b5ULL, 0x84d6c16633ef6d84ULL, 0xfcd7420377e6ce52ULL, 0x62da260ddfe28d7cULL },
  { 0x75ed5f1ad141dc47ULL, 0x4402869b6f431af4ULL, 0xbc81b1ff9efc016cULL, 0xa6bfa82dd9a968ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xec35ae3679be6080ULL, 0x40cd39dc2ac9f225ULL, 0xb92f09f72a7a6d1aULL, 0x44dbdd77af5f92ceULL },
  { 0x7c0cfcf3d95d9daeULL, 0xf7b7caa525bd57f0ULL, 0xc268513808e1115eULL, 0xebba2e4b1018710ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xa81e55a13113efbfULL, 0xab7bfc54da6e7084ULL, 0xa4e7986756236ce8ULL, 0x2ad025d1b41d8d2cULL },
  { 0x652073069348161ULL, 0x7ac5451d5e60118dULL, 0x49dd8f50c37ad27bULL, 0x7fb14f74a4078843ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xcea562251fe908c6ULL, 0x3e88d6194222c1fdULL, 0x19da21fafba78e42ULL, 0x91fa17c1c18cee7ULL },
  { 0x45761dd11a2fb35aULL, 0xbc1d2d6faa3c1b5eULL, 0x93f2f2c052694458ULL, 0x9f6a805d7f0964a7ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x81a0a63c15272002ULL, 0xe684e2683cf05876ULL, 0x14822a9e6597e26eULL, 0x49b9876c1c74d071ULL },
  { 0x7387f0277acd7a1aULL, 0x6b07473f09c0fa9cULL, 0x6ca746ba6c954ad2ULL, 0x7fa102979239a948ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xf1a9847e8405503eULL, 0x561254fd97a8334ULL, 0x666b2d027b85891fULL, 0x1d2b349c754ba9dbULL },
  { 0xbf0677c04b7e7277ULL, 0xa2e15cf898ca10d7ULL, 0x38d7389c24ebd878ULL, 0x2f0f4bc0605d39e7ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x2f26d00a624c8e0bULL, 0x6eb836f946ba2423ULL, 0xf140da61617ed478ULL, 0x66f39894185427a7ULL },
  { 0xacce96e17907489cULL, 0x822eea9390856a4cULL, 0xbdb8e9f3f678ff30ULL, 0x8a846c656b19876dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xbf288b9f1a5dea0eULL, 0x14c921cd9c2b564ULL, 0x9180a4ac74545447ULL, 0x357c4095694d6721ULL },
  { 0x8d9e757f6726e829ULL, 0x1218bc5e7330b18eULL, 0x387bf0e76562530eULL, 0x910d528195aaeba8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x7e1301d786fb8feULL, 0x3bdbfd51e2922ad3ULL, 0x1cedd51a7d896348ULL, 0x737e19afb48d33d1ULL },
  { 0x3a20c8e622de9862ULL, 0x4f3188d5619adff9ULL, 0x316740d85d9bc66eULL, 0x4b4d5125ce864825ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x7741a0dd7d8fcd07ULL, 0xdb14069f0b8c49f0ULL, 0xbd91113d3f8e8bfULL, 0x49512919053d31a0ULL },
  { 0xc55f6d9d08542fdeULL, 0x43e78da33af24048ULL, 0x64ada33c3a457433ULL, 0x2864fdf466bf85ebULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x390b55bea575c02fULL, 0xc622ddb037d34980ULL, 0x5c0c409feb81dfc2ULL, 0x470013894b6cbf19ULL },
  { 0x6831f11e34554d85ULL, 0xfbc60214cf6b9e13ULL, 0x59fbdb3b956ef2bfULL, 0x3f34aeb9de1471dbULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xe1f7b4938cc3b0f0ULL, 0x9986bfc2e9bd4bdbULL, 0x34e39d17172231e5ULL, 0x1081487f3fa6b2eeULL },
  { 0x8f4999a5a64ab698ULL, 0x6b14a0bf2baf4919ULL, 0x23eb54468e0d9d13ULL, 0x2503216d84ac9e47ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x922dfb8c4e75d94eULL, 0x65b0d5d558155909ULL, 0xb151d854fd515a94ULL, 0x55e37d0bbd773405ULL },
  { 0xcf0c56ed6933577fULL, 0xf4650912c6fd0857ULL, 0xdbd700765d6b3688ULL, 0x9588d4b344919101ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x80be02d3328e89b5ULL, 0x66751702201d5330ULL, 0x504564a0175c056aULL, 0x48f1c9896794c4b2ULL },
  { 0xf76c84bc448b316eULL, 0x22755018b3be96ebULL, 0x9b97097d000ee9bdULL, 0x61a62a42218cb0b1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xd4bef8a536a7a105ULL, 0xe84890d7829163c6ULL, 0xf1a12f212cd9ad6bULL, 0x295a19e656cb229eULL },
  { 0x85e233086b82142ULL, 0x1cb9ddb26137212ULL, 0xdb978db55410ea09ULL, 0x5e7aec4fc2eff6f2ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xa032dfa8fce54fcdULL, 0xee59218a08c15722ULL, 0x9e2163b8cdbf5df3ULL, 0x7db4dab60720829ULL },
  { 0x944f5971423fd22fULL, 0xb501350c4fa2b5e2ULL, 0x490f32ac007018e1ULL, 0x6238a22bed24577bULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x52720740e3dbfac7ULL, 0x475548a097bb1d2eULL, 0x5a8c42c771c0bacbULL, 0x90a88ab55aa274fULL },
  { 0x9ea749cd00759157ULL, 0x4699fb74f760464eULL, 0xcfda6beeb40e5f83ULL, 0x97ac8060abbdf67dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x334551c103ee35baULL, 0x609eaa7e49e6e3e7ULL, 0x935338bd957befabULL, 0x611cb31534d6db28ULL },
  { 0xd5d9b69c69cd2c14ULL, 0x8226d57bb82ed97cULL, 0x3d42f864ebdecbc6ULL, 0x1218b2a4774ba78dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x586a49ed21d0ad69ULL, 0x5b4a458012a56f38ULL, 0xddb021d58a258ebbULL, 0x5fd98bf2a5f2826eULL },
  { 0xdc90b0c09583f8b7ULL, 0xd35e6c9d89490378ULL, 0xc542d6aa3340e06cULL, 0x7f8bcb9bed905437ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x74a992f37022ef18ULL, 0x64baa0c0fb8f8406ULL, 0xc61d34ad879cc517ULL, 0x4c8c0ca720244419ULL },
  { 0x853c154177aad1caULL, 0x108f11d6ea97e127ULL, 0x21afdb3fe89dd744ULL, 0x1033623d1d09ad51ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xa3887bb6a1401a0aULL, 0xe284652b88ad5ac2ULL, 0x8449b6e4cd7dfbb4ULL, 0x1f685f2e71885f5cULL },
  { 0x9885d34961d15272ULL, 0x93373c75d38fc5bdULL, 0xb7d128e629253d88ULL, 0x6ce2682d54439eddULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x3f354d4f9fbd4d4eULL, 0x23ffefb8f91add98ULL, 0x83e96d272f09aea0ULL, 0x60c9e8a51e89777cULL },
  { 0x983776706209849cULL, 0xf4be42e483cd611dULL, 0x3154ec6c5ecd55f6ULL, 0x4a63bde947694977ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xc2a595ac5f6538a9ULL, 0xb9fa69590dfe6fd6ULL, 0x4fb44d2ca2d9e95eULL, 0x92c9a77db6eb4cffULL },
  { 0x150ea49e0b65c005ULL, 0x877c22888df8ea80ULL, 0xa5d94de02289e8f0ULL, 0x740e4584bda80bd7ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
};

const uintbig torsion_basis_two_uintbig[3][2][2] = 
{ { { { 0xf1fe96cc4eaf0775ULL, 0x14057ead15b9f0d8ULL, 0xa508db1478e635a8ULL, 0x9ee509352cbf2129ULL },
  { 0x5f78295f053ecdc2ULL, 0x659fdd3c830ea621ULL, 0x6141a8f51c191377ULL, 0x8e47b35c9916244fULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x319c1e00de60157fULL, 0x841bddb428cf525fULL, 0xd7918cf202e2a0bULL, 0x6e4ab618eaddbf74ULL },
  { 0x4e08e27e7c3e665cULL, 0x37b564fd8333a5f4ULL, 0x228629f5691a695fULL, 0x9e390be952811cbdULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x9afc499adff1893aULL, 0x1f77e8c5d3bb3d80ULL, 0xa07c31d22692df67ULL, 0x63bb11940d111de7ULL },
  { 0x2145ea172972dd3cULL, 0x7e8e2984918f8763ULL, 0x6e32034a9c85ba94ULL, 0x8a39086440864b1eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } };


proj torsion_basis[12][3];
proj torsion_basis_sum[3];
point torsion_basis_ted_sum[3];
proj torsion_basis_twist[19][3];
proj torsion_basis_twist_sum[3];
point torsion_basis_twist_ted_sum[3];
proj torsion_basis_two[3];


void init_precomputations_generated() {
	global_setup.action_2 = malloc(12*sizeof(GEN));
	global_setup.action_3 = malloc(12*sizeof(GEN));
	global_setup.action_4 = malloc(12*sizeof(GEN));
	global_setup.action_twist_2 = malloc(19*sizeof(GEN));
	global_setup.action_twist_3 = malloc(19*sizeof(GEN));
	global_setup.action_twist_4 = malloc(19*sizeof(GEN));

	global_setup.action_2[0] = mkmat2(mkcol2(stoi(160210603496426ULL),stoi(365142378111504ULL)),mkcol2(stoi(455413447091662ULL),stoi(316626554706699ULL)));
	global_setup.action_3[0] = mkmat2(mkcol2(stoi(387455510717966ULL),stoi(7663385861227ULL)),mkcol2(stoi(73070025423905ULL),stoi(89381647485160ULL)));
	global_setup.action_4[0] = mkmat2(mkcol2(stoi(32321598889511ULL),stoi(348965632770967ULL)),mkcol2(stoi(339764193407837ULL),stoi(444515559313614ULL)));
	global_setup.action_2[1] = mkmat2(mkcol2(stoi(37ULL),stoi(22ULL)),mkcol2(stoi(9ULL),stoi(12ULL)));
	global_setup.action_3[1] = mkmat2(mkcol2(stoi(8ULL),stoi(41ULL)),mkcol2(stoi(7ULL),stoi(42ULL)));
	global_setup.action_4[1] = mkmat2(mkcol2(stoi(9ULL),stoi(40ULL)),mkcol2(stoi(9ULL),stoi(40ULL)));
	global_setup.action_2[2] = mkmat2(mkcol2(stoi(4ULL),stoi(5ULL)),mkcol2(stoi(1ULL),stoi(7ULL)));
	global_setup.action_3[2] = mkmat2(mkcol2(stoi(4ULL),stoi(3ULL)),mkcol2(stoi(7ULL),stoi(8ULL)));
	global_setup.action_4[2] = mkmat2(mkcol2(stoi(7ULL),stoi(8ULL)),mkcol2(stoi(9ULL),stoi(4ULL)));
	global_setup.action_2[3] = mkmat2(mkcol2(stoi(16ULL),stoi(13ULL)),mkcol2(stoi(16ULL),stoi(15ULL)));
	global_setup.action_3[3] = mkmat2(mkcol2(stoi(15ULL),stoi(7ULL)),mkcol2(stoi(1ULL),stoi(17ULL)));
	global_setup.action_4[3] = mkmat2(mkcol2(stoi(5ULL),stoi(23ULL)),mkcol2(stoi(7ULL),stoi(26ULL)));
	global_setup.action_2[4] = mkmat2(mkcol2(stoi(79ULL),stoi(5ULL)),mkcol2(stoi(63ULL),stoi(4ULL)));
	global_setup.action_3[4] = mkmat2(mkcol2(stoi(1ULL),stoi(0ULL)),mkcol2(stoi(34ULL),stoi(0ULL)));
	global_setup.action_4[4] = mkmat2(mkcol2(stoi(0ULL),stoi(0ULL)),mkcol2(stoi(33ULL),stoi(0ULL)));
	global_setup.action_2[5] = mkmat2(mkcol2(stoi(1ULL),stoi(105ULL)),mkcol2(stoi(1ULL),stoi(106ULL)));
	global_setup.action_3[5] = mkmat2(mkcol2(stoi(41ULL),stoi(58ULL)),mkcol2(stoi(16ULL),stoi(67ULL)));
	global_setup.action_4[5] = mkmat2(mkcol2(stoi(9ULL),stoi(31ULL)),mkcol2(stoi(25ULL),stoi(98ULL)));
	global_setup.action_2[6] = mkmat2(mkcol2(stoi(92ULL),stoi(68ULL)),mkcol2(stoi(79ULL),stoi(45ULL)));
	global_setup.action_3[6] = mkmat2(mkcol2(stoi(38ULL),stoi(95ULL)),mkcol2(stoi(40ULL),stoi(100ULL)));
	global_setup.action_4[6] = mkmat2(mkcol2(stoi(51ULL),stoi(59ULL)),mkcol2(stoi(7ULL),stoi(86ULL)));
	global_setup.action_2[7] = mkmat2(mkcol2(stoi(304ULL),stoi(396ULL)),mkcol2(stoi(584ULL),stoi(447ULL)));
	global_setup.action_3[7] = mkmat2(mkcol2(stoi(224ULL),stoi(553ULL)),mkcol2(stoi(404ULL),stoi(528ULL)));
	global_setup.action_4[7] = mkmat2(mkcol2(stoi(527ULL),stoi(198ULL)),mkcol2(stoi(490ULL),stoi(224ULL)));
	global_setup.action_2[8] = mkmat2(mkcol2(stoi(21ULL),stoi(161ULL)),mkcol2(stoi(326ULL),stoi(806ULL)));
	global_setup.action_3[8] = mkmat2(mkcol2(stoi(523ULL),stoi(153ULL)),mkcol2(stoi(648ULL),stoi(305ULL)));
	global_setup.action_4[8] = mkmat2(mkcol2(stoi(358ULL),stoi(217ULL)),mkcol2(stoi(587ULL),stoi(469ULL)));
	global_setup.action_2[9] = mkmat2(mkcol2(stoi(3174ULL),stoi(472ULL)),mkcol2(stoi(1983ULL),stoi(517ULL)));
	global_setup.action_3[9] = mkmat2(mkcol2(stoi(1035ULL),stoi(1894ULL)),mkcol2(stoi(651ULL),stoi(2657ULL)));
	global_setup.action_4[9] = mkmat2(mkcol2(stoi(1019ULL),stoi(1772ULL)),mkcol2(stoi(895ULL),stoi(2672ULL)));
	global_setup.action_2[10] = mkmat2(mkcol2(stoi(919ULL),stoi(3471ULL)),mkcol2(stoi(3492ULL),stoi(3100ULL)));
	global_setup.action_3[10] = mkmat2(mkcol2(stoi(2460ULL),stoi(128ULL)),mkcol2(stoi(2853ULL),stoi(1560ULL)));
	global_setup.action_4[10] = mkmat2(mkcol2(stoi(2009ULL),stoi(2248ULL)),mkcol2(stoi(198ULL),stoi(2010ULL)));
	global_setup.action_2[11] = mkmat2(mkcol2(stoi(1686ULL),stoi(901ULL)),mkcol2(stoi(2030ULL),stoi(5297ULL)));
	global_setup.action_3[11] = mkmat2(mkcol2(stoi(4612ULL),stoi(4301ULL)),mkcol2(stoi(6695ULL),stoi(2372ULL)));
	global_setup.action_4[11] = mkmat2(mkcol2(stoi(2636ULL),stoi(3506ULL)),mkcol2(stoi(1898ULL),stoi(4347ULL)));
	global_setup.action_twist_2[0] = mkmat2(mkcol2(strtoi("5082003025448880579792896"),strtoi("9674586177364921966854202")),mkcol2(strtoi("9606035991295424061744088"),strtoi("14301242642231139317003827")));
	global_setup.action_twist_3[0] = mkmat2(mkcol2(strtoi("10933195370780868530072935"),strtoi("111981700708158776792864")),mkcol2(strtoi("1859310608868224911066088"),strtoi("8450050296899151366723789")));
	global_setup.action_twist_4[0] = mkmat2(mkcol2(strtoi("9640950267738160709128900"),strtoi("8145235975176814476682807")),mkcol2(strtoi("6522448623020218175251827"),strtoi("9742295399941859187667823")));
	global_setup.action_twist_2[1] = mkmat2(mkcol2(stoi(25ULL),stoi(12ULL)),mkcol2(stoi(41ULL),stoi(18ULL)));
	global_setup.action_twist_3[1] = mkmat2(mkcol2(stoi(40ULL),stoi(5ULL)),mkcol2(stoi(19ULL),stoi(4ULL)));
	global_setup.action_twist_4[1] = mkmat2(mkcol2(stoi(24ULL),stoi(1ULL)),mkcol2(stoi(4ULL),stoi(19ULL)));
	global_setup.action_twist_2[2] = mkmat2(mkcol2(stoi(637ULL),stoi(5439ULL)),mkcol2(stoi(7671ULL),stoi(9972ULL)));
	global_setup.action_twist_3[2] = mkmat2(mkcol2(stoi(156ULL),stoi(2738ULL)),mkcol2(stoi(8564ULL),stoi(10454ULL)));
	global_setup.action_twist_4[2] = mkmat2(mkcol2(stoi(9977ULL),stoi(9905ULL)),mkcol2(stoi(6226ULL),stoi(632ULL)));
	global_setup.action_twist_2[3] = mkmat2(mkcol2(stoi(38ULL),stoi(58ULL)),mkcol2(stoi(101ULL),stoi(71ULL)));
	global_setup.action_twist_3[3] = mkmat2(mkcol2(stoi(98ULL),stoi(93ULL)),mkcol2(stoi(73ULL),stoi(12ULL)));
	global_setup.action_twist_4[3] = mkmat2(mkcol2(stoi(1ULL),stoi(88ULL)),mkcol2(stoi(39ULL),stoi(108ULL)));
	global_setup.action_twist_2[4] = mkmat2(mkcol2(stoi(48ULL),stoi(71ULL)),mkcol2(stoi(32ULL),stoi(151ULL)));
	global_setup.action_twist_3[4] = mkmat2(mkcol2(stoi(192ULL),stoi(11ULL)),mkcol2(stoi(22ULL),stoi(8ULL)));
	global_setup.action_twist_4[4] = mkmat2(mkcol2(stoi(32ULL),stoi(101ULL)),mkcol2(stoi(113ULL),stoi(167ULL)));
	global_setup.action_twist_2[5] = mkmat2(mkcol2(stoi(135ULL),stoi(91ULL)),mkcol2(stoi(124ULL),stoi(92ULL)));
	global_setup.action_twist_3[5] = mkmat2(mkcol2(stoi(169ULL),stoi(80ULL)),mkcol2(stoi(92ULL),stoi(59ULL)));
	global_setup.action_twist_4[5] = mkmat2(mkcol2(stoi(88ULL),stoi(52ULL)),mkcol2(stoi(137ULL),stoi(139ULL)));
	global_setup.action_twist_2[6] = mkmat2(mkcol2(stoi(245ULL),stoi(92ULL)),mkcol2(stoi(140ULL),stoi(174ULL)));
	global_setup.action_twist_3[6] = mkmat2(mkcol2(stoi(97ULL),stoi(219ULL)),mkcol2(stoi(387ULL),stoi(323ULL)));
	global_setup.action_twist_4[6] = mkmat2(mkcol2(stoi(290ULL),stoi(409ULL)),mkcol2(stoi(51ULL),stoi(129ULL)));
	global_setup.action_twist_2[7] = mkmat2(mkcol2(stoi(12ULL),stoi(259ULL)),mkcol2(stoi(62ULL),stoi(479ULL)));
	global_setup.action_twist_3[7] = mkmat2(mkcol2(stoi(84ULL),stoi(338ULL)),mkcol2(stoi(336ULL),stoi(408ULL)));
	global_setup.action_twist_4[7] = mkmat2(mkcol2(stoi(143ULL),stoi(235ULL)),mkcol2(stoi(194ULL),stoi(348ULL)));
	global_setup.action_twist_2[8] = mkmat2(mkcol2(stoi(228ULL),stoi(563ULL)),mkcol2(stoi(224ULL),stoi(341ULL)));
	global_setup.action_twist_3[8] = mkmat2(mkcol2(stoi(174ULL),stoi(413ULL)),mkcol2(stoi(534ULL),stoi(396ULL)));
	global_setup.action_twist_4[8] = mkmat2(mkcol2(stoi(52ULL),stoi(179ULL)),mkcol2(stoi(298ULL),stoi(517ULL)));
	global_setup.action_twist_2[9] = mkmat2(mkcol2(stoi(324ULL),stoi(513ULL)),mkcol2(stoi(18ULL),stoi(307ULL)));
	global_setup.action_twist_3[9] = mkmat2(mkcol2(stoi(434ULL),stoi(123ULL)),mkcol2(stoi(378ULL),stoi(198ULL)));
	global_setup.action_twist_4[9] = mkmat2(mkcol2(stoi(100ULL),stoi(82ULL)),mkcol2(stoi(182ULL),stoi(531ULL)));
	global_setup.action_twist_2[10] = mkmat2(mkcol2(stoi(656ULL),stoi(634ULL)),mkcol2(stoi(89ULL),stoi(21ULL)));
	global_setup.action_twist_3[10] = mkmat2(mkcol2(stoi(412ULL),stoi(402ULL)),mkcol2(stoi(68ULL),stoi(266ULL)));
	global_setup.action_twist_4[10] = mkmat2(mkcol2(stoi(610ULL),stoi(430ULL)),mkcol2(stoi(184ULL),stoi(67ULL)));
	global_setup.action_twist_2[11] = mkmat2(mkcol2(stoi(797ULL),stoi(692ULL)),mkcol2(stoi(214ULL),stoi(60ULL)));
	global_setup.action_twist_3[11] = mkmat2(mkcol2(stoi(303ULL),stoi(302ULL)),mkcol2(stoi(73ULL),stoi(555ULL)));
	global_setup.action_twist_4[11] = mkmat2(mkcol2(stoi(627ULL),stoi(1ULL)),mkcol2(stoi(662ULL),stoi(230ULL)));
	global_setup.action_twist_2[12] = mkmat2(mkcol2(stoi(218ULL),stoi(442ULL)),mkcol2(stoi(493ULL),stoi(641ULL)));
	global_setup.action_twist_3[12] = mkmat2(mkcol2(stoi(36ULL),stoi(736ULL)),mkcol2(stoi(761ULL),stoi(824ULL)));
	global_setup.action_twist_4[12] = mkmat2(mkcol2(stoi(610ULL),stoi(666ULL)),mkcol2(stoi(457ULL),stoi(249ULL)));
	global_setup.action_twist_2[13] = mkmat2(mkcol2(stoi(132ULL),stoi(349ULL)),mkcol2(stoi(785ULL),stoi(751ULL)));
	global_setup.action_twist_3[13] = mkmat2(mkcol2(stoi(255ULL),stoi(857ULL)),mkcol2(stoi(878ULL),stoi(629ULL)));
	global_setup.action_twist_4[13] = mkmat2(mkcol2(stoi(127ULL),stoi(637ULL)),mkcol2(stoi(394ULL),stoi(756ULL)));
	global_setup.action_twist_2[14] = mkmat2(mkcol2(stoi(948ULL),stoi(621ULL)),mkcol2(stoi(791ULL),stoi(71ULL)));
	global_setup.action_twist_3[14] = mkmat2(mkcol2(stoi(325ULL),stoi(43ULL)),mkcol2(stoi(620ULL),stoi(695ULL)));
	global_setup.action_twist_4[14] = mkmat2(mkcol2(stoi(200ULL),stoi(562ULL)),mkcol2(stoi(490ULL),stoi(819ULL)));
	global_setup.action_twist_2[15] = mkmat2(mkcol2(stoi(539ULL),stoi(178ULL)),mkcol2(stoi(973ULL),stoi(632ULL)));
	global_setup.action_twist_3[15] = mkmat2(mkcol2(stoi(517ULL),stoi(325ULL)),mkcol2(stoi(161ULL),stoi(655ULL)));
	global_setup.action_twist_4[15] = mkmat2(mkcol2(stoi(519ULL),stoi(186ULL)),mkcol2(stoi(557ULL),stoi(652ULL)));
	global_setup.action_twist_2[16] = mkmat2(mkcol2(stoi(29ULL),stoi(843ULL)),mkcol2(stoi(846ULL),stoi(1850ULL)));
	global_setup.action_twist_3[16] = mkmat2(mkcol2(stoi(68ULL),stoi(935ULL)),mkcol2(stoi(595ULL),stoi(1812ULL)));
	global_setup.action_twist_4[16] = mkmat2(mkcol2(stoi(1864ULL),stoi(698ULL)),mkcol2(stoi(814ULL),stoi(15ULL)));
	global_setup.action_twist_2[17] = mkmat2(mkcol2(stoi(273ULL),stoi(27ULL)),mkcol2(stoi(656ULL),stoi(2440ULL)));
	global_setup.action_twist_3[17] = mkmat2(mkcol2(stoi(1223ULL),stoi(1501ULL)),mkcol2(stoi(1711ULL),stoi(1491ULL)));
	global_setup.action_twist_4[17] = mkmat2(mkcol2(stoi(256ULL),stoi(2385ULL)),mkcol2(stoi(1486ULL),stoi(2457ULL)));
	global_setup.action_twist_2[18] = mkmat2(mkcol2(stoi(447ULL),stoi(4276ULL)),mkcol2(stoi(4070ULL),stoi(3836ULL)));
	global_setup.action_twist_3[18] = mkmat2(mkcol2(stoi(439ULL),stoi(4019ULL)),mkcol2(stoi(3462ULL),stoi(3845ULL)));
	global_setup.action_twist_4[18] = mkmat2(mkcol2(stoi(679ULL),stoi(699ULL)),mkcol2(stoi(3651ULL),stoi(3604ULL)));
	global_setup.action_two_2 = mkmat2(mkcol2(stoi(7058267855ULL),stoi(1943219718ULL)),mkcol2(stoi(7651452869ULL),stoi(1531666737ULL)));
	global_setup.action_two_3 = mkmat2(mkcol2(stoi(7058267855ULL),stoi(1943219718ULL)),mkcol2(stoi(7651452869ULL),stoi(1531666737ULL)));
	global_setup.action_two_4 = mkmat2(mkcol2(stoi(7058267855ULL),stoi(1943219718ULL)),mkcol2(stoi(7651452869ULL),stoi(1531666737ULL)));
	for (int i = 0; i < 3; ++i) {
		fp_enc( &(&(&torsion_basis_two[i])->x)->re, &(torsion_basis_two_uintbig[i][0][0]) );
		fp_enc( &(&(&torsion_basis_two[i])->x)->im, &(torsion_basis_two_uintbig[i][0][1]) );
		fp_enc( &(&(&torsion_basis_two[i])->z)->re, &(torsion_basis_two_uintbig[i][1][0]) );
		fp_enc( &(&(&torsion_basis_two[i])->z)->im, &(torsion_basis_two_uintbig[i][1][1]) );
	}
	for (int i = 0; i < 3; ++i) {
		fp_enc( &(&(&torsion_basis_sum[i])->x)->re, &(torsion_basis_sum_uintbig[i][0][0]) );
		fp_enc( &(&(&torsion_basis_sum[i])->x)->im, &(torsion_basis_sum_uintbig[i][0][1]) );
		fp_enc( &(&(&torsion_basis_sum[i])->z)->re, &(torsion_basis_sum_uintbig[i][1][0]) );
		fp_enc( &(&(&torsion_basis_sum[i])->z)->im, &(torsion_basis_sum_uintbig[i][1][1]) );
	}
	for (int i = 0; i < 3; ++i) {
		fp_enc( &(&(&torsion_basis_twist_sum[i])->x)->re, &(torsion_basis_twist_sum_uintbig[i][0][0]) );
		fp_enc( &(&(&torsion_basis_twist_sum[i])->x)->im, &(torsion_basis_twist_sum_uintbig[i][0][1]) );
		fp_enc( &(&(&torsion_basis_twist_sum[i])->z)->re, &(torsion_basis_twist_sum_uintbig[i][1][0]) );
		fp_enc( &(&(&torsion_basis_twist_sum[i])->z)->im, &(torsion_basis_twist_sum_uintbig[i][1][1]) );
	}
	for (int j=0;j<12;j++){
		for (int i = 0; i < 3; ++i) {
			fp_enc( &(&(&torsion_basis[j][i])->x)->re, &(torsion_basis_uintbig[j][i][0][0]) );
			fp_enc( &(&(&torsion_basis[j][i])->x)->im, &(torsion_basis_uintbig[j][i][0][1]) );
			fp_enc( &(&(&torsion_basis[j][i])->z)->re, &(torsion_basis_uintbig[j][i][1][0]) );
			fp_enc( &(&(&torsion_basis[j][i])->z)->im, &(torsion_basis_uintbig[j][i][1][1]) );
		}
	}
	for (int j=0;j<19;j++){
		for (int i = 0; i < 3; ++i) {
			fp_enc( &(&(&torsion_basis_twist[j][i])->x)->re, &(torsion_basis_twist_uintbig[j][i][0][0]) );
			fp_enc( &(&(&torsion_basis_twist[j][i])->x)->im, &(torsion_basis_twist_uintbig[j][i][0][1]) );
			fp_enc( &(&(&torsion_basis_twist[j][i])->z)->re, &(torsion_basis_twist_uintbig[j][i][1][0]) );
			fp_enc( &(&(&torsion_basis_twist[j][i])->z)->im, &(torsion_basis_twist_uintbig[j][i][1][1]) );
		}
	}
    	for (int i=0;i<3;i++){
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->x)->re, &(torsion_basis_ted_sum_uintbig[i][0][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->x)->im, &(torsion_basis_ted_sum_uintbig[i][0][1]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->y)->re, &(torsion_basis_ted_sum_uintbig[i][1][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->y)->im, &(torsion_basis_ted_sum_uintbig[i][1][1]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->z)->re, &(torsion_basis_ted_sum_uintbig[i][2][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->z)->im, &(torsion_basis_ted_sum_uintbig[i][2][1]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->t)->re, &(torsion_basis_ted_sum_uintbig[i][3][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->t)->im, &(torsion_basis_ted_sum_uintbig[i][3][1]) );
  	}
  	for (int i=0;i<3;i++){
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->x)->re, &(torsion_basis_twist_ted_sum_uintbig[i][0][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->x)->im, &(torsion_basis_twist_ted_sum_uintbig[i][0][1]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->y)->re, &(torsion_basis_twist_ted_sum_uintbig[i][1][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->y)->im, &(torsion_basis_twist_ted_sum_uintbig[i][1][1]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->z)->re, &(torsion_basis_twist_ted_sum_uintbig[i][2][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->z)->im, &(torsion_basis_twist_ted_sum_uintbig[i][2][1]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->t)->re, &(torsion_basis_twist_ted_sum_uintbig[i][3][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->t)->im, &(torsion_basis_twist_ted_sum_uintbig[i][3][1]) );
  	}

}

