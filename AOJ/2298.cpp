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
    int n, k, t, u, v, l;
    cin >> n >> k >> t >> u >> v >> l;
    vector<int> carrot(l+1);
    for (int i = 0; i < n; ++i) {
        int d;
        scanf("%d", &d);
        carrot[d]++;
    }
    int boost = 0, cnt = 0;
    double ans = 0;
    for (int cur = 0; cur < l; ++cur) {
        if(carrot[cur]) {
            if(cnt == k) boost = t*v;
            else {
                cnt++;
                if(boost == 0){
                    boost = t*v;
                    cnt--;
                }
            }
        }
        if(boost){
            ans += 1.0 / v;
            boost--;
            if(boost == 0 && cnt){
                boost = t*v;
                cnt--;
            }
        }else {
            ans += 1.0 / u;
        }
    }
    printf("%.10f\n", ans);
    return 0;
}