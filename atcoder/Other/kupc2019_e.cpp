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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        vector<vector<int>> v(m);
        for (int j = 1; j < m; ++j) {
            int x;
            scanf("%d", &x);
            v[j].emplace_back(x-1);
            v[x-1].emplace_back(j);
        }
        deque<int> Q;
        stack<int> s;
        int cnt = 0;
        vector<int> visited(m, 0), num(m);
        s.emplace(0);
        while(!s.empty()){
            int a = s.top(); s.pop();
            visited[a]++;
            num[a] = cnt++;
            Q.emplace_front(a);
            for (auto &&j : v[a]) {
                if(!visited[j]) s.emplace(j);
            }
        }
        vector<int> dp(m);
        for (auto &&x : Q) {
            vector<int> a;
            for (auto &&j : v[x]) {
                if(num[x] < num[j]){
                    a.emplace_back(dp[j]);
                }
            }
            sort(a.begin(),a.end());
            if(a.empty() || a[0] != 0) dp[x] = 0;
            else {
                int ok = 0;
                for (int j = 0; j+1 < a.size(); ++j) {
                    if(a[j+1] - a[j] > 1){
                        dp[x] = a[j] + 1;
                        ok = 1;
                        break;
                    }
                }
                if(!ok) dp[x] = a.back()+1;
            }
        }
        ans ^= dp.front();
    }
    puts(ans ? "Bob" : "Alice");
    return 0;
}