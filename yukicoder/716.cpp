#include <iostream>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    vector<int> q;
    int n, a, min = 2000000000;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        q.emplace_back(a);
    }
    sort(q.begin(), q.end());
    for (int j = 0; j < n-1; ++j) {
        a = q[j+1]-q[j];
        if(a<min) min = a;
    }
    cout << min << "\n";
    cout << (q[n-1] - q[0]) << "\n";
    return 0;
}