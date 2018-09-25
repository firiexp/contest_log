#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v.emplace_back(k);
    }
    for (int i = 0; i < n; ++i) {
        ans++;
        int p = 1;
        if(i >= n-2) break;

        if(v[i]<=v[i+1]) for (int j = i+1; j < n; ++j) {
                if(v[j-1] <= v[j]){
                    p = max(p, j-i+1);
                }else break;
        }
        if(v[i]>=v[i+1]) for (int j = i+1; j < n; ++j) {
                if(v[j-1] >= v[j]){
                    p = max(p, j-i+1);
                }else break;
        }
        i += p-1;
    }
    cout << ans << "\n";
    return 0;
}
