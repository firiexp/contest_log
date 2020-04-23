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

void solve(){
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    do {
        vector<vector<char>> u(n/2);
        for (int i = 0; i < n/2; ++i) {
            string s = v[2*i], t = v[2*i+1];
            for (int j = 0; j < min(s.size(), t.size()); ++j) {
                if(s[s.size()-j-1] != t[t.size()-j-1])break;
                u[i].emplace_back(s[s.size()-j-1]);
            }
        }
        vector<int> uu(n/2);
        while(true) {
            string s;
            for (int i = 0; i < n/2; ++i) {
                if(!u[i].empty()) s += u[i][uu[i]];
            }
            sort(s.begin(), s.end());
            s.erase(unique(s.begin(), s.end()), s.end());
            ans = max(ans, (int)s.size());
            uu.back()++;
            for (int j = n/2-1; j >= 1; --j) {
                if(uu[j] >= u[j].size()) uu[j-1]++, uu[j] = 0;
            }
            if(!u.front().empty() && uu.front() >= u.front().size()) break;
            if(u.front().empty() && uu.front() >= 1) break;
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << ans*2 << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
