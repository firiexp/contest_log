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
    string s;
    cin >> s;
    int ans = 0;
    vector<int> v(3, 0);
    char joi[] = {'J', 'O', 'I', '?'};
    int cur = 0;
    for (auto &&i : s) {
        if(i == joi[cur]) v[cur]++;
        else if(i == joi[cur+1]) {
            cur++; v[cur]++;
        }else {
            if(v[0] >= v[1] && v[2] >= v[1]){
                ans = max(ans, v[1]);
            }
            fill(v.begin(), v.end(), 0);
            cur = 0;
            if(i == joi[cur]) v[cur]++;
        }
    }
    if(v[0] >= v[1] && v[2] >= v[1]){
        ans = max(ans, v[1]);
    }
    fill(v.begin(), v.end(), 0);
    cout << ans << "\n";
    return 0;
}
