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
    int x, n, m;
    cin >> x >> n >> m;
    set<int> s, t;
    for (int i = 0; i < n; ++i) {
        int w;
        scanf("%d", &w);
        s.emplace(w);
    }
    for (int i = 0; i < m; ++i) {
        int w;
        scanf("%d", &w);
        t.emplace(w);
    }
    if(s.count(x) && t.count(x)){
        puts("MrMaxValu");
    }else if(s.count(x)){
        puts("MrMax");
    }else if(t.count(x)){
        puts("MaxValu");
    }else {
        puts("-1");
    }
    return 0;
}