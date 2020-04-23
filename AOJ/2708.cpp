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

int main() {
    string s;
    cin >> s;

    vector<string> v, v2;
    v.emplace_back(s);
    int ok = 1;
    while(ok){
        ok = 0;
        for (auto &&t : v) {
            if(t == "ABC"){
                puts("Yes");
                return 0;
            }
            int k = 0;
            for(char C = 'A'; C <= 'C'; ++C){
                string p;
                for (int i = 0; i < t.size(); ++i) {
                    if(i+2 < t.size() && t[i] == 'A' && t[i+1] == 'B' && t[i+2] == 'C') {
                        p += C; i += 2;
                        k = 1;
                    }
                    else p += t[i];
                }
                string q;
                for (char i : p) {
                    if(i == C) q += "ABC";
                    else q += i;
                }
                if(t == q) v2.emplace_back(p);
            }
            ok |= k;
        }
        v.clear();
        v2.swap(v);

    }
    puts("No");
    return 0;
}