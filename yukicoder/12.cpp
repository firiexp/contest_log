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

vector<int> get_prime(int n){
    if(n <= 1) return vector<int>();
    vector<bool> is_prime(n+1, true);
    vector<int> prime;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j > n) break;
            is_prime[i*j] = false;
            if(i % j == 0) break;
        }
    }
    return prime;
}


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n;
    cin >> n;
    vector<int> num(10);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        num[x] = 1;
    }
    auto v = get_prime(5000000);
    n = v.size();
    vector<int> ngs;
    ngs.emplace_back(-1);
    for (int i = 0; i < n; ++i) {
        int x = v[i];
        int ok = 1;
        while(x){
            if(!num[x%10]) ok = 0;
            x /= 10;
        }
        if(!ok) ngs.emplace_back(i);
    }
    ngs.emplace_back(n);
    int ans = 0;
    for (int i = 0; i+1 < ngs.size(); ++i) {
        vector<int> cnt(10);
        for (int j = ngs[i]+1; j < ngs[i+1]; ++j) {
            int x = v[j];
            while(x){
                cnt[x%10]++;
                x /= 10;
            }
        }
        int ok = 1;
        for (int j = 0; j < 10; ++j) {
            if(num[j] && !cnt[j]) ok = 0;
        }
        int l = (ngs[i] == -1 ? 1 : v[ngs[i]]+1);
        int r = (ngs[i+1] == n ? 5000000: v[ngs[i+1]]-1);
        if(ok){
            ans = max(ans, r-l);
        }
    }
    cout << (ans == 0 ? -1 : ans) << "\n";
    return 0;
}