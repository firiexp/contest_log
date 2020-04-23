#include <iostream>
#include <queue>


using ll = long long;
using namespace std;
using P = pair<int, int>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ll n, k;
    cin >> n >> k;
    GPQ<P> pq;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        pq.emplace(a, b);
    }
    ll v = 0;
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        v += p.second;
        if(v >= k){
            cout << p.first << "\n";
            return 0;
        }
    }
    return 0;
}
