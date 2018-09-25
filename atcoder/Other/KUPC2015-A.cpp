#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int t;
    int c = 0, time = 0;
    vector<int> v;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        v.clear();
        if(s.length()<5) {cout << "0\n"; continue;}
        for (unsigned int j = 0; j < s.length()-4; ++j) {
            if (s.substr(j, 5) == "kyoto") v.emplace_back(j);
            else if (s.substr(j, 5) == "tokyo") v.emplace_back(j);
        }
        c = 0, time = 0;
        for (auto &&a : v) {
            if(time <= a){
                c++;
                time = a+5;
            }
        }
        cout << c << "\n";
    }
    return 0;
}
