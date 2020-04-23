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
    int n, a = 0, b = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(x&1) a++;
        else b++;
    }
    while(a>1 || b>1){
        if(a >= 2) {
            b += a/2;
            a = a&1;
        }
        if(b >= 2) b = b/2 + (b&1);
    }
    cout << (a+b==1 ? "YES" : "NO") << "\n";
    return 0;
}
