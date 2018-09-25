#include <iostream>

using ll = long long;
using namespace std;


int main() {
    string w;
    cin >> w;
    for(int i = 0; i < w.size(); i++){
        int count = 0;
        for (int j = 0; j < w.size(); ++j) {
            if (w[i] == w[j]) count++;
        }
        if (count % 2 != 0){
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}