#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;


int main() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        v.emplace_back(t);
    }
    sort(v.begin(), v.end());
    vector<bool> b(n+1, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(b[i]) continue;
        int cnt = 1;
        b[i] = true;
        for (int j = i+1; j < n; ++j) {
            if(v[j] <= v[i]+k && cnt < c){
                b[j] = true;
                cnt++;
            }else break;
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
