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
    int k, n;
    cin >> k >> n;
    auto v = get_prime(n);
    vector<int> h(v);
    for (auto &&i : h) {
        while(i > 9){
            int a = 0;
            while(i){
                a += i%10;
                i /= 10;
            }
            i = a;
        }
    }
    int l = 0, r = 0;
    while(v[l] < k) l++, r++;
    vector<int> cnt(10);
    int ans = 0, ans2 = 0;
    while(r < v.size()){
        cnt[h[r]]++;

        while(cnt[h[r]] > 1){
            cnt[h[l]]--;
            l++;
        }
        r++;
        if(ans <= r-l){
            ans = r-l;
            ans2 = v[l];
        }
    }
    cout << ans2 << "\n";
    return 0;
}