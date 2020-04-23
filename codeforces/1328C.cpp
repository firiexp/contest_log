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

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int big = 0;
    string a(n, '0'), b(n, '0');
    for (int i = 0; i < n; ++i) {
        if(big){
            a[i] = '0'; b[i] = s[i];
        }else {
            if(s[i] == '2'){
                a[i] = b[i] = '1';
            }else if(s[i] == '1'){
                big = 1;
                a[i] = '1'; b[i] = '0';
            }else {
                a[i] = b[i] = '0';
            }
        }
    }
    cout << a << "\n";
    cout << b << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}