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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto S = accumulate(v.begin(),v.end(), 0LL);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i]*4*m >= S) cnt++;
    }
    puts(cnt >= m ? "Yes" : "No");
    return 0;
}