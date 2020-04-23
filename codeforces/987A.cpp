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

int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> v {
            {"Power", "purple"},
            {"Time", "green"},
            {"Space", "blue"},
            {"Soul", "orange"},
            {"Reality", "red"},
            {"Mind", "yellow"}
    };
    vector<string> in(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    cout << 6-n << "\n";
    for (int i = 0; i < 6; ++i) {
        int found = false;
        for (int j = 0; j < n; ++j) {
            if(in[j] == v[i].second) found = true;
        }
        if(!found) cout << v[i].first << "\n";
    }
    return 0;
}
