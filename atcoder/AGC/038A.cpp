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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(i*a+(h-i)*(w-a) == j*b+(w-j)*(h-b)){
                auto v = make_v(h, w, 0);
                vector<int> ans(w);
                for (int k = 0; k < h; ++k) {
                    int cnt = (k < i ? a : w-a);
                    for (int l = 0; l < w; ++l) {
                        if(l < j){
                            if(ans[l] < b && cnt) {
                                cnt--;
                                ans[l]++;
                                v[k][l]++;
                            }
                        }else {
                            if(ans[l] < h-b && cnt) {
                                cnt--;
                                ans[l]++;
                                v[k][l]++;
                            }
                        }
                    }
                }
                for (int k = 0; k < h; ++k) {
                    for (int l = 0; l < w; ++l) {
                        cout << v[k][l];
                    }
                    puts("");
                }
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}