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
    string a, b;
    cin >> a >> b;
    int k = stoi((a+b));
    for (int i = 0; i*i <= k; ++i) {
        if(k == i*i){
            cout << "Yes" << "\n";
            return 0;
        }
    }
    cout << "No" << "\n";
    return 0;
}
