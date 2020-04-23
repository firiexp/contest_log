#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

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
    auto prime_list = get_prime(100001);
    vector<int> d(100001, 0);
    int k = 0;
    for (int i = 0; i <= 100000; ++i) {
        if(prime_list[i] && prime_list[(i+1)/2]) k++;
        d[i] = k;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        cout << d[r]-d[l-1] << "\n";
    }
    return 0;
}
