#include <iostream>
#include <vector>

using ll = long long;
using namespace std;


int main() {
    vector<int> v;
    char c;
    int a, b;
    while(cin >> c){
        if ('0' < c && c < '9') {
            v.emplace_back(int(c- '0'));
            continue;
        }
        if (c == '+'){
            a = v.back();
            b = v.back();
            v.emplace_back(a+b);
            continue;
        }
        if (c == '*'){
            a = v.back();
            b = v.back();
            v.emplace_back(a*b);
            continue;
        }
        if (c == '-'){
            a = v.back();
            b = v.back();
            v.emplace_back(a-b);
            continue;
        }
        cout << v.back();
        break;
    }
    return 0;
}