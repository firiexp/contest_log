#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;



int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= 15000; ++i){
        for (int j = 2; j <= 5; ++j) {
            if(i*j <= 30000) v.emplace_back(i*j);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int s = 0;
    for (int i = 0; i < n-2; ++i) {
        if(i) printf(" ");
        printf("%d", v[i]);
        s += v[i];
    }
    for (int i = n-2; i < v.size(); ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            if((s + v[i]+v[j])%30 == 0) {
                printf(" %d %d\n", v[i], v[j]);
                i = j = v.size();
            }
        }
    }
    return 0;
}
