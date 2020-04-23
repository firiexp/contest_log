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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n;
    cin >> n;
    n++;
    int c = 0;
    for (int i = 40; i >= 0; --i) {
        if(n & (1LL << i)){
            c = i;
            n -= (1LL << i);
            break;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= c; ++i) {
        ans.emplace_back(2*i);
    }
    for (int i = 40; i >= 0; --i) {
        if(n & (1LL << i)){
            ans.emplace_back(i*2+1);
            n -= (1LL << i);
        }
    }
    for (int i = 1; i <= 100; ++i) {
        ans.emplace_back(i);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }
    puts("");
    return 0;
}