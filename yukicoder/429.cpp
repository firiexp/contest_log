#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k, x;
    cin >> n >> k >> x; x--;
    vector<int> v(n);
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i+1;
    }
    for (int i = 0; i < k; ++i) {
        if(i > x){
            int a, b;
            scanf("%d %d", &a, &b);
            p.emplace_back(a-1, b-1);
        }else if(i < x){
            int a, b;
            scanf("%d %d", &a, &b);
            swap(v[a-1], v[b-1]);
        }else {
            string a, b;
            cin >> a >> b;
        }
    }
    reverse(p.begin(), p.end());
    vector<int> u(n);
    for (auto &&i : u) scanf("%d", &i);
    for (auto &&i : p) {
        swap(u[i.first], u[i.second]);
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if(v[i] != u[i]) a.emplace_back(i);
    }
    cout << a[0]+1 << " " << a[1]+1 << "\n";
    return 0;
}
