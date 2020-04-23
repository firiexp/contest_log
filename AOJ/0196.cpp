#include <iostream>
#include <algorithm>
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
    while(cin >> n, n){
        vector<pair<int, string>> v(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int val = n-i;
            for (int j = 0; j < n-1; ++j) {
                int x;
                cin >> x;
                if(x == 0) val += 100000;
                if(x == 1) val -= 100;
            }
            v[i] = {val, s};
        }
        sort(v.begin(),v.end(), greater<>());
        for (int i = 0; i < n; ++i) {
            cout << v[i].second << "\n";
        }
    }
    return 0;
}