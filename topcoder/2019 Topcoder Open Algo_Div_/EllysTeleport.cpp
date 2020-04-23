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
static const ll INF = (ll)MOD*MOD;

class EllysTeleport {
    public:
    int getMax(int N, int H1, int A, int B, int P, int Q, int M) {
        vector<ll> v(N);
        v[0] = H1;
        for (int i = 1; i < N; ++i) {
            v[i] = (v[i-1]*A+B)%M;
        }
        sort(v.begin(),v.end());
        vector<ll> to(N);
        for (int i = 0; i < N; ++i) {
            ll t = (v[i]*P+Q) % M;
            if(t < v[0]) to[i] = -1;
            else {
                ll p = upper_bound(v.begin(),v.end(), t)-v.begin()-1;
                to[i] = p;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            vector<int> visited(N);
            int cur = i, move = 0;
            while(!visited[cur]){
                visited[cur] = 1;
                move++;
                if(to[cur] == -1) break;
                cur = to[cur];
            }
            ans = max(ans, move);
        }
        return ans;
    }
};

// CUT begin
ifstream data("EllysTeleport.sample");

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

bool do_test(int N, int H1, int A, int B, int P, int Q, int M, int __expected) {
    time_t startClock = clock();
    EllysTeleport *instance = new EllysTeleport();
    int __result = instance->getMax(N, H1, A, B, P, Q, M);
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
        int N;
        from_stream(N);
        int H1;
        from_stream(H1);
        int A;
        from_stream(A);
        int B;
        from_stream(B);
        int P;
        from_stream(P);
        int Q;
        from_stream(Q);
        int M;
        from_stream(M);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, H1, A, B, P, Q, M, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1556708627;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "EllysTeleport (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
