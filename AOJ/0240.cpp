#include <iostream>
#include <algorithm>
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
    int n;
    while(cin >> n, n){
        double val = 0, cur = 0;
        int y;
        cin >> y;
        for (int i = 0; i < n; ++i) {
            double r; int b, t;
            cin >> b >> r >> t;
            auto x = t == 1 ? 1+y*r/100 : pow((1+r/100), y);
            if(val < x){
                val = x;
                cur = b;
            }
        }
        cout << cur << "\n";
    }
    return 0;
}
