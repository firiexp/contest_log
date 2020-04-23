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

vector<bool> get_prime(int n) {
    if(n <= 1) return vector<bool>(n+1, 1);
    vector<bool> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]){
            for (int j = i*2; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    return is_prime;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto p = get_prime(3*n);
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] == 1) a++;
        else b++;
    }
    p[0] = p[1] = 0;
    int cur = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if((!p[cur+1] && b)|| !a) {
            b--;
            cur += 2;
            ans.emplace_back(2);
        }else {
            a--;
            cur += 1;
            ans.emplace_back(1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}