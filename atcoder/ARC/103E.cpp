
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    if(s[s.length()-1] == '1' || s[0] == '0'){
        cout << -1 << "\n";
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < s.length()-1; ++i) {
        if(s[i] != s[s.length()-i-2]) {
            cout << -1 << "\n";
            return 0;
        }else if(s[i] == '1'){
            v.emplace_back(i+1);
        }
    }
    int k = 1;
    for (int j = 0; j < v.size(); ++j) {
        cout << k << " " << k+1 << "\n";
        k++;
    }
    k++;
    for (int i = 1; i < v.size(); ++i) {
        for (int j = 0; j < v[i]-v[i-1]-1; ++j) {
            cout << i+1 << " " << k << "\n";
            k++;
        }
    }
    return 0;
}
