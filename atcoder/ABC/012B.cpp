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

int main() {
    int t;
    cin >> t;
    int p, q;
    p = t/3600;
    t -= p * 3600;
    q = t/60;
    t -= q * 60;
    printf("%02d:%02d:%02d", p, q, t);
    return 0;
}
