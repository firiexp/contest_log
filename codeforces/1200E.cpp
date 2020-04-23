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
#include <random>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

vector<int> z_algorithm(const string& s) {
    vector<int> v(s.size());
    v[0] = s.size();
    for (int i = 1, j = 0; i < s.size() ;) {
        while (i+j < s.size() && s[j] == s[i+j]) ++j;
        v[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < s.size() && k+v[k] < j) v[i+k] = v[k], ++k;
        i += k; j -= k;
    }
    return v;
}


int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    int ans = 0;
    for (auto &&i : v) cin >> i, ans += i.size();
    string X = v[0];
    for (int i = 0; i < n-1; ++i) {
        int A = X.size(), B = v[i+1].size();
        string x = v[i+1]+X.substr(max(0, A-B));
        int k = 0;
        auto p = z_algorithm(x);
        for (int j = 0; j < min(A, B); ++j) {
            if(p[p.size()-j-1] == j+1) k = max(k, j+1);
        }
        X += v[i+1].substr(k);
    }
    cout << X << "\n";
    return 0;
}