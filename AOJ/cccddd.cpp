#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> a, b;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == 'B'){
                a.emplace_back(i+j);
                b.emplace_back(i-j);
            }
        }
    }
    auto P = minmax_element(a.begin(),a.end()), Q = minmax_element(b.begin(),b.end());
    cout << max(*P.second-*P.first, *Q.second-*Q.first) << "\n";
    return 0;
}