#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s[i+1] = s[i] + x;
    }
    if(s.back()%3){
        puts("0");
        return 0;
    }
    ll sum = s.back()/3;
    ll a = 0, b = 0;
    for (int i = 1; i < n; ++i) {
        if(s[i] == sum*2) b += a;
        if(s[i] == sum) a++;
    }
    cout << b << "\n";
    return 0;
}
