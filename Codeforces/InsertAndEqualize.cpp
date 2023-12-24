#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a > b)swap(a, b);
    if (a == 0)return b;
    b %= a;
    return gcd(a, b);
}

void solve() {
    int N; cin >> N;
    vector<ll> A(N);
    vector<ll> D(N-1);
    for (int i = 0; i < N; i++)cin >> A[i];
    if (N == 1) {
        cout << 1 << '\n';
        return;
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < N; i++) {
        D[i - 1] = A[i] - A[i - 1];
    }

    ll g = D[0];
    for (int i = 1; i < N-1; i++) {
        g = gcd(g, D[i]);
    }
    ll multi = 1;
    for (int i = 0; i < N-1; i++)multi *= D[i];

    //ll lcm = multi / g; //what we'll add.
    //ll target = A[N - 1] + g;
    ll added = A[N - 1] + g;
    for (int i = 1; i < N; i++) {
        if ((A[i] - A[i-1]) > g) {
            added = A[i] - g;
        }
    }
    ll result = 0;
    ll target = max(added, A[N - 1]);
    for (int i = 0; i < N; i++) {
        result += (target - A[i]) / g;
    }
    result += (target - added) / g;
    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}