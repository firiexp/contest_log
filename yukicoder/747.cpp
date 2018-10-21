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
    string n, k;
    cin >> n >> k;
    int p = 0;
    for (int i = 0; i < n.length(); ++i) {
        p = (p*10 + n[i]- '0')%6;
    }
    if((k[k.length()-1] - '0') % 2 == 0){
        p = (p * p) % 6;
    }
    cout << "285714"[(p+5)%6] << "\n";
    return 0;
}
