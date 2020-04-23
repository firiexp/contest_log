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

string ch(string s, string &a, string &b){
    auto p = s.find(a);
    while(p != string::npos){
        s.replace(p, a.size(), b);
        p = s.find(a, p + b.size());
    }
    return s;
}

int main() {
    int n;
    while(cin >> n, n){
        vector<string> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        string s, t;
        cin >> s >> t;
        vector<vector<string>> v(10);
        map<string, int> X;
        v[0].emplace_back(s);
        X[s] = 0;
        for (int i = 0; i < 9; ++i) {
            for (auto &&j : v[i]) {
                for (int k = 0; k < n; ++k) {
                    string u = ch(j, a[k], b[k]);
                    if(!X.count(u)){
                        v[i+1].emplace_back(u);
                        X[u] = i+1;
                    }
                }
            }
        }
        if(X.count(t)) cout << X[t] << "\n";
        else puts("-1");
    }

    return 0;
}