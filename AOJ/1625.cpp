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
    int n, m, t, p;
    while (cin >> n >> m >> t >> p, n){
        vector<int> v(n, 1), u(m, 1);
        for (int i = 0; i < t; ++i) {
            int d, c;
            cin >> d >> c;
            if(d == 1){
                vector<int> vv(max((int)v.size()-c, c));
                for (int j = 0; j < vv.size(); ++j) {
                    if(j+c < v.size()) vv[j] = v[j+c];
                    if(c-1-j >= 0) vv[j] += v[c-1-j];
                }
                v.swap(vv);
            }else {
                vector<int> uu(max((int)u.size()-c, c));
                for (int j = 0; j < uu.size(); ++j) {
                    if(j+c < u.size()) uu[j] = u[j+c];
                    if(c-1-j >= 0) uu[j] += u[c-1-j];
                }
                u.swap(uu);
            }
        }
        for (int i = 0; i < p; ++i) {
            int x, y;
            cin >> x >> y;
            cout << u[y]*v[x] << "\n";
        }
    }
    return 0;
}