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
    int n;
    while(cin >> n, n){
        map<int, int> m, ans;
        for (int wwww = 0; wwww < n; ++wwww) {
            int a, b, c, d, f; char e;
            scanf("%d/%d %d:%d %c %d ", &a, &b, &c, &d, &e, &f);
            int time = a*1000000+b*10000+c*60+d;

            if(e == 'I'){
                m[f] = time;
                if(!f){
                    for (auto &&i : m) {
                        i.second = time;
                    }
                }
            }else {
                if(f){
                    if(m.count(0)) ans[f] += time-m[f];
                    m.erase(f);
                }else {
                    for (auto &&i : m) {
                        ans[i.first] += time-i.second;
                        i.second = time;
                    }
                    m.erase(0);
                }
            }
        }
        int p = 0;
        for (auto &&j : ans) {
            if(j.first) p = max(p, j.second);
        }
        cout << p << "\n";
    }
    return 0;
}