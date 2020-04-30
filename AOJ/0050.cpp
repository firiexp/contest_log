#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <sstream>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    getline(cin, s);
    string tmp;
    string A = "apple", B = "peach";
    for (auto &&i : s) {
        tmp += i;
        if(tmp.size() >= 5) {
            int okA = 1, okB = 1;
            for (int j = 0; j < 5; ++j) {
                if(tmp.end()[j-5] != A[j]) okA = 0;
                if(tmp.end()[j-5] != B[j]) okB = 0;
            }
            for (int j = 0; j < 5; ++j) {
                if(okA) tmp.end()[j-5] = B[j];
                if(okB) tmp.end()[j-5] = A[j];
            }
        }
    }
    cout << tmp << "\n";
    return 0;
}