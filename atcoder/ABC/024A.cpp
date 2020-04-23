#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int a, b, c, k, s, t;
    cin >> a >> b >> c >> k >> s >> t;
    if(s + t >= k) a-=c, b-=c;
    cout << (a * s + b *t) << "\n";
    return 0;
}
