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
    vector<char> v(4);
    string A = "+-*";
    while(true){
        for (auto &&i : v) scanf(" %c", &i);
        if(v[0] == '0') break;
        auto solve = [&](string &s) -> string {
            stack<pair<string, int>> S;
            for (auto &&i : s) {
                if(isdigit(i)) S.emplace(string(1, i), i-'0');
                else if(i == '+'){
                    if(S.size() < 2) return {};
                    auto a = S.top(); S.pop();
                    auto b = S.top(); S.pop();
                    S.emplace("(" + a.first + "+" + b.first + ")", a.second+b.second);
                }else if(i == '*'){
                    if(S.size() < 2) return {};
                    auto a = S.top(); S.pop();
                    auto b = S.top(); S.pop();
                    S.emplace("(" + a.first + "*" + b.first + ")", a.second*b.second);
                }else if(i == '-'){
                    if(S.size() < 2) return {};
                    auto a = S.top(); S.pop();
                    auto b = S.top(); S.pop();
                    S.emplace("(" + a.first + "-" + b.first + ")", a.second-b.second);
                }
            }
            if(S.top().second != 10) return {};
            else return S.top().first;
        };
        int ok = 0;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) {
             string s = string(1, v[0])+v[1]+v[2]+v[3]+A[i]+A[j]+A[k];
             sort(s.begin(),s.end());
             do {
                 auto ret = solve(s);
                 if(!ret.empty()){
                     cout << ret << "\n";
                     i = j = k = 3;
                     ok = 1;
                     break;
                 }
             }while(next_permutation(s.begin(),s.end()));
        }
        if(!ok) puts("0");
    }
    return 0;
}