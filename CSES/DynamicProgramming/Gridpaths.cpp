#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef long long ll;
#define PI pair<ll,ll>
ll N;
ll dp[1005][1005];
bool mines[1005][1005];
const int MOD = 1e9 + 7;
 
int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch; cin >> ch;
			mines[i][j] = ch == '*';
			dp[i][j] = 0;
		}
	}
 
	dp[N - 1][N - 1] = !mines[N - 1][N - 1];
 
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (mines[i][j])continue;
			if (i < N - 1)dp[i][j] += dp[i + 1][j];
			if (j < N - 1)dp[i][j] += dp[i][j + 1];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[0][0];
}