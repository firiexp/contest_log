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
    vector<int> v(n), v2(n-1), v3(n-2);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&j : v2) scanf("%d", &j);
    for (auto &&k : v3) scanf("%d", &k);
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    int ok = 0;
    for (int i = 0; i < n-1; ++i) {
        if(v[i] != v2[i]) {
            ok = 1;
            cout << v[i] << "\n";
            break;
        }
    }
    if(!ok) cout << v.back() << "\n";
    ok = 0;
    for (int i = 0; i < n-2; ++i) {
        if(v3[i] != v2[i]) {
            ok = 1;
            cout << v2[i] << "\n";
            break;
        }
    }
    if(!ok) cout << v2.back() << "\n";
    return 0;
}