#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> vx, vy;
    for (int i = 0; i < a; ++i) {
        int k;
        cin >> k;
        vx.emplace_back(k);
    }
    for (int i = 0; i < b; ++i) {
        int k;
        cin >> k;
        vy.emplace_back(k);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    bool flag = false;
    for (int j = vx[a-1]+1; j <= vy[0]; ++j) {
        if(c < j && j <= d) flag = true;
    }
    cout << (flag ? "No War" : "War") << "\n";
    return 0;
}
