#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

vector<bool> get_prime(int n) {
    if(n <= 1) return vector<bool>{false, false};
    vector<bool> prime(static_cast<unsigned int>(n + 1), true);
    prime[0] = false; prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]) for(int j = i << 1; j <= n; j += i) prime[j] = false;
    }
    return(prime);
}

int main() {
    vector<int> v;
    auto a = get_prime(55555);
    for (int i = 11; i <= 55551; i += 10) {
        if(a[i]) v.emplace_back(i);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
