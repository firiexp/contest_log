#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "}";
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(26);
    vector<int> in(26), visited(26);
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        int c = 0;
        while(c < min(s.size(), t.size()) && s[c] == t[c]) c++;
        if(c == min(s.size(), t.size())){
            if(s > t){
                puts("-1");
                return 0;
            }
        }else {
            v[s[c]-'a'].emplace_back(t[c]-'a');
            in[t[c]-'a']++;
        }
    }
    int x = 1;
    string s;
    while(x){
        x = 0;
        for (int i = 0; i < 26; ++i) {
            if(visited[i] || in[i]) continue;
            stack<int> S; x++;
            S.emplace(i);
            visited[i] = 1;
            s += ('a'+i);
            for (auto &&j : v[i]) {
                in[j]--;
            }
            v[i].clear();
            break;
        }
    }
    if(s.size() < 26) puts("-1");
    else cout << s << "\n";
    return 0;
}
