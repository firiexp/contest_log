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

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        for (int j = max(0, i-r+1); j < min(n, i+r); ++j) {
            if(v[j] == 2) ok = 1;
        }
        if(!ok){
            for (int j = min(n, i+r)-1; j >= max(0, i-r+1); --j) {
                if(v[j] == 1) {
                    ok = 1;
                    v[j] = 2;
                    ans++;
                    break;
                }
            }
            if(!ok){
                puts("-1");
                return 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}