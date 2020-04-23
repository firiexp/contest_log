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
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n <= 100){
            long double x = 0, p = 0;
            vector<long double> dp1(n+1), dp2(n+1);
            dp1[0] = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= 6; ++j) {
                    if(i+j > n){
                        x += dp1[i]/6;
                        p += (dp2[i]/dp1[i]+1)*dp1[i]/6;
                    }else {
                        dp1[i+j] += dp1[i]/6;
                        dp2[i+j] += (dp2[i]/dp1[i]+1)*dp1[i]/6;
                    }
                }
            }
            p /= x;
            long double q = dp2.back()/dp1.back();
            printf("%.15Lf\n", (q*x-p*x-q)/(x-1));
        }else {
            printf("%.15Lf\n", n+5.0L/3);
        }
    }

    return 0;
}