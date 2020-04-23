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

vector<int> Z_algorithm(const string &s){
    vector<int> res(s.size());
    res.front() = s.size();
    for (int i = 1, j = 0; i < s.size(); ) {
        while(i + j < s.size() && s[j] == s[i+j]) ++j;
        res[i] = j;
        if(j == 0) { ++i; continue;}
        int k = 1;
        while(i+k < s.size() && k + res[k] < j) res[i+k] = res[k], ++k;
        i += k; j -= k;
    }
    return res;
}



int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto &&i : A) scanf("%d", &i);
    for (auto &&k : B) scanf("%d", &k);
    vector<int> ok(n), val(n);
    for (int i = 0; i < 30; ++i) {
        string s, t, u;
        for (int j = 0; j < n; ++j) {
            if(A[j] & (1 << i)) s += '1';
            else s += '0';
            if(B[j] & (1 << i)) t += '1', u += '0';
            else t += '0', u += '1';
        }
        s += t;
        s += t;
        auto Z = Z_algorithm(s);
        for (int j = 0; j < n; ++j) {
            if(Z[j+n] >= n && ok[j] == i) ok[j] = i+1;
            s.pop_back(); s.pop_back();
        }
        s += u;
        s += u;
        Z = Z_algorithm(s);
        for (int j = 0; j < n; ++j) {
            if(Z[j+n] >= n && ok[j] == i) ok[j] = i+1, val[j] ^= (1 << i);
        }
    }
    for (int i = n; i > 0; --i) {
        if(ok[i%n] == 30){
            printf("%d %d\n", n-i, val[i%n]);
        }
    }
    return 0;
}