#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int y, x, yy, xx;
    cin >> y >> x;
    if(x == 2 || y == 2) {
        cout << "Second" << "\n";
        return 0;
    }
    for (int i = x+1;; ++i) {
        if (is_prime(i)) {
            xx = i;
            break;
        }
    }
    for (int i = y+1;; ++i) {
        if (is_prime(i)) {
            yy = i;
            break;
        }
    }
    int dis = (yy - y - 1) + (xx - x - 1);
    if(dis%2) cout << "First" << "\n";
    else cout << "Second" << "\n";
    return 0;
}
