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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int h, w;
    cin >> h >> w;
    vector<pair<int, int>> v;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '*') v.emplace_back(i, j);
        }
    }
    if(v[0].first == v[1].first) {
        v.emplace_back((v[0].first == 0 ? 1 : 0), v[0].second);
    }else {
        v.emplace_back(v[0].first, (v[0].second == 0 ? 1 : 0));
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int flag = 0;
            for (int k = 0; k < 3; ++k) {
                if(v[k].first == i && v[k].second == j) flag = 1;
            }
            cout << (flag ? '*' : '-');
        }
        puts("");
    }
    return 0;
}
