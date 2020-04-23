#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    map<char, string> m;
    map<string, char> minv;
    m[' '] = "101";
    m['\''] = "000000";
    m[','] = "000011";
    m['-'] = "10010001";
    m['.'] = "010001";
    m['?'] = "000001";
    m['A'] = "100101";
    m['B'] = "10011010";
    m['C'] = "0101";
    m['D'] = "0001";
    m['E'] = "110";
    m['F'] = "01001";
    m['G'] = "10011011";
    m['H'] = "010000";
    m['I'] = "0111";
    m['J'] = "10011000";
    m['K'] = "0110";
    m['L'] = "00100";
    m['M'] = "10011001";
    m['N'] = "10011110";
    m['O'] = "00101";
    m['P'] = "111";
    m['Q'] = "10011111";
    m['R'] = "1000";
    m['S'] = "00110";
    m['T'] = "00111";
    m['U'] = "10011100";
    m['V'] = "10011101";
    m['W'] = "000010";
    m['X'] = "10010010";
    m['Y'] = "10010011";
    m['Z'] = "10010000";
    minv["00000"] = 'A';
    minv["00001"] = 'B';
    minv["00010"] = 'C';
    minv["00011"] = 'D';
    minv["00100"] = 'E';
    minv["00101"] = 'F';
    minv["00110"] = 'G';
    minv["00111"] = 'H';
    minv["01000"] = 'I';
    minv["01001"] = 'J';
    minv["01010"] = 'K';
    minv["01011"] = 'L';
    minv["01100"] = 'M';
    minv["01101"] = 'N';
    minv["01110"] = 'O';
    minv["01111"] = 'P';
    minv["10000"] = 'Q';
    minv["10001"] = 'R';
    minv["10010"] = 'S';
    minv["10011"] = 'T';
    minv["10100"] = 'U';
    minv["10101"] = 'V';
    minv["10110"] = 'W';
    minv["10111"] = 'X';
    minv["11000"] = 'Y';
    minv["11001"] = 'Z';
    minv["11010"] = ' ';
    minv["11011"] = '.';
    minv["11100"] = ',';
    minv["11101"] = '-';
    minv["11110"] = '\'';
    minv["11111"] = '?';
    string s;
    while(getline(cin, s)){
        string t;
        for (auto &&i : s) t += m[i];
        while(t.size()%5) t += '0';
        string ans;
        for (int i = 0; i < t.size(); i += 5) {
            cout << minv[t.substr(i, 5)];
        }
        puts("");

    }
    return 0;
}