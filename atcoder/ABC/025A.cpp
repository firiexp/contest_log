#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    string s , ans;
    int n;
    int cnt = 0;
    cin >> s >> n;
    for (auto &&a : s) {
        for (auto &&b : s) {
            cnt++;
            if(cnt == n){
                ans = {a , b};
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
