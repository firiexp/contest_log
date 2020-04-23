#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;


int main() {
    int n,q, t;
    string name;
    queue<pair<string, int> > Q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps = 0, a;

    while(!Q.empty()){
        u = Q.front(); Q.pop();
    }

    return 0;
}