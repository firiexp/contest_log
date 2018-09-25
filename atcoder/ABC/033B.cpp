#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
template <typename T>
using PQ = priority_queue<T>;

int main() {
    int n;
    cin >> n;
    PQ<pair<int, string>> Q;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        int p;
        cin >> s >> p;
        Q.emplace(p, s);
        sum += p;
    }
    if(Q.top().first * 2 > sum) cout << Q.top().second << "\n";
    else cout << "atcoder\n";
    return 0;
}
