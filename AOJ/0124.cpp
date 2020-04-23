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
    int n, cnt = 0;
    while(cin >> n, n){
        if(cnt) puts("");
        cnt++;
        vector<pair<int, string>> v(n);
        for (int i = 0; i < n; ++i) {
            string s; int a, b, c;
            cin >> s >> a >> b >> c;
            v[i] = {a*300+c*100+n-i, s};
        }
        sort(v.begin(),v.end(), greater<>());
        for (int i = 0; i < n; ++i) {
            cout << v[i].second << "," << v[i].first/100 << "\n";
        }
    }
    return 0;
}