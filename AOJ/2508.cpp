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
    int n;
    while(cin >> n, n){
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        string s;
        cin >> s;
        auto f = [](char c){
            if('a' <= c && c <= 'z') return int(c-'a');
            else return int(c-'A'+26);
        };
        auto g = [](int x){
            x = (x%52+52)%52;
            if(0 <= x && x < 26) return char('a'+x);
            else return char('A'+(x-26));
        };
        for (int i = 0; i < s.size(); ++i) {
            s[i] = g(f(s[i])-v[i%n]);
        }
        cout << s << "\n";
    }
    return 0;
}