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
    vector<int> v(10, 1);
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        string r;
        cin >> a >> b >> c >> d >> r;
        if(r == "NO"){
            v[a] = 0, v[b] = 0, v[c] = 0, v[d] = 0;
        }else {
            for (int j = 0; j < 10; ++j) {
                if(a != j && b != j && c != j && d != j){
                    v[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i <= 9; ++i) {
        if(v[i] == 1){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
