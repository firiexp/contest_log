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

template<class T>
class BIT2D {
    vector<vector<T>> bit;
public:
    BIT2D(int h, int w): bit(h+1, vector<T>(w+1)){}

    T sum(int y, int x){
        T ret = 0;
        for (int k = y+1; k > 0; k -= (k & -k)) {
            for (int l = x+1; l > 0; l -= (l & -l)) {
                ret ^= bit[k][l];
            }
        }
        return ret;
    }

    void add(int y, int x, T c){
        for (int k = y+1; k < bit.size(); k  += (k & -k)){
            for (int l = x+1; l < bit[0].size(); l  += (l & -l)){
                bit[k][l] ^= c;
            }
        }
    }
};

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
    int n, m, q;
    cin >> n >> m >> q;
    xor_shift rd;
    BIT2D<u32> S(n, m);
    vector<vector<u32>> v(n, vector<u32>(m, 0));
    for (int i = 0; i < q; ++i) {
        int t, r1, r2, c1, c2;
        scanf("%d %d %d %d %d", &t, &r1, &c1, &r2, &c2);
        if(t == 1){
            r1--; c1--;
            v[r1][c1] = rd.urand();
            S.add(r1, c1, v[r1][c1]);
            S.add(r1, c2, v[r1][c1]);
            S.add(r2, c1, v[r1][c1]);
            S.add(r2, c2, v[r1][c1]);
        }else if(t == 2) {
            r1--; c1--;
            S.add(r1, c1, v[r1][c1]);
            S.add(r2, c1, v[r1][c1]);
            S.add(r1, c2, v[r1][c1]);
            S.add(r2, c2, v[r1][c1]);
        }else {
            u32 val1 = S.sum(r1-1, c1-1), val2 = S.sum(r2-1, c2-1);
            puts(val1 == val2 ? "Yes" : "No");
        }
    }
    return 0;
}