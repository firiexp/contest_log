#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int m;
    while(cin >> m, m) {
        vector<pair<int, int>> v;
        for (int i = 0; i < m; ++i) {
            int id;
            cin >> id;
            int ans = 0, one = 0, two = 0;
            for (int j = 0; j < 9; ++j) {
                int x;
                cin >> x;
                ans += x*(!!one+!!two+1);
                one = two; two = 0;
                if(x == 10) two++;
                else {
                    int y;
                    cin >> y;
                    ans += y*(!!one+!!two+1);
                    one = two; two = 0;
                    if(x+y == 10) one++;
                }
            }
            int x, y;
            cin >> x >> y;
            ans += x*(!!one+!!two+1);
            one = two; two = 0;
            ans += y*(!!one+!!two+1);
            one = two; two = 0;
            if(x == 10 || x+y == 10){
                int z;
                cin >> z;
                ans += z*(!!one+!!two+1);
            }
            v.emplace_back(ans, -id);
        }
        sort(v.begin(),v.end(), greater<>());
        for (auto &&k : v) {
            cout << -k.second << " " << k.first << "\n";
        }
    }
    return 0;
}