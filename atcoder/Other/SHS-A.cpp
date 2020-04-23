#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a + b == 15) {
        cout << "+\n";
        return 0;
    }
    if(a * b == 15){
        cout << "*\n";
        return 0;
    }
    cout << "x\n";
}