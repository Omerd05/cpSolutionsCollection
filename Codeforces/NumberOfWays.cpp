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
    ll N; cin >> N;
    vector<ll> r(N), a(N);
    vector<pair<ll, ll>> p(N);
    map<pair<ll, ll>, ll> m; //value - first = (r[j] - r[i],r[n] - r[j]), second = number of appearnces
    for (int i = 0; i < N; i++)cin >> a[i];
    r[0] = a[0];
    for (int i = 1; i < N; i++) { r[i] = r[i - 1] + a[i];}
    for (int i = 0; i < N; i++) p[i] = { r[i],r[N - 1] - r[i] };
    for (int i = 1; i < N-1; i++) {
        m[p[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        pair<ll, ll> tmp = { p[i].first * 2,p[i].first };
        if (i > 0 && m[p[i]])m[p[i]]--;
        if(m.count(tmp))ans += m[tmp];
    }
    cout << ans << '\n';
}