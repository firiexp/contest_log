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
#include <list>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    if(v.front() > v.back()){
        puts("No");
        return 0;
    }
    vector<int> ans;
    list<int> l(v.begin(),v.end());
    for(auto i = l.begin(); i != l.end(); ++i){
        while(true){
            auto j = next(i, 1);
            if(j != l.end() && next(j, 1) != l.end() && *i < *j && *l.begin() < *j){
                ans.emplace_back(*j);
                l.erase(j);
            }else break;
        }
    }
    l.reverse();
    if(!l.empty()){
        for(auto i = ++l.begin(); i != l.end(); ++i){
            ans.emplace_back(*i);
        }
    }
    puts("Yes");
    for (int i = 0; i < n-1; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}