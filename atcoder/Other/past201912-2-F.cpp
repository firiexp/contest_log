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
    string s, t;
    cin >> s;
    vector<string> v;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if(isupper(s[i])){
            t += s[i]-'A'+'a';
            if(t.size() > 1){
                v.emplace_back(t);
                t.clear();
            }
        }else t += s[i];
    }
    sort(v.begin(),v.end());
    for (auto &&i : v) {
        i.front() += 'A' - 'a';
        i.back() += 'A' - 'a';
        cout << i;
    }
    puts("");
    return 0;
}