#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s, a = "bdpq";
    cin >> s;
    auto t = s;
    reverse(t.begin(),t.end());
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if(t[i] == a[j]){
                t[i] = a[j^1];
                break;
            }
        }
    }
    puts(s == t ? "Yes" : "No");
    return 0;
}