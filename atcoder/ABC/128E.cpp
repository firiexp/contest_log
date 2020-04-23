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
    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> query(2*n+1);
    query.back() = {INF<int>};
    for (int i = 0; i < n; ++i) {
        int s, t, x;
        scanf("%d %d %d", &s, &t, &x);
        query[2*i] = {s-x, x, 1};
        query[2*i+1] = {t-x, x, -1};
    }
    sort(query.begin(),query.end());
    set<int> s;
    int cur = 0;
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        while(query[cur][0] <= x){
            if(query[cur][2] == 1){
                s.insert(query[cur][1]);
            }else {
                s.erase(query[cur][1]);
            }
            cur++;
        }
        if(s.empty()) puts("-1");
        else cout << *s.lower_bound(0) << "\n";
    }
    return 0;

}