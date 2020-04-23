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
    int n;
    string s;
    cin >> n;
    if(n < 60) s = "Bad";
    else if (n < 90) s = "Good";
    else if (n < 100) s = "Great";
    else s = "Perfect";
    cout << s << "\n";
    return 0;
}
