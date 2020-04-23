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

template<u32 M = 1000000007>
struct modint{
    u32 val;
    modint(): val(0){}
    template<typename T>
    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}

    modint pow(ll k) const {
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    template<typename T>
    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}
    modint inv() const {return pow(M-2);}
    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}
    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}
    modint& operator/=(modint a){return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(M-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
};
using mint = modint<MOD>;

template<int W, int start>
class AhoCorasick {
public:
    struct Node {
        array<int, W> to;
        int fail;
    };
    explicit AhoCorasick() : v(1) {}
    vector<Node> v;
    vector<int> ord;
    int add(string &s, int cur = 0){
        for (auto &&i : s) {
            if(!v[cur].to[i-start]) v[cur].to[i-start] = v.size(), v.emplace_back();
            cur = v[cur].to[i-start];
        }
        return cur;
    }

    void build() {
        v[0].fail = -1;
        int l = 0, r = 1;
        ord.clear();
        ord.reserve(v.size());
        ord.emplace_back(0);
        while(l < r){
            int i = ord[l]; l++;
            for (int c = 0; c < W; ++c) {
                if(!v[i].to[c]) continue;
                int to = v[i].to[c];
                v[to].fail = (v[i].fail == -1 ? 0 : v[v[i].fail].to[c]);
                ord.emplace_back(to);
                r++;
            }
            if(i != 0){
                for (int c = 0; c < W; ++c) {
                    if(!v[i].to[c]) v[i].to[c] = v[v[i].fail].to[c];
                }
            }
        }
    }
    inline int next(int x, char c){ return v[x].to[c-start]; }
};

mint dp[32][501][601][2];
int to[601][501];
int to2[601][501];
int dp0[601];
void solve(int n, int m, int K){
    vector<string> words;
    vector<vector<int>> G;
    fill(dp0, dp0+601, 0);
    vector<string> kigo(K);
    int sz = 0;
    {
        int cur = 0;
        map<string, int> exist;
        for (int i = 0; i < n; ++i) {
            string s, t;
            cin >> s >> t;
            if(!exist.count(s)) {
                exist[s] = cur++;
                words.emplace_back(s);
                G.emplace_back();
            }
            if(!exist.count(t)){
                exist[t] = cur++;
                words.emplace_back(t);
                G.emplace_back();
            }
            G[exist[s]].emplace_back(exist[t]);
        }
        n = words.size();
        AhoCorasick<26, 'a'> aho;
        for (int i = 0; i < K; ++i) {
            cin >> kigo[i];
            dp0[aho.add(kigo[i])]++;
        }
        aho.build();
        for (auto &&i : aho.ord) if(i) dp0[i] += dp0[aho.v[i].fail];
        sz = aho.v.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < n; ++j) {
                to[i][j] = i;
                to2[i][j] = 0;
                for (auto &&c : words[j]) {
                    to[i][j] = aho.next(to[i][j], c);
                    to2[i][j] += dp0[to[i][j]];
                }
            }
        }
    }
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < sz; ++k) {
                for (int l = 0; l < 2; ++l) {
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(to2[0][i] < 2) dp[words[i].size()&31][i][to[0][i]][to2[0][i]] += mint(1);
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < sz; ++k) {
                for (int l = 0; l < 2; ++l) {
                    dp[(i+22)&31][j][k][l] = 0;
                }
            }
        }
        for (int o = 0; o < n; ++o) {
            for (auto &&j : G[o]) {
                if(i+words[j].size() > m) continue;
                int now = i&31, next = (now+words[j].size())&31;
                for (int k = 0; k < sz; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        if(l + to2[k][j] >= 2) continue;
                        dp[next][j][to[k][j]][l+to2[k][j]] += dp[now][o][k][l];
                    }
                }
            }
        }
    }
    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz; ++j) {
            ans += dp[m&31][i][j][1];
        }
    }
    cout << ans.val << "\n";
}

int main() {
    int n, m, k;
    while(cin >> n >> m >> k, n){
        solve(n, m, k);
    }
    return 0;
}