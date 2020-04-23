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
#pragma GCC optimize ("-O3", "unroll-loops")


int main() {
    int n, r;
    cin >> n >> r;
    r = min(r, n-r);
    vector<int> p(n);
    for (auto &&i : p) scanf("%d", &i), i--;
    vector<int> visited(n);
    int k = 0;
    vector<int> sz;
    for (int i = 0; i < n; ++i) {
        if(visited[i]) continue;
        if(p[i] == i) {
            k++;
            continue;
        }
        int cnt = 0;
        while(!visited[i]){
            cnt++;
            visited[i] = 1;
            i = p[i];
        }
        sz.emplace_back(cnt);
    }
    bitset<150001> v;
    v.set(0);
    for (int i : sz) v |= (v << i);
    for (int i = max(0, r-k); i <= r; ++i) {
        if(v[i]){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}