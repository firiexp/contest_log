#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>
static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
template <typename T>
using PQ = priority_queue<T>;

int main() {
    int n;
    cin >> n;
    PQ<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v.emplace(k);
    }
    int x = 0, w = 0;
    while (!v.empty()){
        int k = v.top(); v.pop();
        if(!w) x += k*k;
        else x -= k*k;
        w ^= 1;
    }
    cout << setprecision(15) << acos(-1.0)*x << "\n";
    return 0;
}
