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
    for (int i = 0; i < n; ++i) {
        int p;
        scanf("%d", &p);
        if(p % 8 == 0) printf("iki");
        if(p % 10 == 0) printf("sugi");
        if(p % 8 && p % 10 && p % 3 == 0) printf("%d", p/3);
        printf("\n");
    }
    return 0;
}
