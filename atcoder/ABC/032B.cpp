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
    set<string> x;
    string s;
    int k;
    cin >> s >> k;
    if(s.length()>=k) for (int i = 0; i < s.length()-k+1; ++i) {
        x.insert(s.substr(i,k));
    }
    cout << x.size() << "\n";
    return 0;
}
