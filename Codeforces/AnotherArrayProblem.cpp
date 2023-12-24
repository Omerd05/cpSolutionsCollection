#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];

    if (n == 2) {
        cout << max(A[0] + A[1], 2 * abs(A[0] - A[1])) << '\n';
        return;
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == A[idx]) {
            if (i != 1 && i != n - 2) {
                idx = i;
            }
        }
        if (A[i] > A[idx]) {
            idx = i;
        }
    }

    if (n == 3 && idx == 1) {

        long long a1 = A[0] + A[1] + A[2];
        long long a2 = max(3 * A[2], 3 * A[0]);
        long long a3 = 3 * max(A[1]-A[2],A[1]-A[0]);
        long long res = max(max(a1, a2), a3);
        cout << res << '\n';
        return;
    }

    long long ans = n * A[idx];

    cout << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}