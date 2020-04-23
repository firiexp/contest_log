#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s += 'x';
    vector<pair<int, int>> v;
    int l = 0, r = 0;
    while(l < n && r < n){
        while(s[l] == s[r]) r++;
        v.emplace_back(l, r);
        l = r;
    };
    int ans = 0;
    int c = 0, p = 0; l = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(s[v[i].first] == '0') c++;
        p += v[i].second-v[i].first;
        if(c > k) {
            if(s[v[l].first] == '1'){
                p -= v[l].second - v[l].first;
                l++;
            }
            p -= v[l].second - v[l].first;
            l++;
            c--;
        }
        ans = max(ans, p);
    }
    cout << ans << "\n";
    return 0;
}
