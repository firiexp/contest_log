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
    int n, m;
    cin >> n >> m;
    map<int,int> v;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a]++, v[b]++;
    }
    for (auto &&i : v) {
        if(i.second % 2){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
