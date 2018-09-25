#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ll N, x, cnt = 0;
    cin >> N >> x;
    vector<ll> v;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        v.emplace_back(b);
    }
    if(v[0] > x) {
        cnt += v[0] - x;
    }
    for (int i = 0; i < N - 1; ++i) {
        if(v[i]+v[i+1] > x) {
            cnt += min(v[i+1], v[i]+v[i+1]-x);
            v[i+1] -= min(v[i+1], v[i]+v[i+1]-x);

        }
    }

    cout << cnt << "\n";
    return 0;
}
