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
    int a;
    cin >> a;
    int k = 0;
    for (auto &&i : to_string(a)) k += i- '0';
    cout <<(a % k ? "No" : "Yes") << "\n";
    return 0;
}
