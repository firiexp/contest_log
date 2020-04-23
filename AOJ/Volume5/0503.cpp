#include <iostream>
#include <stack>
#include <queue>

using ll = long long;
using namespace std;
using P = pair<int, int>;

int move(int A,int B, int C){
    if(!A&&!B) return 0;
    if(C&1)return move(A>>1,B>>1, C>>1);
    if(B&1)return move(C>>1,B>>1, A>>1)+move((A|B|C )>>1, 0, 0) + 1;
    if(A&1)return move(A>>1,B>>1, C>>1)+ 2*move((A|B|C)>>1, 0,0)+ 2;
}

int main() {
    int n, m;
    while(cin>>n>>m, n || m){
        int cup[3] = {};
        for (int &i : cup) {
            int t;
            cin >> t;
            for (int j = 0; j < t; ++j) {
                int a;
                cin >> a;
                i += 1<<(a-1);
            }
        }
        int a = min(move(cup[0],cup[1], cup[2]),move(cup[2], cup[1], cup[0]));
        cout << (a<=m ? a : -1) << "\n";
    }
    return 0;
}
