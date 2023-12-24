#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
 
using namespace std;
typedef long long ll;
int N;
ll dp[200001];
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    vector<tuple<ll, ll, ll>> v;
    for (int i = 0; i < N; i++) {
        ll a, b, c; cin >> a >> b >> c;
        v.push_back({ b,a,c });
    }
    sort(v.begin(), v.end());
    dp[0] = get<2>(v[0]);
    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i - 1], get<2>(v[i]));
        auto it = lower_bound(v.begin(), v.end(), make_tuple(get<1>(v[i]), -1e18, -1e18));
        if (it == v.begin())continue;
        it--;
        dp[i] = max(dp[i], dp[it - v.begin()] + get<2>(v[i]));
    }
    cout << dp[N - 1];
}