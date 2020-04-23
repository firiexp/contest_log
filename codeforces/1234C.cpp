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
char buf[200001];
int main() {
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int a = 1, b = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] <= '2' && t[i] <= '2') {}
            else if(s[i] <= '2') b = 0;
            else if(t[i] <= '2') a = 0;
            else {
                swap(a, b);
            }
        }
        puts(b ? "YES" : "NO");
    }
    return 0;
}