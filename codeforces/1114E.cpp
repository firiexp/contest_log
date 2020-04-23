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
using u32 = unsigned;
using u64 = unsigned long long;
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
    int querycnt = 59;
    int a0;
    cout << "? " << 1 << endl;
    cin >> a0;
    int ok = a0-1, ng = 1000000000;
    vector<int> vals{a0};
    while(ng - ok > 1){
        querycnt--;
        int mid = (ok+ng)/2;
        cout << "> " << mid << endl;
        int res; cin >> res;
        if(res) ok = mid;
        else ng = mid;
    }
    vector<int> got(n);
    iota(got.begin(),got.end(), 0);
    vals.emplace_back(ng);
    xor_shift rd;
    int cur = 1;
    while(querycnt && cur < n){
        int no = rd.rand(1, n-1);
        swap(got[no], got[cur]);
        cout << "? " << got[cur]+1 << endl;
        int res; cin >> res;
        vals.emplace_back(res);
        querycnt--; cur++;
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int res = 0;
    for (int i = 0; i+1 < vals.size(); ++i) {
        res = __gcd(res, vals[i+1]-vals[i]);
    }
    cout << "! " << ng-(n-1)*res << " " << res << endl;
    return 0;
}