#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using ll = long long;
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(10);
    vector<int> v2(k);
    set<string> S;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.begin() + n);
    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) == k) {
            int c = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    v2[c] = v[j];
                    c++;
                }
            }
            sort(v2.begin(), v2.end());
            do {
                string s;
                for (int &item : v2) {
                    s += to_string(item);
                }
                S.emplace(s);
            } while (next_permutation(v2.begin(), v2.end()));
        }
    }
    cout << S.size() << "\n";
    return 0;
}
