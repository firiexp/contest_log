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

string bin(int x){
    if(!x) return "0";
    string ans;
    while(x){
        ans += to_string(x&1);
        x /= 2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        cout << 0 << "\n";
    }else if(n == 2){
        cout << 2 << "\n";
        cout << 0 << "\n";
        cout << 11 << "\n";
    }else {
        cout << n-1 << "\n";
        for (int i = 2; i <= n; ++i) {
            string s(i, '0');
            s.front() = s.back() = '1';
            cout << s << "\n";
        }
    }
    return 0;
}