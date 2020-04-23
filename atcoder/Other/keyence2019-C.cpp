#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> v;
    ll sa = 0, sb = 0;
    for (auto &&item : a) {
        scanf("%d", &item);
        sa += item;
    }
    for (auto &&i : b) {
        scanf("%d", &i);
        sb += i;
    }
    if(sb > sa){
        puts("-1");
        return 0;
    }
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        v.emplace_back(a[i]-b[i], i);
    }
    ll k = sa-sb;
    int ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        if(v[i].first < 0) continue;
        int p, q;
        tie(p, q) = v[i];
        if(k >= p) {
            ans++;
            k -= p;
        }
    }
    cout << n-ans << "\n";
    return 0;
}
