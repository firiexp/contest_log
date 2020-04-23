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
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                int ok = 0;
                for (int x = 0; x < n; ++x) {
                    if(ok == 0){
                        if(s[x]-'0' == i) ok++;
                    }else if(ok == 1){
                        if(s[x]-'0' == j) ok++;
                    }else if(ok == 2){
                        if(s[x]-'0' == k) ok++;
                    }else break;
                }
                if(ok == 3) ans++;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}