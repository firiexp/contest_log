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
    int n, m;
    cin >> n >> m;
    vector<queue<int>> q(n);
    vector<int> v(n, 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        q[a-1].emplace(b-1);
        q[b-1].emplace(a-1);
    }
    int x = 0, y = q[0].front(); q[0].pop();
    v[x] = 0, v[y] = 0;
    deque<int> ans;
    ans.emplace_front(x);
    ans.emplace_back(y);

    while(!q[x].empty() || !q[y].empty()){
        int x2 = x , y2 = y;
        if(!q[x].empty()){
            if(v[q[x].front()]) {
                x2 = q[x].front();
                v[x2] = 0;
                ans.emplace_front(x2);
            }
            q[x].pop();
        }
        if(!q[y].empty()){
            if(v[q[y].front()]){
                y2 = q[y].front();
                v[y2] = 0;
                ans.emplace_back(y2);
            }
            q[y].pop();
        }
        x = x2, y = y2;
    }
    int len = static_cast<int>(ans.size());
    cout << len << "\n";
    for (int i = 0; i < len; ++i) {
        if(i) printf(" ");
        printf("%d", ans.front()+1);
        ans.pop_front();
    }
    return 0;
}
