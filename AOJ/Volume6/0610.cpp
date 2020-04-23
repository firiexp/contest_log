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
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }



int main() {
    int h, w;
    cin >> h >> w;
    auto v = make_v(h, w, INF<int>);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == 'c'){
                for (int k = j; k < w; ++k) {
                    if(s[k] == 'c' && j != k)  {
                        j = k-1;
                        break;
                    }
                    v[i][k] = min(v[i][k], k-j);
                }
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(j) cout << " ";
            cout << (v[i][j] == INF<int> ? -1 : v[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
