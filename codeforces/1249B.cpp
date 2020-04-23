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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i), i--;
        vector<int> ans(n);
        vector<int> used(n);
        vector<int> u;
        for (int i = 0; i < n; ++i) {
            if(!used[i]){
                used[i] = 1;
                u.clear();
                u.emplace_back(i);
                int j = i;
                while(v[j] != i){
                    used[j] = 1;
                    u.emplace_back(v[j]);
                    j = v[j];
                }
                for (auto &&k : u) {
                    ans[k] = u.size();
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}