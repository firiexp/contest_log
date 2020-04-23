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

bool IsKadomatsu(int a, int b, int c){
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(IsKadomatsu(a, b, c)) {
        puts("INF");
    }else {
        int ans = 0;
        for (int i = 1; i <= 1000; ++i) {
            if(IsKadomatsu(a%i, b%i, c%i)) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
