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
    int n, c;
    cin >> n >> c;
    vector<int> v(n), S(n+1), Sr(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] == c) s++;
        S[i+1] = s;
    }
    s = 0;
    for (int i = n-1; i >= 0; --i) {
        if(v[i] == c) s++;
        S[i] = s;
    }
    int ans = 0;
    map<int, int> m;
    priority_queue<int> q;
    int l = 0, r = 0;
    q.push(v[0]);

    while(l != n-1 && r != n-1){

    }
    return 0;
}
