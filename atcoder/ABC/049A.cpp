#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    string vowel = "aeiou";
    for(auto &a: vowel){
        if(a == c){
            cout << "vowel" << "\n";
            return 0;
        }
    }
    cout << "consonant" << "\n";
}