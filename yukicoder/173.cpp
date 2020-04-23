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
struct Timer {
    ll starttime;
    static constexpr ll CYCLES_PER_SEC = 2250000000;
    Timer() { starttime = get_cycle(); }
    double get() { return (double)(get_cycle()-starttime)/CYCLES_PER_SEC; };
    static ll get_cycle() {
        u32 a, b;
        __asm__ volatile("rdtsc" : "=a"(a), "=d"(b));
        return ((ll)a)|((ll)b << 32);
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
    int n; double x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int p = 0, q = 0;
    xor_shift rd;
    Timer timer;
    while(timer.get() < 3){
        vector<int> A = a, B = b;
        int score1 = 0, score2 = 0;

        for (int i = 0; i < n; ++i) {
            double s = rd.urand()/4294967295.0, t = rd.urand()/4294967295.0;
            if(i == n-1){
                (A.back() > B.back() ? score1 : score2) += (A.back() + B.back());
            }else {
                int cur1 = 0, cur2 = 0;
                if(s > x) cur1 = rd.rand(1, n-i-1);
                if(t > y) cur2 = rd.rand(1, n-i-1);
                (A[cur1] > B[cur2] ? score1 : score2) += (A[cur1] + B[cur2]);
                A.erase(A.begin()+cur1);
                B.erase(B.begin()+cur2);
            }
        }
        q++;
        if(score1 > score2) p++;
    }
    printf("%.10lf", 1.0*p/q);
    return 0;
}