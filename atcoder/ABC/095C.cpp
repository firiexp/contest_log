#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;



int main() {
    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;
    int t = max(x, y), u = min(x, y);
    vector<int> s(3);
    s[0] = x * a + y * b;
    s[1] = (x-u) * a + (y-u) * b + 2*u * ab;
    s[2] = 2 * t * ab;
    sort(s.begin(), s.end());
    cout << s[0] << "\n";
    return 0;
}
