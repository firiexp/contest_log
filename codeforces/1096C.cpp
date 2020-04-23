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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int t;
    cin >> t;
    array<int, 180> v{};
    fill(v.begin(),v.end(), INF<int>);
    for (int i = 3; i <= 360; ++i) {
        for (int j = 1; j <= i-2; ++j) {
            if(180*j%i == 0){
                int ans = 180*j/i;
                v[ans] = min(v[ans], i);
            }
        }
    }
    while(t--){
        int x;
        cin >> x;
        cout << v[x] << "\n";
    }
    return 0;
}