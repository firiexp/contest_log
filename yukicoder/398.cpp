#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


vector<ll> ans = {601, 2985, 8915, 20700, 41796, 76170, 128305, 203145, 306731, 445530, 626460, 856830, 1144981, 1499595, 1929755, 2444850, 3055236, 3771540, 4604725, 5565975, 6667391, 7921260, 9340140, 10936740, 12724621, 14717445, 16929095, 19373520, 22065456, 25019670, 28251085, 31774605, 35605871, 39760470, 44254080, 49102290, 54321361, 59927415, 65936615, 72364950, 79229016, 86545200, 94329865, 102599115, 111369611, 120657720, 130479720, 140851560, 151789681, 163310145, 175428875, 188161380, 201523596, 215531010, 230198905, 245542065, 261575651, 278314290, 295772340, 313963590, 332902141, 352601475, 373074755, 394334490, 416393436, 439263660, 462956845, 487483935, 512856071, 539083620, 566176500, 594143820, 622994821, 652737885, 683380895, 714930840, 747394776, 780778830, 815088565, 850328565, 886503431, 923616750, 961671480, 1000669530, 1040612761, 1081501935, 1123337135, 1166117310, 1209841296, 1254506760, 1300110625, 1346648595, 1394116211, 1442507760, 1491816720, 1542035280, 1593155401, 1645167705, 1698061955, 1751826540, 1806449556, 1861917705, 1918216810, 1975331310, 2033245421, 2091942030, 2151403230, 2211609825, 2272542496, 2334180660, 2396503055, 2459487210, 2523110616, 2587349595, 2652179890, 2717576100, 2783512901, 2849963880, 2916902130, 2984299695, 3052128796, 3120360630, 3188966015, 3257914800, 3327177096, 3396722085, 3466518670, 3536534850, 3606739001, 3677098650, 3747581130, 3818152965, 3888781156, 3959431920, 4030071395, 4100664990, 4171178676, 4241577735, 4311827470, 4381892520, 4451738201, 4521329220, 4590630390, 4659605955, 4728220936, 4796439810, 4864227275, 4931547540, 4998365676, 5064646305, 5130354370, 5195454390, 5259911861, 5323691910, 5386760070, 5449081545, 5510622616, 5571349260, 5631227975, 5690225010, 5748307776, 5805443475, 5861599930, 5916744780, 5970846941, 6023875200, 6075799050, 6126587895, 6176212516, 6224643630, 6271852775, 6317811480, 6362492736, 6405869565, 6447915910, 6488605770, 6527914721, 6565818450, 6602293650, 6637317165, 6670867516, 6702923400, 6733464635, 6762471270, 6789925116, 6815808255, 6840103990, 6862795920, 6883869521, 6903310620, 6921106350, 6937244235, 6951713776, 6964504890, 6975608915, 6985017660, 6992724996, 6998725305, 7003014490, 7005588990, 7006447421, 7005588990, 7003014490, 6998725305, 6992724996, 6985017660, 6975608915, 6964504890, 6951713776, 6937244235, 6921106350, 6903310620, 6883869521, 6862795920, 6840103990, 6815808255, 6789925116, 6762471270, 6733464635, 6702923400, 6670867516, 6637317165, 6602293650, 6565818450, 6527914721, 6488605770, 6447915910, 6405869565, 6362492736, 6317811480, 6271852775, 6224643630, 6176212516, 6126587895, 6075799050, 6023875200, 5970846941, 5916744780, 5861599930, 5805443475, 5748307776, 5690225010, 5631227975, 5571349260, 5510622616, 5449081545, 5386760070, 5323691910, 5259911861, 5195454390, 5130354370, 5064646305, 4998365676, 4931547540, 4864227275, 4796439810, 4728220936, 4659605955, 4590630390, 4521329220, 4451738201, 4381892520, 4311827470, 4241577735, 4171178676, 4100664990, 4030071395, 3959431920, 3888781156, 3818152965, 3747581130, 3677098650, 3606739001, 3536534850, 3466518670, 3396722085, 3327177096, 3257914800, 3188966015, 3120360630, 3052128796, 2984299695, 2916902130, 2849963880, 2783512901, 2717576100, 2652179890, 2587349595, 2523110616, 2459487210, 2396503055, 2334180660, 2272542496, 2211609825, 2151403230, 2091942030, 2033245421, 1975331310, 1918216810, 1861917705, 1806449556, 1751826540, 1698061955, 1645167705, 1593155401, 1542035280, 1491816720, 1442507760, 1394116211, 1346648595, 1300110625, 1254506760, 1209841296, 1166117310, 1123337135, 1081501935, 1040612761, 1000669530, 961671480, 923616750, 886503431, 850328565, 815088565, 780778830, 747394776, 714930840, 683380895, 652737885, 622994821, 594143820, 566176500, 539083620, 512856071, 487483935, 462956845, 439263660, 416393436, 394334490, 373074755, 352601475, 332902141, 313963590, 295772340, 278314290, 261575651, 245542065, 230198905, 215531010, 201523596, 188161380, 175428875, 163310145, 151789681, 140851560, 130479720, 120657720, 111369611, 102599115, 94329865, 86545200, 79229016, 72364950, 65936615, 59927415, 54321361, 49102290, 44254080, 39760470, 35605871, 31774605, 28251085, 25019670, 22065456, 19373520, 16929095, 14717445, 12724621, 10936740, 9340140, 7921260, 6667391, 5565975, 4604725, 3771540, 3055236, 2444850, 1929755, 1499595, 1144981, 856830, 626460, 445530, 306731, 203145, 128305, 76170, 41796, 20700, 8915, 2985, 601};

int main() {
    int aa, bb;
    scanf("%d.%d", &aa, &bb);
    int val = aa*4+bb/25;
    cout << ans[val] << "\n";
    return 0;
}