#include <iostream>
#include <string>
using namespace std;

int main(){
    string s[3];
    int a=0,b=0,c=0;
    int turn=0;
    cin >> s[0] >> s[1] >> s[2];
    while(true){
        if(turn==0){
            if(a>=s[0].size()){
                cout << "A" << "\n";
                return 0;
            }
            turn=s[0][a]-'a';
            a++;
        }
        if(turn==1){
            if(b>=s[1].size()){
                cout << "B" << "\n";
                return 0;
            }
            turn=s[1][b]-'a';
            b++;
        }
        if(turn==2){
            if(c>=s[2].size()){
                cout << "C" << "\n";
                return 0;
            }
            turn=s[2][c]-'a';
            c++;
        }
    }
}