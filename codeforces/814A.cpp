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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> u(k);
    for (auto &&j : u) scanf("%d", &j);
    sort(u.begin(),u.end(), greater<>());
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if(!v[i]) v[i] = u[cur++];
    }
    for (int i = 0; i < n-1; ++i) {
        if(v[i] >= v[i+1]){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}