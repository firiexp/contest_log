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
#include <chrono>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

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
    vector<array<int, 4>> v{};
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if(i == j) continue;
            for (int k = 0; k <= 9; ++k) {
                if(i == k || j == k) continue;
                for (int l = 0; l <= 9; ++l) {
                    if(i == l || j == l || k == l) continue;
                    v.emplace_back(array<int, 4>{i, j, k, l});
                }
            }
        }
    }
    xor_shift rd;
    while(true){
        int k = rd.rand(v.size()-1);
        for (int i = 0; i < 4; ++i) {
            if(i) cout << " ";
            cout << v[k][i];
        }
        cout << endl;
        int x, y;
        cin >> x >> y;
        if(x == 4){
            return 0;
        }
        vector<array<int, 4>> newv;
        for (int i = 0; i < v.size(); ++i) {
            if(i == k) continue;
            int a = 0, b = 0;
            for (int j = 0; j < 4; ++j) {
                if(v[k][j] == v[i][j]) a++;
                else {
                    for (int l = 0; l < 4; ++l) {
                        if(v[i][j] == v[k][l]) b++;
                    }
                }
            }
            if(a == x && b == y) newv.push_back(v[i]);
        }
        v = newv;
    }

}