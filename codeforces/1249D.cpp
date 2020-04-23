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
    int n, k;
    cin >> n >> k;
    using P = array<int, 3>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i][1], &v[i][0]);
        v[i][2] = i+1;
    }
    sort(v.begin(),v.end());
    multiset<int> s;
    for (int i = 0; i < k; ++i) {
        s.insert(0);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound(v[i][1]);
        if(it != s.begin()){
            --it;
            s.erase(it);
            s.insert(v[i][0]);
        }else {
            ans.emplace_back(v[i][2]);
        }
    }
    printf("%zu\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}