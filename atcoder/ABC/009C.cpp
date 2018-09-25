#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using ll = long long;
using namespace std;

int counts(string s, char c){
    int i = 0;
    for (char &d : s) {
        i += c == d;
    }
    return i;
}

int main() {
    int n, k;
    string s, t;
    vector<char> v;
    cin >> n >> k >> s;
    for (char &c: s){
        v.emplace_back(c);
    }
    sort(v.begin(), v.end());
    while(t.length() != s.length()) {
        string s2 = s.substr(0, t.length()+1);
        for (char &c : v) {
            if(c < 'a' || 'z' < c) continue;
            int count = n - t.length() - 1;
            string t2 = t + c;
            for (int j = 0; j < t2.length(); ++j) {
                if(s2[j] != t2[j]) count++;
            }
            for(char d = 'a'; d <= 'z'; d++){
                count -= min(counts(s, d) - counts(s2, d), counts(s, d) - counts(t2,d));
            }
            if(count <= k){
                t = t2;
                c = ' ';
                break;
            }
        }
    }cout << t << "\n";
    return 0;
}
