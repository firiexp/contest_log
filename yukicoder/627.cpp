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
    int t;
    cin >> t;
    int x;
    cin >> x;
    if(x != -1 && x != 1){
        cout << "F\n";
        return 0;
    }
    for (int i = 0; i < t-1; ++i) {
        int y;
        cin >> y;
        if(abs(y-x) != 1){
            cout << "F\n";
            return 0;
        }
        x = y;
    }
    cout << "T\n";
    return 0;
}
