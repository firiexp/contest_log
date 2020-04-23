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

vector<int> mul(vector<int> x, vector<int> y){
    vector<int> z(x.size());
    for (int i = 0; i < x.size(); ++i) {
        z[i] = x[y[i]];
    }
    return z;
}


vector<int> pow_(vector<int> x, int n){
    vector<int> ans(x.size()), xx = x;
    iota(ans.begin(),ans.end(), 0);
    while(n > 0){
        if(n & 1) ans = mul(ans, xx);
        xx = mul(xx, xx);
        n >>= 1;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), A(n), B(n);
    for (auto &&i : a) scanf("%d", &i), i--;
    for (auto &&i : b) scanf("%d", &i), i--;
    if(k == 1){
        for (int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", a[i]+1);
        }
        puts("");
        return 0;
    }
    vector<string> v{"b", "bA", "bAB", "bABaB", "bABaaB", "bABabaB"};
    for (int i = 0; i < n; ++i) {
        A[a[i]] = i;
        B[b[i]] = i;
    }
    auto f = [&](string s){
        vector<int> ans(n);
        iota(ans.begin(),ans.end(),0);
        for (char i : s) {
            if(i == 'a') ans = mul(ans, a);
            else if(i == 'b') ans = mul(ans, b);
            else if(i == 'A') ans = mul(ans, A);
            else if(i == 'B') ans = mul(ans, B);
        }
        return ans;
    };
    vector<int> X = f("bABa"), Y = f("AbaB");
    auto ans = mul(mul(pow_(X, (k-2)/6), f(v[(k-2)%6])), pow_(Y, (k-2)/6));
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    puts("");
    return 0;
}