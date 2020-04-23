#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    vector<int> v(5, 0);
    string s = "MARCH";
    ll ans = 0;
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; ++i) {
        char a[15];
        scanf("%s", a);
        for (int j = 0 ; j < 5; ++j) {
            if(s[j] == a[0]) v[j]++;
        }
    }
    vector<int> v2 = {0, 0, 1, 1, 1};
    do{
        ll a = 1;
        for (int i = 0; i < 5; ++i) {
            if(v2[i]){
                a *= v[i];
            }
        }
        ans += a;
    }while (next_permutation(v2.begin(), v2.end()));
    cout << ans << "\n";
    return 0;
}
