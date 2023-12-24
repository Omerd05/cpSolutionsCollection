#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

void solve() {
    ll N, P, L, t; cin >> N >> P >> L >> t;
    
    ll mini = 0; ll maxi = N;
    ll mid = (mini + maxi) / 2;
    ll result = maxi;

    while (mini <= maxi) {
        ll tasks = min((ll)((N-1)/ 7)+1, 2*mid) * t;
        if (tasks + mid * L >= P) {
            result = min(result, mid);
            maxi = mid - 1;
        }
        else {
            mini = mid + 1;
        }
        mid = (mini + maxi) / 2;
    }
    cout << N-result << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
