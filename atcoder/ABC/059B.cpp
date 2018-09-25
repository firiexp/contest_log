#include <iostream>
#include <algorithm>
#include <vector>

static const int INF = 1000000007;
using ll = long long;
using namespace std;


int main() {
    string s, t;
    cin >> s >> t;
    if (s == t){
        cout << "EQUAL" << "\n";
        return 0;
    }
    if(s.length() < t.length()){
        cout << "LESS" << "\n";
        return 0;
    }else if (s.length() > t.length()){
        cout << "GREATER" << "\n";
        return 0;
    }else {
        for (int i = 0; i < s.length(); ++i) {
            if(s[i] > t[i]) {
                cout << "GREATER" << "\n";
                return 0;
            } else if (s[i] < t[i]){
                cout << "LESS" << "\n";
                return 0;
            }
        }
    }
    return 0;
}
