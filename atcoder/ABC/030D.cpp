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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n, a; string k;
    cin >> n >> a >> k; a--;
    int b = a;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    map<int, int> x; vector<int> u;
    int cnt = 1;
    while(!x[b]) x[b] = cnt++, u.emplace_back(b+1), b = v[b];
    int loops = cnt-x[b], offset = x[b];

    if(k.size() < 10){
        ll y = stoll(k);
        if(y+1 < offset){
            cout << u[y] << "\n";
        }else {
            cout << u[((y-offset+1)%loops+loops)%loops+offset-1] << "\n";
        }
    }else {
        ll y = 0;
        int cur = 0;
        while(cur < k.size()) y = (10*y+k[cur++]-'0')%loops;
        cout << u[((y-offset+1)%loops+loops)%loops+offset-1] << "\n";
    }
    return 0;
}