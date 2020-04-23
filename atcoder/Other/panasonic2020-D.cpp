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
    string s = "a";
    auto dfs = [&](int x, int sz, auto &&f){
        if(x == n){
            cout << s << "\n";
            return;
        }
        for (int i = 0; i <= sz+1; ++i) {
            s += 'a' + i;
            f(x+1, max(sz, i), f);
            s.pop_back();
        }
    };
    dfs(1, 0, dfs);
    return 0;
}