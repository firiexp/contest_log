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
    int n;
    cin >> n;
    string a = "DCHS", b = "A23456789TJQK";
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v[i] = {a.find(s[0]), b.find(s[1])};
    }
    sort(v.begin(), v.end());
    for (auto &&i : v) {
        cout << a[i.first] << b[i.second] <<" ";
    }
    return 0;
}
