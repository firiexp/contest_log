#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int x1, y1, x2, y2, t, v, n;
    cin >> x1 >> y1 >> x2 >> y2 >> t >> v >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if(sqrt((a-x1)*(a-x1)+(b-y1)*(b-y1))+sqrt((a-x2)*(a-x2)+(b-y2)*(b-y2))<= t*v){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
