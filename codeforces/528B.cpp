#include <iostream>
#include <queue>

using ll = long long;
using namespace std;
using P = pair<int, int>;
int main() {
    int n, x, w;
    cin >> n;
    priority_queue<P, vector<P>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> x >> w;
        pq.emplace(x+w, x-w);
    }
    int time = -1234567890, c = 0;
    while (!pq.empty()){
        P a = pq.top(); pq.pop();
        if(time <= a.second){
            c++;
            time = a.first;
        }
    }
    cout << c << "\n";
    return 0;
}
