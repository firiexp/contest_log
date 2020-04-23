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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> l, r;
    l.reserve(n);
    r.reserve(n);
    for (int i = 0; i < n; ++i) {
        r.emplace_back(0);
    }
    vector<int> suml(n+1), sumr(n+1), minl(n+1), minr(n+1), maxl(n+1), maxr(n+1);

    l.emplace_back(0);
    int lcur = l.size()-1, rcur = r.size()-1;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'R') {
            lcur++; rcur--;
            l.emplace_back(-r.back());
            r.pop_back();
        }
        else if(s[i] == 'L') {
            if(lcur != 0){
                lcur--; rcur++;
                r.emplace_back(-l.back());
                l.pop_back();
                sumr[rcur+1] = sumr[rcur] + r.back();
                minr[rcur+1] = min(minr[rcur], sumr[rcur+1]);
                maxr[rcur+1] = max(maxr[rcur], sumr[rcur+1]);
            }
        } else if(s[i] == '('){
            l.back() = 1;
        } else if(s[i] == ')'){
            l.back() = -1;
        } else {
            l.back() = 0;
        }
        suml[lcur+1] = suml[lcur] + l.back();
        minl[lcur+1] = min(minl[lcur], suml[lcur+1]);
        maxl[lcur+1] = max(maxl[lcur], suml[lcur+1]);

        if(i) printf(" ");
        if(suml[lcur+1] - sumr[rcur+1] != 0) printf("-1");
        else if(minl[lcur+1] < 0 || minr[rcur+1] < 0) printf("-1");
        else printf("%d", max(maxl[lcur+1], maxr[rcur+1]));
    }
    puts("");

    return 0;
}