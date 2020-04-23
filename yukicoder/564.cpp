#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int h, n;
    cin >> h >> n;
    vector<int> v(n);
    for (int i = 0; i < n-1; ++i) cin >> v[i];
    v[n-1] = h;
    sort(v.begin(), v.end());
    string s = to_string(n-(lower_bound(v.begin(), v.end(), h) - v.begin()));
    if(s.back() == '1') s += "st";
    else if(s.back() == '2') s += "nd";
    else if(s.back() == '3') s += "rd";
    else s += "th";
    cout << s << "\n";
    return 0;
}
