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
    vector<map<int, int>> v(2);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        if(i%2) v[0][k]++;
        else v[1][k]++;
    }
    using P = pair<int, int>;
    vector<vector<P>> v2(2);
    for (auto &&j : v[0]) {
        v2[0].emplace_back(j.second, j.first);
    }
    v2[0].emplace_back(0, 10000001);
    for (auto &&j : v[1]) {
        v2[1].emplace_back(j.second, j.first);
    }
    v2[1].emplace_back(0, 10000002);
    int a = 0, b = 0;
    sort(v2[0].rbegin(), v2[0].rend());
    sort(v2[1].rbegin(), v2[1].rend());
    while (v2[0][a].second == v2[1][b].second){
        if(v2[0][a].first - v2[0][a+1].first < v2[1][b].first - v2[1][b+1].first){
            a++;
        }else b++;
    }
    cout << n - v2[0][a].first - v2[1][b].first;
    return 0;
}
