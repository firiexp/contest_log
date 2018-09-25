#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> visited(n, 0), link(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> link[i];
    }
    int k = 0, ans = 0;
    while(!visited[k]){
        visited[k] = 1;
        k = link[k] - 1;
        if(visited[1]) break;
        ans++;
    }
    cout << (visited[1] ? ans : -1) << "\n";
    return 0;
}
