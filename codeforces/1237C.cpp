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
    using A = array<int, 4>;
    vector<array<int, 4>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &v[i][j]);
        }
        v[i][3] = i+1;
    }
    sort(v.begin(),v.end());
    vector<A> b;
    int cur = 0;
    vector<int> ans1, ans2, ans3;
    while(cur < n){
        int cur2 = cur;
        vector<A> c;
        while(cur2 < n && v[cur][0] == v[cur2][0]) {
            c.emplace_back(v[cur2]);
            cur2++;
        }
        cur = cur2;
        vector<A> d;
        int curr = 0;
        while(curr < c.size()){
            int curr2 = curr;
            while(curr2 < c.size() && c[curr][1] == c[curr2][1]) {
                curr2++;
            }
            if((curr2-curr)&1){
                d.emplace_back(c[curr]);
                curr++;
            }
            while(curr < curr2){
                printf("%d %d\n", c[curr][3], c[curr+1][3]);
                curr += 2;
            }
        }
        if(d.size()&1) b.emplace_back(d[0]);
        for (int i = d.size()&1; i < d.size();) {
            printf("%d %d\n", d[i][3], d[i+1][3]);
            i += 2;
        }
    }
    for (int i = 0; i < b.size()/2; ++i) {
        printf("%d %d\n", b[i*2][3], b[i*2+1][3]);
    }
    return 0;
}