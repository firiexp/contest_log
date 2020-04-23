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

int main() {
    int a, b, c, n;
    while(cin >> a >> b >> c, a|b|c){
        cin >> n;
        vector<int> v(a+b+c+1, 0);
        vector<vector<int>> vv;
        for (int i = 0; i < n; ++i) {
            int p, q, r, s;
            cin >> p >> q >> r >> s;
            if(s == 1) {
                v[p] = v[q] = v[r] = 1;
            }else vv.push_back({p, q, r});
        }
        for (auto &&j : vv) {
            if (v[j[0]] + v[j[1]] + v[j[2]] == 2){
                for (int i = 0; i < 3; ++i) if(v[j[i]] == 0) v[j[i]] = 10;
            }
        }
        for (int i = 1; i <= a+b+c; ++i) {
            if(v[i] == 0) cout << 2 << "\n";
            else if(v[i] == 1) cout << 1 << "\n";
            else if(v[i] == 10) cout << 0 << "\n";
        }
    }

    return 0;
}
