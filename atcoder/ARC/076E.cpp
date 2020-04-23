#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a, b, p, q;
        scanf("%d%d%d%d", &a, &b, &p, &q);
        if(((a == 0 || a == r) || (b == 0 || b == c)) && ((p == 0 || p == r) || (q == 0 || q == c))){
            int d = 0;
            if(b == 0) d = a;
            else if (a == r) d = r+b;
            else if (b == c) d = 2*r+c-a;
            else if (a == 0) d = 2*r+2*c-b;
            v.emplace_back(d, i);
            d = 0;
            if(q == 0) d = p;
            else if (p == r) d = r+q;
            else if (q == c) d = 2*r+c-p;
            else if (p == 0) d = 2*r+2*c-q;
            v.emplace_back(d, i);
        }
    }
    if(v.empty()) {
        puts("YES");
        return 0;
    }
    sort(v.begin(), v.end());
    deque<int> dq;
    for (auto &i : v) {
        if(!dq.empty() && dq.back() == i.second) dq.pop_back();
        else dq.emplace_back(i.second);
    }
    while(!dq.empty() && dq.front() == dq.back()){
        dq.pop_front(); dq.pop_back();
    }
    puts(dq.empty() ? "YES" : "NO");
    return 0;
}
