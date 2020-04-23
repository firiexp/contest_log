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

static const int MOD = 9973;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    vector<int> v(26);
    for (auto &&i : v) scanf("%d", &i);
    auto f = [&](char c){ return c - 'A';};
    cout << v[f('A')] - v[f('B')] << "\n";
    cout << v[f('C')] + v[f('D')] << "\n";
    cout << max(0, v[f('F')] - v[f('E')]+1) << "\n";
    cout << (v[f('G')] + v[f('H')] + v[f('I')])/3+1 << "\n";
    string s = "dagabaji";
    string ans;
    for (int i = 0; i < (1<<8); ++i) {
        if(__builtin_popcount(i) == v[f('J')]){
            string t;
            for (int j = 0; j < 8; ++j) {
                if(i & (1<<j)) t += s[j];
            }
            if(ans.empty()){
                ans = t;
            }
            else ans = min(ans, t);
        }
    }
    cout << ans << "\n";
    ll a = 0;
    for (int i = 0; i <= 59*61; ++i) {
        if(i%59 == v[f('K')] && i % 61 == v[f('L')]) a = i;
    }
    a += (v[f('M')]-1)*59*61;
    vector<ll> kanzen = {6, 28, 496, 8128, 33550336, 8589869056};
    ll b = INF<ll>;
    for (auto &&k : kanzen) {
        if(llabs(k-a) >= v[f('N')]) b = min(b, k);
    }
    cout << min(a, b) << "\n";
    cout << max(a, b) << "\n";
    cout << (v[f('O')]+v[f('P')]+v[f('Q')])%MOD
            *(v[f('R')]+v[f('S')]+v[f('T')])%MOD
            *(v[f('U')]+v[f('V')]+v[f('W')])%MOD
            *(v[f('X')]+v[f('Y')]+v[f('Z')])%MOD << "\n";
    return 0;
}