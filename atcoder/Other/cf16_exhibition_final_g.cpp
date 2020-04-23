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
#include <random>
#include <chrono>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

vector<ll> v = {1,255,43435,6347715,866251507,114429029715,14877590196755,1919209135381395,246614610741341843};

int main() {
    string X = "FESTIVAL";
    ll k;
    cin >> k;
    string s;
    vector<ll> ans(9);
    for (int i = 8; i >= 0; --i) {
        ans[i] = k/v[i];
        k %= v[i];
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 7; ++j) {
            s += string(1<<i, X[j]);
        }
        s += string(ans[i], 'L');
        if(accumulate(ans.begin()+i+1,ans.end(), 0LL) == 0) break;
    }
    cout << s << "\n";
    return 0;
}