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
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n-1; ++i) {
        if(v[i]*y > v[i+1]*x){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
