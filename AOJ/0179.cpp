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
    string s;
    while(cin >> s, s != "0"){
        map<string, int> m;
        queue<string> Q;
        Q.emplace(s);
        m[s] = 0;
        int p = 0;
        while(!Q.empty()){
            string x = Q.front(); Q.pop();
            int ok = 1;
            for (int i = 0; i+1 < x.size(); ++i) {
                if(x[i] != x[i+1]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                p = 1;
                cout << m[x] << "\n";
                break;
            }
            for (int i = 0; i+1 < x.size(); ++i) {
                if(x[i] == x[i+1]) continue;;
                string y = x;
                auto w = 'r'^'g'^'b'^x[i]^x[i+1];
                y[i] = y[i+1] = w;
                if(!m.count(y)){
                    m[y] = m[x]+1;
                    Q.emplace(y);
                }
            }
        }
        if(!p){
            puts("NA");
        }
    }
    return 0;
}