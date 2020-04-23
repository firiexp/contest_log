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
    while(t--){
       string x, y;
       cin >> x >> y;
       sort(x.begin(),x.end());
       int ok = 0;
        for (int i = 0; i+x.size() <= y.size(); ++i) {
            string yy = y.substr(i, x.size());
            sort(yy.begin(),yy.end());
            if(x == yy) ok = 1;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}