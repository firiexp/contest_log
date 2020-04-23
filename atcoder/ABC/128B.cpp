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
    int n;
    cin >> n;
    vector<tuple<string, int, int>> v;
    for (int i = 0; i < n; ++i) {
        string s; int p;
        cin >> s >> p;
        v.emplace_back(s, -p, i+1);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        string s; int p, q;
        tie(s, p, q) = v[i];
        cout << q << "\n";
    }
    return 0;
}