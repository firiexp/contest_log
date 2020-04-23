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
    string s;
    map<char, int> m;
    cin >> s;
    for (auto &&a : s) if(!m[a]) m[a]++;
    if(!(m['N']^m['S']) && !(m['W']^m['E'])) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}
