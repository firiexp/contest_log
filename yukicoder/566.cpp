#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
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
    template <class T>
    void shuffle(vector<T> &a){
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            swap(a[n-i-1], a[rand(n-i-1)]);
        }
    }
};


int main() {
    int k;
    cin >> k;
    vector<int> v((1<<k)-1);
    for (int i = 0; i < (1<<k)-1; ++i) {
        v[i] = i+1;
    }
    if(k == 2){
        puts("1 2 3");
        return 0;
    }else if(k == 3){
        puts("5 3 2 4 1 6 7");
        return 0;
    }
    xor_shift rd;
    for (int i = 0; i < (1<<k)-1; ++i) {
        int y = rd.rand((1<<k)-i-2);
        swap(v[y], v[(1<<k)-i-2]);
    }
    for (int i = 0; i < (1<<k)-1; ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    return 0;
}
