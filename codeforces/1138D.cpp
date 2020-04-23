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

int main() {
    string s, t;
    cin >> s >> t;
    int a = 0, b = 0, p = 0, q = 0;
    for (auto &&i : s) {
        (i == '0' ? a : b)++;
    }
    for (auto &&i : t) {
        (i == '0' ? p : q)++;
    }
    if(a >= p && b >= q){
        a-=p, b-= q;
        cout << t;
    }
    vector<int> v(t.size());
    v[0] = t.size();
    for (int i = 1, j = 0; i < t.size() ;) {
        while (i+j < t.size() && t[j] == t[i+j]) ++j;
        v[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < t.size() && k+v[k] < j) v[i+k] = v[k], ++k;
        i += k; j -= k;
    }
    int ans = INF<int>;
    for (int i = 1; i < t.size(); ++i) {
        if(t.size() == v[i]+i) ans = min(ans, i);
    }
    string k;
    int d = 0, e = 0;
    for (int i = (ans == INF<int> ? 0 : t.size()-ans); i < t.size(); ++i) {
        (t[i] == '0' ? d : e)++;
        k += t[i];
    }
    while (a >= d && b >= e){
        a-=d, b-= e;
        cout << k;
    }
    for (int i = 0; i < a; ++i) {
        cout << '0';
    }
    for (int j = 0; j < b; ++j) {
        cout << '1';
    }
    cout << "\n";
    return 0;
}
