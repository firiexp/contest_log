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
    int n;
    cin >> n;
    char c = 'a';
    string ans = "a", t;
    while(n){
        t += '0'+(n&1);
        n /= 2;
    }
    t.pop_back();
    reverse(t.begin(),t.end());
    for (char i : t) {
        ans = c + ans + c;
        if(i == '1'){
            c++;
            if(c > 'z') c = 'a';
            ans = c + ans + c;
        }

    }
    cout << ans << "\n";
    return 0;
}