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

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i){
        int k;
        cin >> k;
        sum += k;
        v.emplace_back(k);
    }
    int ans = 0;
    if(sum % n) {cout << -1 << "\n"; return 0;}
    for (int i = 0; i < n; ++i) {
        if(v[i] != sum/n) {
            v[i+1] += v[i]-sum/n;
            v[i] = sum/n;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
