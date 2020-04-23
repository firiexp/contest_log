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
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        m[k]++;
    }
    for (auto &&i : m) {
        if(i.second % 2){
            puts("Conan");
            return 0;
        }
    }
    puts("Agasa");
    return 0;
}
