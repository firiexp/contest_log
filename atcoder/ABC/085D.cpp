#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> v;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(b);
        x = max(x, a);
    }
    sort(v.begin(), v.end(), greater<>());
    partial_sum(v.begin(), v.end(), v.begin());
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        if(h <= v[i]){
            ans = min(ans, i+1);
            break;
        }else {
            ans = min(ans, (h-v[i]+x-1)/x+i+1);
        }
    }
    cout << ans << "\n";
    return 0;
}
