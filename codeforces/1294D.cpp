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
    int q, x;
    cin >> q >> x;
    vector<int> v(q);
    vector<int> a(x);
    int cur = 0;
    iota(a.begin(),a.end(), 0);
    for (int i = 0; i < q; ++i) {
        int p;
        scanf("%d", &p);
        p %= x;
        int nxt = a[p];
        if(nxt < q){
            a[p] += x;
            v[nxt]++;
        }
        while(cur < q && v[cur]) cur++;
        printf("%d\n", cur);
    }
    return 0;
}