#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    vector<int> days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> days2(13);
    int s = 0;
    for (int i = 0; i < 12; ++i) {
        s += days[i];
        days2[i+1] = s;
    }
    vector<int> isholiday(444, 0);
    for (int i = 0; i < 366; ++i) {
        if(i%7 == 0 || i%7 == 6) isholiday[i] = 1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d/%d", &a, &b);
        for (int j = days2[a-1]+b-1; j < 366; ++j) {
            if(!isholiday[j]) {
                isholiday[j]= true;
                break;
            }
        }
    }
    int ans = 0, no = 0;
    for (int i = 0; i < 367; ++i) {
        if(isholiday[i]) no++;
        else ans = max(ans, no), no = 0;
    }
    cout << ans << "\n";
    return 0;
}
