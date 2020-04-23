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

#include <chrono>
class xor_shift {
    uint32_t x, y, z, w;
public:
    xor_shift() : x(static_cast<uint32_t>((chrono::system_clock::now().time_since_epoch().count())&((1LL << 32)-1))),
                  y(1068246329), z(321908594), w(1234567890) {};

    uint32_t urand(){
        uint32_t t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w;
    };

    int rand(int n){
        if(n < 0) return -rand(-n);
        uint32_t t = numeric_limits<uint32_t>::max()/(n+1)*(n+1);
        uint32_t e = urand();
        while(e >= t) e = urand();
        return static_cast<int>(e%(n+1));
    }

    int rand(int a, int b){
        if(a > b) swap(a, b);
        return a+rand(b-a);
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i = 0; i < 2*n; ++i) {
        v[i] = i+1;
    }
    xor_shift rd;
    for (int i = 0; i < 2*n; ++i) {
        int y = rd.rand(2*n-i-1);
        swap(v[y], v[2*n-i-1]);
    }
    vector<pair<int, int>> u;
    for (int i = 0; i < n; ++i) {
        if(v[i*2] < v[i*2+1]) u.emplace_back(v[i*2+1], v[i*2]);
    }
    sort(u.begin(),u.end());
    for (int i = 0; i < u.size(); ++i) {
        cout << u[i].second << " " << u[i].first << "\n";
    }
    puts("");
    return 0;
}