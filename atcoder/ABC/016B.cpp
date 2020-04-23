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
    int a, b, c, p = 0, q = 0;
    cin >> a >> b >> c;
    if(a+b == c) p^=1;
    if(a-b == c) q^=1;
    if(p&&q) cout << "?\n";
    else if(p&&!q) cout << "+\n";
    else if(!p&&q) cout << "-\n";
    else cout << "!\n";
    return 0;
}
