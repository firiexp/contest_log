#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    string s;
    cin >> s;
    bool allchecked = false;
    int pp = 0;
    vector<int> checked(s.length(), 0);
    for (int i = 0; i < s.length(); ++i) {
        auto a = s[i];
        if(!checked[i] && a == 'g') {
            if(!pp) pp = i+1;
            for (int j = pp; j < s.length(); ++j) {
                if(s[j] == 'p' && !checked[j]){
                    checked[i] = 1;
                    checked[j] = 1;
                    pp = j+1;
                    break;
                }
                if(j == s.length()-1) allchecked = true;
            }
        }
        if(allchecked) break;
    }
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(!checked[i]){
            if(s[i] == 'g') a++;
            else b++;
        }
    }
    cout << a/2-b << "\n";
    return 0;
}
