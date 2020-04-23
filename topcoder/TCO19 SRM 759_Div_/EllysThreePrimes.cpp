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

class EllysThreePrimes {
    public:
    vector<bool> is_composite;
    vector<int> prime;

    vector<int> getPrimes(vector<int> sums) {
        is_composite.resize(100001);
        int M = 100000;
        vector<vector<int>> prime2(10);
        for (int i = 2; i <= M; ++i) {
            if(!is_composite[i]) {
                prime.push_back(i);
                prime2[i/10000].push_back(i);
            }
            for (auto &&j : prime) {
                if(i*j > M) break;
                is_composite[i*j] = true;
                if(i % j == 0) break;
            }
        }

        string u(5, '0');
        for (int a = 1; a <= 9; ++a) {
            for (int b = 1; b <= 9; ++b) {
                if(a+b >= sums.back() || a+b+9 < sums.back()) continue;
                for (auto &&i : prime2[a]) {
                    string s = to_string(i);
                    for (auto &&j : prime2[b]) {
                        string t = to_string(j);
                        int ok = 1;
                        for (int k = 0; k < 5; ++k) {
                            u[k] = sums[k]-(s[k]-'0'+t[k]-'0')+'0';
                            if(!isdigit(u[k])) ok = 0;
                        }
                        if(!ok) continue;
                        int k = stoi(u);
                        if(k < 10000 || is_composite[k]) continue;
                        return vector<int>{i, j, k};
                    }
                }
            }
        }
        return vector<int>();
    }
};

// CUT begin
ifstream data("EllysThreePrimes.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> sums, vector<int> __expected) {
    time_t startClock = clock();
    EllysThreePrimes *instance = new EllysThreePrimes();
    vector<int> __result = instance->getPrimes(sums);
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
        vector<int> sums;
        from_stream(sums);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(sums, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1559127550;
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
        cout << "EllysThreePrimes (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
