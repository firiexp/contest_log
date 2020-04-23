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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

set<string> S;
void f(string &s){
    if(!S.count(s)){
        cout << s << "\n";
        exit(0);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        S.insert(x);
    }
    string s = "iaaeuu";
    string t = "nbmgr";
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    do {
        do {
            int cur1 = 0, cur2 = 0;
            string x;
            while(cur1 < s.size() || cur2 < t.size()){
                if(cur1 < s.size()) x += s[cur1], cur1++;
                if(cur2 < t.size()) x += t[cur2], cur2++;
            }
            f(x);
            for (int i = 0; i < 10; ++i) {
                swap(x[i], x[i+1]);
                f(x);
            }
        }while(next_permutation(s.begin(),s.end()));
    }while(next_permutation(t.begin(),t.end()));
    puts("NO");
    return 0;
}