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
    int t;
    cin >> t; cin.ignore();
    string s;
    while(t--){
        getline(cin, s);
        [&](){
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    string a = s;
                    for (auto &&k : a) {
                        if(isalpha(k)) k = ((k-'a')*i+j)%26+'a';
                    }
                    if(a.find("this") != string::npos || a.find("that") != string::npos){
                        cout << a << "\n";
                        return;
                    }
                }
            }
        }();
    }
    return 0;
}