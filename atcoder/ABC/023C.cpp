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
    int r, c, k;
    cin >> r >> c >> k;
    vector<int> R(r, 0), C(c, 0);
    int n;
    cin >> n;
    vector<pair<int,int>> V;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        R[a-1]++;
        C[b-1]++;
        V.emplace_back(a-1, b-1);
    }
    ll ans = 0;
    for (auto &&i : V) {
        if(R[i.first] + C[i.second] == k) ans--;
        else if (R[i.first] + C[i.second] == k+1) ans++;
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < r; ++i) {
        if(k >= R[i]) ans += upper_bound(C.begin(), C.end(), k-R[i]) - lower_bound(C.begin(), C.end(), k-R[i]);
    }

    cout << ans << "\n";
    return 0;
}

