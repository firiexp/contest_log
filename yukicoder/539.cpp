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
    int t;
    cin >> t;
    string s;
    cin.ignore();
    for (int q = 0; q < t; ++q) {
        getline(cin, s);
        s += (isdigit(s.back()) ? "a" : "1");
        vector<string> v;
        string tmp;
        for (int i = 0; i+1 < s.size(); ++i) {
            tmp += s[i];
            if(isdigit(s[i]) != isdigit(s[i+1])){
                v.emplace_back(tmp);
                tmp.clear();
            }
        }
        for (int i = (int)v.size()-1; i >= 0; --i) {
            if(isdigit(v[i].front())){
                int cur = (int)v[i].size()-1;
                v[i].back()++;
                while(cur > 0 && v[i][cur] > '9'){
                    v[i][cur-1]++;
                    v[i][cur] = '0';
                    cur--;
                }
                if(v[i][cur] > '9'){
                    v[i] = "1" + string(v[i].size(), '0');
                }
                break;
            }
        }
        for (auto &&i : v) cout << i;
        puts("");
    }
    return 0;
}