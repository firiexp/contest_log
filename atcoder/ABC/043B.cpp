#include <iostream>
using namespace std;

int main() {
    string s, ans;
    cin >> s;
    for(auto &a: s){
        if(a == 'B'){
            if(!ans.empty()) ans.pop_back();
            continue;
        }
        ans += a;
    }
    cout << ans;
}