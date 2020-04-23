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
    while(getline(cin, s)){
        stringstream in;
        in << s;
        stack<double> S;
        while(!in.eof()){
            string x;
            in >> x;
            if(x == "+" || x == "*" || x == "/" || x == "-"){
                double b = S.top(); S.pop(); double a = S.top(); S.pop();
                if(x == "+") S.emplace(a+b);
                else if(x == "*") S.emplace(a*b);
                else if(x == "/") S.emplace(a/b);
                else S.emplace(a-b);
            }else {
                S.emplace(stod(x));
            }
        }
        printf("%.10lf\n", S.top());
    }
    return 0;
}