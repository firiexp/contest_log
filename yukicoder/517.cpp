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
    int n, m;
    vector<vector<int>> G(26);
    vector<int> in(26, -1);
    cin >> n;
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(in[s[0]-'A'] == -1) in[s[0]-'A'] = 0;
        sz += s.size();
        for (int j = 0; j+1 < s.size(); ++j) {
            int from = s[j]-'A', to = s[j+1]-'A';
            if(in[to] == -1) in[to] = 0;
            if(in[from] == -1) in[from] = 0;
            in[to]++;
            G[from].emplace_back(to);
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if(in[s[0]-'A'] == -1) in[s[0]-'A'] = 0;
        for (int j = 0; j+1 < s.size(); ++j) {
            int from = s[j]-'A', to = s[j+1]-'A';
            if(in[to] == -1) in[to] = 0;
            if(in[from] == -1) in[from] = 0;
            in[to]++;
            if(G[from].empty()) G[from].emplace_back(to);
        }
    }
    for (int i = 0; i < 26; ++i) {
        if(!in[i]){
            string s(1, 'A'+i);
            int cur = i;
            while(!G[cur].empty()){
                cur = G[cur].front();
                s += char('A'+cur);
            }
            if(s.size() == sz){
                cout << s << "\n";
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}