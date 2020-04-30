#include <iostream>
#include <algorithm>
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
    vector<string> v{"light fly", "fly", "bantam", "feather", "light", "light welter", "welter", "light middle", "middle", "light heavy", "heavy"};
    vector<int> a{48, 51, 54, 57, 60, 64, 69, 75, 81, 91, 999999};
    double x;
    while(cin >> x){
        for (int i = 0; i < v.size(); ++i) {
            if(x <= a[i]){
                cout << v[i] << "\n";
                break;
            }
        }
    }
    return 0;
}