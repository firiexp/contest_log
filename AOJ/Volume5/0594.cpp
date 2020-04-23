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
    int w, h, n;
    cin >> w >> h >> n;
    ll ans = 0;
    vector<pair<int, int>> v(n);
    for (auto &&i : v) scanf("%d %d", &i.first, &i.second);
    for (int i = 0; i < n-1; ++i) {
        if(v[i].first < v[i+1].first && v[i].second < v[i+1].second){
            ans += max(v[i+1].first-v[i].first,  v[i+1].second - v[i].second);
        } else if(v[i].first > v[i+1].first && v[i].second > v[i+1].second){
            ans += max(v[i].first-v[i+1].first,  v[i].second - v[i+1].second);
        } else ans += abs(v[i].first-v[i+1].first)+ abs(v[i].second-v[i+1].second);
    }
    cout << ans << "\n";
    return 0;
}
