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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    map<int, int> m;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v.emplace_back(a);
        m[a]++;
    }
    int x = 0, y = 0, z = 0;
    for (auto &&a : m) {
        if(a.second == 1){
            x++;
        }else if (a.second == 2){
            y++;
        }else {
            z++;
        }
    }
    if(x & 1 && z == 0){
        cout << "NO\n";
        return 0;
    }else cout << "YES\n";
    if (x & 1){
        bool flag = false, guuki = true;
        for (auto &&a : v) {
            if(m[a] == 1){
                if(guuki){
                    cout << "A";
                }else {
                    cout << "B";
                }
                guuki = !guuki;
            }else if(m[a] >= 3){
                if(!flag) cout << "B";
                else cout << "A";
                flag = true;
            }else cout << "A";
        }
    }else {
        bool guuki = true;
        for (auto &&a : v) {
            if(m[a] == 1){
                if(guuki){
                    cout << "A";
                }else {
                    cout << "B";
                }
                guuki = !guuki;
            }else {
                cout << "A";
            }
        }
    }
    cout << "\n";
    return 0;
}
