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
    using p = array<bool, 255>;
    stack<p> s;
    map<string, p> v;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string x; int a, b;
        cin >> x >> a >> b;
        p k{};
        for (int j = a; j <= b; ++j) {
            k[j] = true;
        }
        v[x] = k;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        if(v.count(t)){
            s.emplace(v[t]);
        }else if(t.size() == 1 && (t[0] < '0' || t[0] > '9')){
            p b = s.top(); s.pop(); p a = s.top(); s.pop();
            p c{};
            if(t[0] == '+'){
                for (int j = 0; j < 256; ++j) {
                    if(!a[j]) continue;
                    for (int k = 0; k < 256; ++k) {
                        if(!b[k]) continue;
                        c[(j+k)%256] = true;
                    }
                }
            }else if(t[0] == '-'){
                for (int j = 0; j < 256; ++j) {
                    if(!a[j]) continue;
                    for (int k = 0; k < 256; ++k) {
                        if(!b[k]) continue;
                        c[(j+256-k)%256] = true;
                    }
                }
            }else if(t[0] == '*'){
                for (int j = 0; j < 256; ++j) {
                    if(!a[j]) continue;
                    for (int k = 0; k < 256; ++k) {
                        if(!b[k]) continue;
                        c[(j*k)%256] = true;
                    }
                }
            }else {
                for (int j = 0; j < 256; ++j) {
                    if(!a[j]) continue;
                    for (int k = 0; k < 256; ++k) {
                        if(!b[k]) continue;
                        if(k == 0) {
                            puts("error");
                            return 0;
                        }
                        c[(j/k)%256] = true;
                    }
                }
            }
            s.emplace(c);
        }else {
            int k = stoi(t);
            p x{};
            x[k] = true;
            s.emplace(x);
        }
    }
    puts("correct");
    return 0;
}