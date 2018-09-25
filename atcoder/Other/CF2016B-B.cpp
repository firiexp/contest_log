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
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int aa = 0, bb = 0;
    for (auto &&x : s) {
        if(aa+bb+1 > a+b || (x == 'b' && bb+1 > b) || x == 'c') cout << "No" << "\n";
        else {cout << "Yes" << "\n"; if(x == 'a') aa++; else bb++;}
    }
    return 0;
}
