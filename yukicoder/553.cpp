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

double F(int n) {
    double p = 0, q = 0;
    for (int i = 1; i <= n; ++i) {
        p += pow(0.81, i);
        q += pow(0.9, i);
    }
    return sqrt(p)/q;
}

double g(double X){
    return pow(2.0, X/800.0);
}

double ginv(double X){
    return 800*log2(X);
}

int main() {
    double a = 0.229415733871;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    double f = 1200.0*(F(n)-a)/(F(1)-a);
    double k = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        k += g(v[i])*pow(0.9, i+1);
        l += pow(0.9, i+1);
    }
    printf("%.0f\n", ginv(k/l)-f);
    return 0;
}