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
    int n, m;
    cin >> n >> m;
    using P = pair<int, int>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].second, &v[i].first);
    }
    vector<int> u(m);
    for (auto &&j : u) scanf("%d", &j);
    sort(v.begin(),v.end(), greater<>());
    sort(u.begin(),u.end(), greater<>());
    int a = 0, b = 0;
    while(a < u.size() && b < v.size()){
        while(b < v.size() && v[b].second > u[a]) b++;
        if(b == v.size()) break;
        a++; b++;
    }
    cout << a << "\n";
    return 0;
}