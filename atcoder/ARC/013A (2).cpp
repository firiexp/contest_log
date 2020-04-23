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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int a, b, c;
    vector<int> v(3);
    cin >> a >> b >> c >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    int ans = 0;
    do{
        ans = max(ans, (a/v[0])*(b/v[1])*(c/v[2]));
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << "\n";
    return 0;
}
