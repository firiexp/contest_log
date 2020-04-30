#include <iostream>
#include <algorithm>
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
    array<int, 256> v{};
    string s;
    while(cin >> s) {
        if(s[s.size()-2] != ',') v[2]++;
        else if(s.back() == 'A') v[0]++;
        else if(s.back() == 'B') v[1]++;
        else if(s.back() == 'O') v[3]++;
    }
    printf("%d\n%d\n%d\n%d\n", v[0], v[1], v[2], v[3]);
    return 0;
}