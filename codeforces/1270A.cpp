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
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        vector<int> a(k1), b(k2);
        for (auto &&i : a) scanf("%d", &i);
        for (auto &&j : b) scanf("%d", &j);
        int X = *max_element(a.begin(),a.end());
        int Y = *max_element(b.begin(),b.end());
        if(X > Y) puts("YES");
        else puts("NO");
    }
    return 0;
}