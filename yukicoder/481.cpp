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
    int a;
    cin >> a;
    if(a == 2){
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 0; i < 8; ++i) {
        int b;
        cin >> b;
        if(b != a+1) {
            cout << a+1 << "\n";
            return 0;
        }
        a = b;
    }
    cout << 10 << "\n";
    return 0;
}
