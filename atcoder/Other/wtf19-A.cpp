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
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "}";
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<pair<int, int>> vvv;
    vvv.reserve(n);
    for (int i = 0; i < n; ++i) {
        vvv.emplace_back(v[i], i);
    }
    for (int q = 0; q < n; ++q) {
        auto vv = vvv;
        int c1 = q;
        vector<int> ans;
        ans.emplace_back(c1);
        vv[c1].first--;
        bool valid = true;
        for (int i = 0; i < k+1; ++i) {
            sort(vv.begin(), vv.end(), greater<>());
            if(vv.back().second == c1){
                for (int j = 0; j < n-1; ++j) {
                    ans.emplace_back(vv[j].second);
                    vv[j].first--;
                }
                c1 = vv[n-2].second;
            }else {
                for (int j = 0; j < n; ++j) {
                    if(vv[j].second != c1){
                        ans.emplace_back(vv[j].second);
                        vv[j].first--;
                    }
                }
                c1 = vv.back().second;
            }
        }
        for (auto &&i : vv) {
            if(i.first < 0){
                valid = false;
            }
        }
        if(valid){
            cout << ans.size() << "\n";
            for (int i = 0; i < ans.size(); ++i) {
                if(i) cout << " ";
                cout << ans[i]+1;
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}
