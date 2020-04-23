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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    cin >> s;
    array<int, 10> v{};
    for (auto &&i : s) {
        v[i-'0']++;
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = i+1; j < 10; ++j) {
            if(v[i] && v[j]) ans = __gcd(ans, j-i);
        }
    }
    if(ans == 0){
        cout << s << "\n";
        return 0;
    }
    ans *= 9;
    int val = 0;
    for (int i = s.size()-1; i >= 0; --i) {
        val = (val*10+s[i]-'0')%ans;
    }
    cout << __gcd(ans, val) << "\n";
    return 0;
}