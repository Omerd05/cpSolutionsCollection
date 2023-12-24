#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef long long ll;
#define PI pair<ll,ll>
ll N;
ll dp[5005][5005];
ll pref[5005];
 
 
int main()
{
	cin >> N;
	vector<ll> X(N);
	for (int i = 0; i < N; i++)cin >> X[i];
 
	pref[0] = X[0];
	for (int i = 1; i < N; i++) {
		pref[i] = pref[i - 1] + X[i];
	}
 
	for (int i = N-1; i >= 0; i--) {
		dp[i][i] = X[i];
		for (int j = i+1; j < N; j++) {
			ll opt1 = X[i] + (pref[j] - pref[i]) - dp[i + 1][j];
			ll opt2 = X[j] + (pref[j - 1] - (pref[i] - X[i])) - dp[i][j - 1];
			dp[i][j] = max(opt1, opt2);
		}
	}
 
	cout << dp[0][N - 1];
}