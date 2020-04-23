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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    vector<ll> k {
            0,
            5,
            29,
            169,
            5741,
            33461,
            195025,
            1136689,
            38613965,
            225058681,
            1311738121,
            44560482149,
            259717522849,
            1513744654945,
            51422757785981,
            299713796309065,
            1746860020068409,
            10181446324101389,
            345869461223138161
    };
    vector<ll> l {
            0,
            3,
            20,
            119,
            4059,
            23660,
            137903,
            803760,
            27304196,
            159140519,
            927538920,
            31509019100,
            183648021599,
            1070379110496,
            36361380737780,
            211929657785303,
            1235216565974040,
            7199369738058939,
            244566641436218639
    };
    int x;
    cin >> x;
    cout << l[x] <<" " << l[x]+1 << " " << k[x] << "\n";
    return 0;
}
