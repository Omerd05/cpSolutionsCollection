#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(); cin.tie(0);
    ll t, k; cin >> t >> k;
    vector<ll> dp(1e5+10);
    ll tmp = min(k, (ll)1e5+1);
    for (int i = 0; i <= tmp; i++)dp[i] = 1;
    for (int i = k; i <= 1e5; i++) {
        dp[i] = (dp[i - k] % MOD + dp[i - 1] % MOD) % MOD;
    }
    vector<ll> r(1e5 + 1);
    r[0] = dp[0];
    for (int i = 1; i <= 1e5; i++) { r[i] = (r[i - 1]%MOD + dp[i]%MOD)%MOD; }// r[i] %= MOD; }
    while (t--) {
        ll a, b; cin >> a >> b;
        ll ans = (r[b] - r[a - 1]) % MOD;
        ans = (ans + MOD) % MOD;
        cout << ans << '\n';
    }
}