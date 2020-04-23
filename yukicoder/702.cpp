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

u32 x = 0, y = 1, z = 2, w = 3;
void generate() {
    u32 t = (x^(x<<11));
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main() {
    u32 seed; cin >> seed;
    vector<u32> v;
    x = seed;
    u32 l = 0, r = 0;
    for (int i = 0; i < 10000001; ++i) {
        generate();
        if(w < 2143000000) l++;
        else if(w < 2152000000) v.emplace_back(w);
    }
    nth_element(v.begin(),v.begin()+(5000000-l), v.end());
    cout << v[5000000-l] << "\n";
    return 0;
}