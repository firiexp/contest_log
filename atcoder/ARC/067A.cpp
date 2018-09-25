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

map<int, int> prime_factor(int n, map<int, int> &ret)
{
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n]++;
    return(ret);
}
int main() {
    int n;
    cin >> n;
    map<int, int> p;
    for (int i = 2; i <= n; ++i) {
        prime_factor(i, p);
    }
    ll ans = 1;
    for (auto &&x : p) {
        ans = (ans * (x.second+1)) % INF;
    }
    cout << ans << "\n";
    return 0;
}
