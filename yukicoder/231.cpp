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
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int g, d;
        cin >> g >> d;
        v.emplace_back(g-30000*d, i+1);
    }
    sort(v.begin(), v.end(), greater<>());
    if(v[0].first < 500000) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < 6; ++i) {
        cout << v[0].second << "\n";
    }
    return 0;
}
