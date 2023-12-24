#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
#define PI pair<int,int>
const int MOD = 1e9 + 7;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {

        int N; cin >> N;
        vector<ll> A(N);
        vector<ll> dp(N);
        vector<ll> pref(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            pref[i] = A[i];
            if (i)pref[i] += pref[i - 1];
        }
        priority_queue<ll> pq;
        pq.push(0);
        
        for (int i = N - 1; i >= 0; i--) {
            ll suff = pref[N - 1] - (pref[i]-A[i]);
            dp[i] = pq.top() + suff;
            pq.push(dp[i]);
        }
        cout << dp[0] << '\n';
    }
}