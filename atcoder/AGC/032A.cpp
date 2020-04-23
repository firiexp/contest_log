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

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "}";
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        for (int j = n-i-1; j >= 0; --j) {
            if(v[j] == j){
                for (int k = j; k < n-i-1; ++k) {
                    v[k] = v[k+1];
                }
                v[n-i-1] = INF<int>;
                ans.emplace_back(j+1);
                break;
            }
        }
        if(v[n-i-1] != INF<int>){
            puts("-1");
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
