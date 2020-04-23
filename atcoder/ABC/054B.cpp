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
    u32 n, m;
    cin >> n >> m;
    vector<string> v1(n), v2(m);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> v2[j];
    }
    for (u32 i = 0; i < n-m+1; ++i) {
        for (u32 j = 0; j < n-m+1; ++j) {
            int a = 1;
            for (int k = 0; k < m; ++k) {
                if(v1[i+k].substr(j, m) != v2[k]){
                    a = 0;
                    break;
                }
            }
            if(a){
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }
    cout << "No" << "\n";
    return 0;
}
