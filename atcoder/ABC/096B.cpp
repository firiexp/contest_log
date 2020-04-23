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

int main(){
    vector<int> v(3);
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    sort(v.begin(), v.end());
    for (int i = 0; i < k; ++i) {
        v[2]*=2;
    }
    cout << v[0] + v[1] + v[2] << "\n";
    return 0;
}
