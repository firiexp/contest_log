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
    vector<pair<int, int>> v(n);
    vector<int> cnt(m);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        if(l <= m-1-r){
            v[i] = {l, r};
        }else {
            v[i] = {m-1-r, m-1-l};
        }
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        int l, r; tie(l, r) = v[i];
        int ok = 1;
        for (int j = l; j <= r; ++j) {
            if(cnt[j]) {
                ok = 0;
                break;
            }
        }
        if(ok){
            for (int j = l; j <= r; ++j) cnt[j] = 1;
        }else {
            for (int j = m-1-r; j <= m-1-l; ++j) {
                if(cnt[j]){
                    puts("NO");
                    return 0;
                }
                cnt[j] = 1;
            }
        }
    }
    puts("YES");
    return 0;
}