#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

bool solve(string &s){
    stack<char> S;
    for (auto &&i : s) {
        if(i == '(' || i == '[') S.emplace(i);
        else if(i == ')' || i == ']'){
            if(S.empty()) return false;
            char c = S.top(); S.pop();
            if(i == ')' && c == '[') return false;
            if(i == ']' && c == '(') return false;
        }
    }
    return S.empty();
}

int main() {
    string s;
    while(getline(cin, s), s != "."){
        puts(solve(s) ? "yes" : "no");
    }
    return 0;
}
