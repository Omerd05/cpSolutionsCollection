#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            char ch; cin >> ch;
            a[i] = ch - '0';
        }
        vector<ll> s(n);
        s[0] = a[0] - 1;
        for (int i = 1; i < n; i++)s[i] = s[i - 1] + a[i] - 1;
        map<ll, ll> T;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += s[i] == 0;
            ans += T[s[i]];
            T[s[i]] += 1;
        }
        cout << ans << '\n';
    }
}