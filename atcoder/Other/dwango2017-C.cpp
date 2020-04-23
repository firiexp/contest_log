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
    int n;
    cin >> n;
    vector<deque<int>> v(4);
    vector<int> v2(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v2[i] = x;
        v[x-1].emplace_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v2[i]){
            ans++;
            v[v2[i]-1].pop_front();
            int p = v2[i];
            v2[i] = 0;
            for (int j = 2; j >= 0; --j) {
                while (!v[j].empty() && p + j+1 <= 4){
                    p += j+1;
                    v2[v[j].back()] = 0;
                    v[j].pop_back();
                }
            }
            v2[i] = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
