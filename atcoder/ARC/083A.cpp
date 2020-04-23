#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<int> v1, v2;
    a*=100, b*=100;
    for (int i = 0; i <= f/a; ++i) {
        v1.emplace_back(i*a);
    }
    for (int i = 0; i <= f/a; ++i) {
        for (int j = 0; j <= (f-v1[i])/b; ++j) {
            v1.emplace_back(v1[i]+j*b);
        }
    }
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    for (int i = 0; i <= f/c; ++i) {
        v2.emplace_back(i*c);
    }
    for (int i = 0; i <= f/c; ++i) {
        for (int j = 0; j <= (f-v2[i])/d; ++j) {
            v2.emplace_back(v2[i]+j*d);
        }
    }

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    double up = (((double)e*100)/((double)(100+e)));
    double ans = 0;
    int maxx = 0, maxy = 0;
    for (auto &&x : v1) {
        for (auto &&y : v2) {
            if(x+y != 0){
                double k = (double)100*y/(double)(x+y);
                if(ans <= k && k <= up && x+y <= f ){
                    ans = k;
                    maxx = x;
                    maxy = y;
                }
            }
        }
    }
    cout << maxx+maxy << " " << maxy << "\n";
    return 0;
}
