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

int main() {
    ll m, n, mulx, addx, muly, addy, X;
    cin >> m >> n >> mulx >> addx >> muly >> addy >> X;
    vector<ll> x(m), y(m), a(m), b(m);
    for (auto &&i : x) scanf("%lld", &i);
    for (auto &&i : y) scanf("%lld", &i);
    for (auto &&i : a) scanf("%lld", &i);
    for (auto &&i : b) scanf("%lld", &i);
    vector<ll> A(X+1);
    for (int i = 0; i < m; ++i) {
        A[x[i]] += y[i];
    }
    ll nowx = x.back(), nowy = y.back();
    for (int j = m; j < n; ++j) {
        nowx = (nowx * mulx + addx)&(X-1);
        nowy = (nowy * muly + addy)&(X-1);
        A[nowx] += nowy;
    }
    vector<char> V(X+1);
    for (int i = 2; i <= X; ++i) {
        if(!V[i]){
            for (int j = X/i; j != 0; --j) {
                V[i*j] = 1;
                A[j] += A[i*j];
            }
        }
    }
    ll anss = 0;
    for (int i = 0; i < m; ++i) {
        ll ans = A[a[i]];
        if(a[i]*b[i] <= X) ans -= A[a[i]*b[i]];
        printf("%lld\n",ans);
        anss ^= ans;
    }
    ll nowa = a.back(), nowb = b.back();

    for (int j = m; j < n; ++j) {
        nowa = ((nowa * mulx + addx+X-1)&(X-1)) + 1;
        nowb = ((nowb * muly + addy+X-1)&(X-1)) + 1;
        ll ans = A[nowa];
        if(nowa*nowb <= X) ans -= A[nowa*nowb];
        anss ^= ans;
    }
    printf("%lld\n", anss);
    return 0;
}