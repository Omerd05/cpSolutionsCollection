#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, a, b, ans = -2e18; cin >> n >> a >> b;
    vector<ll> reisha(n + 1);
    reisha[0] = 0;
    for (int i = 1; i <= n;i++) {
        cin >> reisha[i];
        reisha[i] += reisha[i - 1];
    }
    multiset<ll> ms;
    for (int i = a;i <= n;i++) {
        ms.insert(reisha[i - a]);
        ans = max(ans, reisha[i] - *ms.begin());
        if (i >= b) {
            ms.erase(ms.find(reisha[i - b]));
        }
    }
    cout << ans;
}