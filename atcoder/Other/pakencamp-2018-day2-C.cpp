#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 1; i <= n; ++i) {
        bool valid = true;
        vector<vector<int>> group(i);
        for (int j = 0; j < n; ++j) {
            group[j%i].emplace_back(v[j]);
        }
        for (auto &&vec : group) {
            int k = 0;
            for (auto &&j : vec) {
                if(j != 0){
                    if(k == 0) k = j;
                    else {
                        if(j != k) valid = false;
                    }
                }
            }
        }
        if(valid){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
