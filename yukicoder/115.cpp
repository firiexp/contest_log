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

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "}";
}

int main() {
    int n, d, k;
    cin >> n >> d >> k;
    if(n < k || d < k*(k+1)/2 || n*(n+1)/2-(n-k)*(n-k+1)/2 < d) {
        puts("-1");
        return 0;
    }
    vector<int> v(k+1);
    iota(v.begin(), v.end(), 1);
    v[k] = n+1;
    int sum = k*(k+1)/2, cur = k-1;
    while(sum < d){
        if(v[cur] >= v[cur+1]-1) cur--;
        v[cur]++;
        sum++;
    }
    for (int i = 0; i < k; ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
