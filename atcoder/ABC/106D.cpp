#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;
static const int INF = 1000000000;


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v (600, 0);
    vector<vector<int>> p(300001, vector<int>(3, INF));
    vector<int> ans(300000);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        vector<int> e {r*2+2, l, -1};
        p.emplace_back(e);
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        vector<int> e {r*2+3, l, i};
        p.emplace_back(e);
    }
    sort(p.begin(), p.end());
    for (auto &&a: p){
        if(a[0] == INF) break;
        if(a[0]%2 == 0){
            v[a[1]]++;
        }else{
            int sum = 0;
            for (int i = a[1]; i <= a[0]/2; ++i) {
                sum += v[i];
            }
            ans[a[2]] = sum;
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
