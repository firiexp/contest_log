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
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    int s = 1;
    while(n > 0){
        if((s-1)%12+1 >= p && (s-1)%12+1 <= p+q-1) n -= 2*m;
        else n -= m;
        if(n > 0) s++;
    }
    cout << s << "\n";
    return 0;
}
