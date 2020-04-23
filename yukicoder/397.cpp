#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        int M = 0, Midx = 0;
        for (int j = 0; j < n-i; ++j) {
            if(M <= v[j]){
                M = v[j];
                Midx = j;
            }
        }
        if(Midx != n-i-1){
            ans.emplace_back(Midx, n-i-1);
            swap(v[Midx], v[n-i-1]);
        }
    }
    cout << ans.size() << "\n";
    for (auto &&k : ans) {
        cout << k.first << " "  << k.second << "\n";
    }
    cin >> n;
    cout << endl;
    return 0;
}
