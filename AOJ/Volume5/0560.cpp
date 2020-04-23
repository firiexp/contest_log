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
template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    auto J = make_v(h+1, w+1, 0);
    auto O = J, I = J;
    for (int i = 1; i <= h; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; ++j) {
            if(s[j-1] == 'J') J[i][j]++;
            else if(s[j-1] == 'O') O[i][j]++;
            else I[i][j]++;
        }
    }
    for (int i = 0; i < h+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            J[i][j] += J[i][j-1];
            O[i][j] += O[i][j-1];
            I[i][j] += I[i][j-1];
        }
    }
    for (int i = 1; i < h+1; ++i) {
        for (int j = 0; j < w+1; ++j) {
            J[i][j] += J[i-1][j];
            O[i][j] += O[i-1][j];
            I[i][j] += I[i-1][j];
        }
    }
    for (int i = 0; i < k; ++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int ans1 = J[c][d]-J[a-1][d]-J[c][b-1]+J[a-1][b-1],
            ans2 = O[c][d]-O[a-1][d]-O[c][b-1]+O[a-1][b-1],
            ans3 = I[c][d]-I[a-1][d]-I[c][b-1]+I[a-1][b-1];
        printf("%d %d %d\n", ans1, ans2, ans3);
    }
    return 0;
}
