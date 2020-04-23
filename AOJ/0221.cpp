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
    int n, m;
    vector<string> v(10000);
    for (int i = 0; i < 10000; ++i) {
        int x = i+1;
        if(x%3 == 0 || x%5 == 0){
            v[i] = string(x%3 == 0 ? "Fizz" : "") + (x%5 == 0 ? "Buzz" : "");
        }else {
            v[i] = to_string(x);
        }
    }
    while(cin >> n >> m, n){
        vector<int> alive(n, 1);
        int cnt = n, cur = 0;
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            if(cnt == 1) continue;
            while(!alive[cur]) cur = (cur+1)%n;
            if(v[i] != s) alive[cur] = 0, cnt--;
            cur = (cur+1)%n;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if(alive[i]) ans.emplace_back(i);
        }
        for (int i = 0; i < ans.size(); ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]+1);
        }
        puts("");
    }
    return 0;
}