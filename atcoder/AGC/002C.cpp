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
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 1; i < n; ++i) {
        if(v[i-1] + v[i] >= l){
            puts("Possible");
            for (int j = 1; j < i; ++j) {
                printf("%d\n", j);
            }
            for (int j = n-1; j > i; --j) {
                printf("%d\n", j);
            }
            printf("%d\n", i);
            return 0;
        }
    }
    puts("Impossible");
    return 0;
}
