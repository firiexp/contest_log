#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n;
    cin >> n;
    ll k = 26, m = 1;
    while(k <= n){
        n -= k;
        k *= 26;
        m++;
    }
    string s;
    while(m){
        s += static_cast<char>(n%26+'A');
        n /= 26;
        m--;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}
