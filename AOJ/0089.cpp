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
    vector<vector<int>> v;
    string s;
    while(getline(cin, s)){
        stringstream ss;
        ss << s;
        string t;
        v.emplace_back();
        while(getline(ss, t, ',')){
            v.back().emplace_back(stoi(t));
        }
    }
    for (int i = 0; i+1 < v.size(); ++i) {
        if(v[i].size() < v[i+1].size()){
            for (int j = 0; j < v[i+1].size(); ++j) {
                int a = 0;
                if(j) a = max(a, v[i][j-1]);
                if(j+1 != v[i+1].size()) a = max(a, v[i][j]);
                v[i+1][j] += a;
            }
        }else {
            for (int j = 0; j < v[i+1].size(); ++j) {
                v[i+1][j] += max(v[i][j], v[i][j+1]);
            }
        }
    }
    cout << v.back().back() << "\n";
    return 0;
}