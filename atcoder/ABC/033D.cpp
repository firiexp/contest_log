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

const double pi = acos(-1);
constexpr double EPS = 1e-10;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &&i : v) scanf("%d %d", &i.first, &i.second);
    ll chokkaku = 0, donkaku = 0;
    for (int i = 0; i < n; ++i) {
        vector<double> u;
        for (int j = 0; j < n; ++j) {
            if(i != j) {
                u.emplace_back(atan2(v[j].first-v[i].first, v[j].second-v[i].second));
                u.emplace_back(atan2(v[j].first-v[i].first, v[j].second-v[i].second)+2*pi);
            }
        }
        sort(u.begin(),u.end());
        for (int j = 0; j < n - 1; ++j) {
            chokkaku += upper_bound(u.begin(),u.end(), u[j]+pi/2+EPS)
                    - lower_bound(u.begin(),u.end(), u[j]+pi/2-EPS);
            donkaku += upper_bound(u.begin(),u.end(), u[j]+pi)
                    - upper_bound(u.begin(),u.end(), u[j]+pi/2+EPS);
        }
    }
    printf("%lld %lld %lld\n" , (ll)n*(n-1)*(n-2)/6-chokkaku-donkaku, chokkaku, donkaku);
    return 0;
}