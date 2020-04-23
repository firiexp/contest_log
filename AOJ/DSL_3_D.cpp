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

template<class G>
class SWAG {
    using T = typename G::T;
    vector<T> in, out, insum, outsum;
public:
    SWAG() : in(0), out(0), insum(1, G::e()), outsum(1, G::e()) {}

    void push(const T& v){
        insum.push_back(G::f(insum.back(), v));
        in.push_back(v);
    }

    void pop(){
        if(out.empty()){
            do {
                out.emplace_back(in.back());
                outsum.emplace_back(G::f(in.back(), outsum.back()));
                in.pop_back(); insum.pop_back();
            }while(!in.empty());
        }
        out.pop_back(); outsum.pop_back();
    }

    T fold(){
        return G::f(outsum.back(), insum.back());
    }
};

struct Monoid {
    using T = int;
    static T f(T a, T b) { return min(a, b); }
    static T e() { return INF<int>; }
};


int main() {
    int n, l;
    cin >> n >> l;
    SWAG<Monoid> Q;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        Q.push(x);
        if(i >= l-1) {
            if(i != l-1) printf(" ");
            printf("%d", Q.fold());
            Q.pop();
        }
    }
    puts("");
    return 0;
}