#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ll answ = n*m/2+(n*m)%2, ansb = n*m/2;
        ll p = (x1+y1)%2*((x2-x1+1)*(y2-y1+1))%2 + (x2-x1+1)*(y2-y1+1)/2;
        answ += p, ansb -= p;
        ll q = (x3+y3+1)%2*((x4-x3+1)*(x4-x3+1))%2 + (x4-x3+1)*(x4-x3+1)/2;
        ansb += q, answ -= q;
        ll xx1 = max(x1, x3),
        xx2 = min(x2, x4),
        yy1 = max(y1, y3),
        yy2 = min(y2, y4);
        if(xx1 <= xx2 && yy1 <= yy2) {
            q = (xx1+yy1+1)%2*((xx2-xx1+1)*(yy2-yy1+1))%2 + (xx2-xx1+1)*(yy2-yy1+1)/2;
            ansb += q, answ -= q;
        }

        cout << answ << " " << ansb << "\n";
    }
    return 0;
}
