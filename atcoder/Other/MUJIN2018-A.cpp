#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    cout <<  ( (s.substr(0, 5) == "MUJIN") ? "Yes" : "No" ) << "\n";
    return 0;
}
