#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;

bool Compare(pair<int,int>a, pair<int, int> b){
    return a.second < b.second;
};

priority_queue<pair<int, int>,vector<pair<int, int>>, greater<> > q;

int main() {
    int n, m, count = 0, maximum = 0, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        q.push(make_pair(y,x));
    }
    while (!q.empty()){
        x = q.top().first, y = q.top().second; q.pop();
        if(y >= maximum){
            maximum = x;
            count++;
        }
    }
    cout << count << "\n";
}