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
    int n, m;
    cin >> n >> m;
    if(m < 2*n || 4*n < m){
        cout << "-1 -1 -1\n";
        return 0;
    }
    int p = m-2*n;
    int q = p%2, r = p/2;
    printf("%d %d %d", n-q-r, q, r);
    return 0;
}
