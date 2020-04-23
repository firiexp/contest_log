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
};




int main() {
    int L, N, M;
    cin >> L >> N >> M;
    vector<ll> R(N), P(N), A(M), B(M), C(M), D(M);
    for (int i = 0; i < N; i++)
    {
        cin >> R[i] >> P[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--; B[i]--;
    }
    auto calcscore = [&](vector<ll> &x, vector<ll> &y, vector<ll> &z){
        ll ret = 0;
        for (int i = 0; i < N; ++i) {
            if(x[i] != -1 && y[i] != -1 && z[i] != -1){
                ret += P[i];
            }
        }
        for (int i = 0; i < M; ++i) {
            ll a = A[i], b = B[i], c = C[i], d = D[i];
            if((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])+ (z[a]-z[b])*(z[a]-z[b]) <= c*c) ret += d;
        }
        return ret;
    };
    for (int i = 0; i < 100; ++i) {

    }
    return 0;
}
