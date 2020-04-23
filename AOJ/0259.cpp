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

string get(int x){
    string s = to_string(x);
    return string(4-s.size(), '0') + s;
}

int main() {
    map<string, int> dp;
    dp["6174"] = 0;
    auto dfs = [&](string s, auto &&f){
        if(dp.count(s)) return dp[s];
        string a = s, b = s;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(), greater<>());
        return dp[s] = f(get(stoi(b)-stoi(a)), f)+1;
    };
    for (int i = 0; i <= 9999; ++i) {
        if(i%1111 == 0) dp[get(i)] = -1;
        else dfs(get(i), dfs);
    }
    string s;
    while(cin >> s, s != "0000"){
        if(dp[s] < 0) puts("NA");
        else cout << dp[s] << "\n";
    }
    return 0;
}