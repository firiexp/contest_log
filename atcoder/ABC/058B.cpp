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
    string o, e, ans;
    cin >> o >> e;
    for (int i = 0; i < o.length(); ++i) {
        if(o[i] != '\0'){
            ans += o[i];
        }
        if(e[i] != '\0'){
            ans += e[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
