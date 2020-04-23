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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    queue<int> v1, v2;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v1.emplace(k);
    }
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        v2.emplace(k);
    }
    ll turn = 0, t = 0;
    while(1){
        if(turn%2 == 0){
            if(v1.empty()) break;
            int k = v1.front(); v1.pop();
            while(k < t && !v1.empty()){
                k = v1.front(); v1.pop();
            }
            if(k < t) break;
            t = x + k;
            turn++;
        }else{
            if(v2.empty()) break;
            int k = v2.front(); v2.pop();
            while(k < t && !v2.empty()){
                k = v2.front(); v2.pop();
            }
            if(k < t) break;
            t = y + k;
            turn++;
        }
    }
    cout << turn/2 << "\n";
    return 0;
}
