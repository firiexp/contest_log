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
    int gx, gy;
    cin >> s >> gx >> gy;
    vector<char> v{'W', 'X', 'Y', 'Z'};
    do {
        int x = 0, y = 0;
        if(x == gx && y == gy){
            puts("Yes");
            return 0;
        }
        for (auto &&i : s) {
            if(i == v[0]) x--;
            else if(i == v[1]) x++;
            else if(i == v[2]) y++;
            else y--;
            if(x == gx && y == gy){
                puts("Yes");
                return 0;
            }
        }
    } while(next_permutation(v.begin(), v.end()));
    puts("No");
    return 0;
}
