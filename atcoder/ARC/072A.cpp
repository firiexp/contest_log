#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v.emplace_back(k);
    }

    partial_sum(v.begin(), v.end(), v.begin());

    ll p = 0, q = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        k ^= 1;
        if(k){
            if(v[i]+ p < 1){
                q += abs(1-v[i]-p);
                p = 1 -v[i];
            }
        }else{
            if(v[i]+ p > -1){
                q += abs(-1-v[i]-p);
                p = -1 -v[i];
            }
        }
    }
    ll q2 = q;
    k = 1, q = 0, p = 0;
    for (int i = 0; i < n; ++i) {
        k ^= 1;
        if(k){
            if(v[i]+ p < 1){
                q += abs(1-v[i]-p);
                p = 1 -v[i];
            }
        }else{
            if(v[i]+ p > -1){
                q += abs(-1-v[i]-p);
                p = -1 -v[i];
            }
        }
    }
    cout << min(q, q2) << "\n";

    return 0;
}
