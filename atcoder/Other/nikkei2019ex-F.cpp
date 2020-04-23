#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll m = 1789997546303;
    int n;
    cin >> n;
    while(1000-(++n) >= 0){
        if(m%2) m = m*3+1;
        else m/= 2;
    }
    cout << m << "\n";
    return 0;
}
