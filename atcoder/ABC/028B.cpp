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
    cin >> s;
    for (int i = 'A'; i < 'G'; ++i) {
        cout << count(s.begin(), s.end(), i);
        if(i != 'F') cout << " ";
        else cout << "\n";
    }
    return 0;
}
