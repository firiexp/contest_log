#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int t;
    cin >> t;
    while(t--){
        int r, g, b;
        cin >> r >> g >> b;
        cout << min({(r+g+b)/2, r+g+b-max({r, g, b})}) << "\n";

    }
    return 0;
}