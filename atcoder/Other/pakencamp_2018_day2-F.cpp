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
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

vector<pair<int, int>> solve(ll k){
    int keta = 0;
    ll l = k;
    vector<int> ketas;
    while(l > 0){
        ketas.emplace_back(l%4);
        l /= 4;
        keta++;
    }
    reverse(ketas.begin(), ketas.end());
    cout << keta*5 << " ";
    vector<pair<int, int>> v;
    v.emplace_back(1, 2);
    v.emplace_back(1, 3);
    v.emplace_back(1, 4);
    v.emplace_back(1, 5);
    for (int i = 2; i <= ketas[0]+1; ++i) {
        for (int j = 6; j <= 9; ++j) {
            v.emplace_back(i, j);
        }
    }
    for (int i = 1; i <= ketas[1]; ++i) {
        v.emplace_back(5, 5+i);
    }
    v.emplace_back(5, 10);
    for (int i = 1; i <= keta-2; ++i) {
        int kijun = i*5;
        for (int j = 1; j <= 4; ++j) {
            for (int m = 6; m <= 9; ++m) {
                v.emplace_back(kijun+j, kijun+m);
            }
        }
        for (int j = 1; j <= ketas[i+1]; ++j) {
            v.emplace_back(kijun+5, kijun+5+j);
        }
        if(i != keta-2) v.emplace_back(kijun+5, kijun+10);
    }
    int x = (keta-1)*5;
    v.emplace_back(x+1, x+5);
    v.emplace_back(x+2, x+5);
    v.emplace_back(x+3, x+5);
    v.emplace_back(x+4, x+5);
    return v;
}

int main() {
    ll k;
    cin >> k;
    vector<pair<int, int>> ans;
    if(k <= 63){
        cout << k+2 << " ";
        for (int i = 2; i <= k+1; ++i) {
             ans.emplace_back(1, i);
             ans.emplace_back(i, k+2);
        }
    }else {
        ans = solve(k);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto &&j : ans) {
        printf("%d %d\n", j.first, j.second);
    }
    return 0;
}
