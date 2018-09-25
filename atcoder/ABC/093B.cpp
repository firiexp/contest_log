#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    set<int> v;
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = a; i <= a+k-1; ++i) {
        if(i > b) break;
        else v.insert(i);
    }
    for (int j = b; j >= b-k+1; --j) {
        if(j < a) break;
        else v.insert(j);
    }
    for (auto &&x : v) {
        cout << x << "\n";
    }
    return 0;
}
