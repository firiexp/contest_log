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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

struct Node {
    int d, l, r;
    explicit Node(int d) : d(d), l(-1), r(-1){};
    Node() : d(0), l(-1), r(-1){};
};

int main() {
    ll n, l;
    cin >> n >> l;
    ll ans = 0;
    vector<Node> v;
    v.emplace_back();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int x = 0;
        for (auto &&j : s) {
            if(j == '0'){
                if(v[x].l == -1){
                    v[x].l = static_cast<int>(v.size());
                    v.emplace_back(v[x].d + 1);
                }
                x = v[x].l;
            }else {
                if(v[x].r == -1){
                    v[x].r = static_cast<int>(v.size());
                    v.emplace_back(v[x].d + 1);
                }
                x = v[x].r;
            }
        }
    }
    for (auto &i : v) {
        if((i.l == -1) + (i.r == -1) == 1){
            ans ^= (l- i.d)&(i.d-l);
        }
    }
    puts(ans ? "Alice":  "Bob");
    return 0;
}
