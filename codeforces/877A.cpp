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
    string s;
    cin >> s;
    vector<string> v{"Danil", "Olya", "Slava", "Ann", "Nikita"};
    vector<int> cnt(5);
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            if(s.substr(i, v[j].size()) == v[j]) cnt[j]++;
        }
    }
    if(accumulate(cnt.begin(),cnt.end(), 0) == 1){
        puts("YES");
    }else {
        puts("NO");
    }
    return 0;
}