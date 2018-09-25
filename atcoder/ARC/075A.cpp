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
    int n;
    vector<int> v(15001, 0);
    cin >> n;
    v[0] = 1;
    int p = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = p; j >= 0; --j) {
            if(v[j]) v[j+k]++;
        }
        p += k;
    }
    for (int i = p; i >= 0; --i) {
        if(v[i]>0 && i%10 != 0){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
