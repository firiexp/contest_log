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
    int n, d, k;
    cin >> n >> d >> k;
    using P = pair<int, int>;
    vector<P> v;
    for (int i = 0; i < d; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        v.emplace_back(l, r);
    }
    for (int i = 0; i < k; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        int day = 1;
        for (auto &&j : v) {
            if(s < j.first || j.second < s) {
                day++;
                continue;
            }
            if(s < t) {
                if(t <= j.second) s = t;
                else s = j.second;
            }else {
                if(t >= j.first) s = t;
                else s = j.first;
            }
            if(s == t) {
                cout << day << "\n";
                break;
            }
            day++;
        }
    }
    return 0;
}
