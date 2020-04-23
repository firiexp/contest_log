#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int n, m, q, a, b, x;
    string s, t;
    vector<int> V;
    cin >> n >> m >> q >> s >> t;
    unsigned int p = t.length();
    for (unsigned int i = 0; i+p <= s.length(); ++i) {
        if(s.substr(i, p) == t) V.emplace_back(i);
    }
    sort(V.begin(), V.end());

    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &a, &b);
        auto fir= lower_bound(V.begin(), V.end(),a-1);
        auto las= upper_bound(V.begin(), V.end(),b-p)-1;

        if(fir <= las) x = distance(fir, las) + 1;
        else x = 0;

        printf("%d\n", x);
    }
    return 0;
}
