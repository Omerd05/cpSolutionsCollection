#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    if (N == 1) {
        if (s[0] == '0') {
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
        return;
    }
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (s[i] == '0')flag = 1;
    }
    if (flag) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
