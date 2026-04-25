#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    const long long mod = 1e9 + 7;
    const int p = 31;

    long long hash = 0;
    long long p_power = 1;  

    for (int i = 0; i < s.size(); i++) {
        hash = (hash + (s[i] * p_power) % mod) % mod;
        p_power = (p_power * p) % mod;
    }

    cout << hash << endl;
    return 0;
}
