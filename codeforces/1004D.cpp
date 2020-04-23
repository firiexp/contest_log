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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    int n;
    cin >> n;
    int x = 1, p = 0;
    vector<int> cnt(n+1), cntt(n+1);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
        p = max(p, a);
    }
    if(cnt[0] != 1){
        puts("-1");
        return 0;
    }
    while(x < n && cnt[x] == (x)*4) x++;
    auto v = divisor(n);
    for (auto &&h : v) {
        int w = n/h;
        int y = h+w-p-x;
        if(x <= 0 || h < x || y <= 0 || w < y) continue;
        fill(cntt.begin(),cntt.end(), 0);
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cntt[abs(i-x)+abs(j-y)]++;
            }
        }
        if(cnt == cntt){
            printf("%d %d\n", h, w);
            printf("%d %d\n", x, y);
            return 0;
        }
    }
    puts("-1");
    return 0;
}