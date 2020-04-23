#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int sl = s.length(), tl = t.length();
    int c = -1;
    for (int i = sl-tl; i >= 0; --i) {
        bool f = true;
        for (int j = 0; j < tl; ++j) {
            if(s[i+j] != t[j] && s[i+j] != '?') f = false;
        }
        if(f) {c = i; break;}
    }
    if(c >= 0){
        s.replace(c, tl, t);
        replace(s.begin(), s.end(), '?', 'a');
        cout << s << "\n";
    }else{
        cout << "UNRESTORABLE\n";
    }
    return 0;
}
