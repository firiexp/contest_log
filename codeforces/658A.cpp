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
    int n, c;
    cin >> n >> c;
    vector<int> p(n), t(n);
    for (auto &&i : p) scanf("%d", &i);
    for (auto &&j : t) scanf("%d", &j);
    int A = 0, T = 0;
    for (int i = 0; i < n; ++i) {
        T += t[i]; A += max(0, p[i]-c*T);
    }
    int B = 0; T = 0;
    for (int i = n - 1; i >= 0; --i) {
        T += t[i]; B += max(0, p[i]-c*T);
    }
    if(A < B) puts("Radewoosh");
    else if(A > B) puts("Limak");
    else puts("Tie");
    return 0;
}