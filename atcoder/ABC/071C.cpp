#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;
template <typename T>
using PQ = priority_queue<T>;

int main() {
    int n;
    PQ<ll> q;
    q.push(0); q.push(0);
    cin >> n;
    map<ll, int> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x]++;
        if(m[x]%2 == 0){
             q.push(x);
        }
    }
    ll a = q.top(); q.pop();
    ll b = q.top(); q.pop();
    cout << a * b << "\n";
    return 0;
}
