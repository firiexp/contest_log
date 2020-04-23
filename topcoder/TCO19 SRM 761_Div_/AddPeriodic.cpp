#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>
#include <bitset>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <fstream>
static const int MOD = 1000000007;
using u32 = unsigned;
using namespace std;

using ll = long long;

class AddPeriodic {
    public:

    pair<ll, ll> parse(string &A){
        ll p = 0, q = 1;
        int cur = 0;
        while(A[cur] != '.'){
            p *= 10;
            p += A[cur]-'0';
            cur++;
        }
        cur++;
        while(A[cur] != '('){
            p *= 10, q *= 10;
            p += A[cur]-'0';
            cur++;
        }
        cur++;
        ll r = 0, s = q, k = 1;
        while(A[cur] != ')'){
            r *= 10; k *= 10;
            r += A[cur] - '0';
            cur++;
        }
        k--;
        s *= k;
        p = p*s+q*r; q = q*s;
        ll g = __gcd(p, q);
        p /= g; q /= g;
        return make_pair(p, q);
    }

    using P = pair<ll, ll>;
    P add(P x, P y){
        ll p = x.first*y.second+x.second*y.first, q = x.second*y.second;
        ll g = __gcd(p, q);
        p /= g; q /= g;
        return make_pair(p, q);
    }

    string add(string A, string B) {
        auto x = add(parse(A), parse(B));
        string ans = to_string(x.first/x.second);
        x.first %= x.second;
        ans += ".";
        for (int i = 0; i < 300; ++i) {
            if(x.first == 0) continue;
            x.first *= 10;
            ans += to_string(x.first/x.second);
            x.first %= x.second;
        }
        if(ans.size() <= 50){
            ans += "(0)";
            return ans;
        }
        int cur = 0;
        string anss;
        while(ans[cur] != '.') {
            anss += ans[cur];
            cur++;
        }
        anss += ".";
        cur++;
        for (int i = cur; i <= 25; ++i) {
            for (int len = 1; len <= 25; ++len) {
                int ok = 1;
                for (int j = 0; j < 5; ++j) {
                    if(ans.substr(i+len*j, len) != ans.substr(i+len*(j+1), len)){
                        ok = 0;
                    }
                }
                if(ok){
                    anss += "(";
                    anss += ans.substr(i, len);
                    anss += ")";
                    return anss;
                }
            }
            anss += ans[i];
        }
        return ans;
    }
};

// CUT begin
ifstream data("AddPeriodic.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string A, string B, string __expected) {
    time_t startClock = clock();
    AddPeriodic *instance = new AddPeriodic();
    string __result = instance->add(A, B);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string A;
        from_stream(A);
        string B;
        from_stream(B);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1561215586;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "AddPeriodic (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
