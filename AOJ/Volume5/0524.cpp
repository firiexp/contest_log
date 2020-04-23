#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int m;
    while (cin >> m, m){
        vector<pair<int, int>> v, v2;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            v.emplace_back(a, b);
        }
        int n;
        cin >> n;
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            s.emplace(a, b);
            v2.emplace_back(a, b);
        }
        for (int i = 0; i < n; ++i) {
            int pp = v2[i].first-v[0].first, qq = v2[i].second-v[0].second;
            int valid = 1;
            for (int j = 0; j < m; ++j) {
                if(!s.count(make_pair(v[j].first+pp, v[j].second+qq))) valid = 0;
            }
            if(valid) {
                cout << pp << " " << qq << "\n";
            }
        }
    }
    return 0;
}
