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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            if(s == "nyanpass" || s == "-") v[i][j] = 1;
        }
    }
    int q = INF<int>;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        for (int j = 0; j < n; ++j) {
            k &= v[j][i];
        }
        if(k){
            if(q != INF<int>){
                cout << -1 << "\n";
                return 0;
            }else {
                q = i;
            }
        }
    }
    cout << (q != INF<int> ? q+1 : -1) << "\n";

    return 0;
}
