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
    int a, b, c, a1 = 1, b1 = 1, c1 = 1;
    cin >> a >> b >> c;
    if(a < b) a1++;
    else b1++;
    if(b < c) b1++;
    else c1++;
    if(c < a) c1++;
    else a1++;
    printf("%d\n%d\n%d\n", a1, b1, c1);
    return 0;
}
