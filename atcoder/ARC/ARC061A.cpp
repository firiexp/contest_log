#include <iostream>
#include <deque>

using ll = long long;
using namespace std;

int main() {
    string s;
    int prev;
    cin >> s;
    ll ans = stoll(s);
    int n = s.size()-1;
    for (int i = 0; i < (1 << n); ++i) {
        deque<int> S;
        prev = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) S.emplace_back(j);
        }
        bool a = S.empty();
        while(!S.empty()) {
            int k = S.front(); S.pop_front();
            ans += stoll(s.substr(prev, k - prev + 1));
            prev = k+1;
        }
        if((prev != n+1) && !a){
            ans += stoll(s.substr(prev, n - prev + 2));
        }

    }
    cout << ans << "\n";

    return 0;
}
