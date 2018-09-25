#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    vector<int> v(8);
    for (int i = 0; i < 8; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[7] << "\n";
    return 0;
}
