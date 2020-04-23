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

using P = tuple<int, int, int>;

int main() {
    int n;
    while(cin >> n, n){
        set<P> A, B;
        A.emplace(-1, 0, MOD);
        B.emplace(0, MOD, -1);
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            if(c == 'W'){
                int x, y;
                cin >> x >> y;
                auto it = A.begin();
                while(y){
                    int p, q, r; tie(p, q, r) = (*it);
                    it = A.erase(it); B.erase(P(q, r, p));
                    if(r-q >= y){
                        A.emplace(x, q, q+y);
                        B.emplace(q, q+y, x);
                        A.emplace(p, q+y, r);
                        B.emplace(q+y, r, p);
                        y = 0;
                    }else {
                        y -= r-q;
                        A.emplace(x, q, r);
                        B.emplace(q, r, x);
                    }
                }
            }else {
                int x;
                cin >> x;
                if(c == 'D'){
                    auto it = A.lower_bound(P(x, 0, 0));
                    while(it != A.end() && get<0>(*it) == x) {
                        int p, q, r; tie(p, q, r) = (*it);
                        it = A.erase(it); B.erase(P(q, r, p));
                        A.emplace(-1, q, r);
                        B.emplace(q, r, -1);
                    }
                }else {
                    auto it = B.lower_bound(P(x, -1, -1));

                    int p, q, r; tie(p, q, r) = (*it);
                    while(x < p || it == B.end()) {
                        it--;
                        tie(p, q, r) = (*it);
                    }
                    cout << get<2>(*it) << "\n";
                }
            }
        }
        puts("");
    }

    return 0;
}