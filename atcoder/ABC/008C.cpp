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
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v.emplace_back(k);
    }
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if(i != j && v[i]%v[j] == 0){
                k++;
            }
        }
        if(k % 2) ans += 0.5;
        else ans += (2.0+k)/(2.0 + 2.0 * k);
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
