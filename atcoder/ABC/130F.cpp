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
    cin >> n;
    vector<int> x(n), y(n);
    vector<char> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> d[i];
    }
    double l = 0, r = INF<int>;
    double xmax = INF<ll>, xmin = -INF<ll>, ymax = INF<ll>, ymin = -INF<ll>;
    double xmax2 = INF<ll>, xmin2 = -INF<ll>, ymax2 = INF<ll>, ymin2 = -INF<ll>;
    for (int i = 0; i < 300; ++i) {
        double lb = (l*2+r)/3, ub = (l+2*r)/3;
        xmax = -INF<ll>, xmin = INF<ll>, ymax = -INF<ll>, ymin = INF<ll>;
        xmax2 = -INF<ll>, xmin2 = INF<ll>, ymax2 = -INF<ll>, ymin2 = INF<ll>;
        for (int j = 0; j < n; ++j) {
            double X1 = x[j], Y1 = y[j], X2 = x[j], Y2 = y[j];
            if(d[j] == 'R')  X1 += lb,  X2 += ub;
            if(d[j] == 'L')  X1 -= lb,  X2 -= ub;
            if(d[j] == 'U')  Y1 += lb,  Y2 += ub;
            if(d[j] == 'D')  Y1 -= lb,  Y2 -= ub;
            xmax = max(xmax, X1); xmin = min(xmin, X1);
            ymax = max(ymax, Y1); ymin = min(ymin, Y1);
            xmax2 = max(xmax2, X2); xmin2 = min(xmin2, X2);
            ymax2 = max(ymax2, Y2); ymin2 = min(ymin2, Y2);
        }
        if((xmax-xmin)*(ymax-ymin) < (xmax2-xmin2)*(ymax2-ymin2)) r = ub;
        else l = lb;
    }
    cout << setprecision(15) << (xmax-xmin)*(ymax-ymin) << "\n";
    return 0;
}