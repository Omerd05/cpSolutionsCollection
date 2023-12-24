#include <iostream>
#include <vector>
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
	long n, q; cin >> n >> q;
	vector<vector<bool>> v(n);
	for (long i = 0; i < n; i++)
	{
		vector<bool> tmp(n);
		for (long j = 0; j < n; j++)
		{
			char a;
			cin >> a;
			tmp[j] = a == '*';
		}
		v[i] = tmp;
	}
	//vector<vector<long>> cool(n, vector<long>(n));
	vector<vector<long>> tmp(n,vector<long> (n));
	for (long i = n-1; i >= 0; i--)
	{
		for (long j = n-1; j >= 0; j--)
		{
			if (i < n-1) {
				tmp[i][j] += tmp[i+1][j]; //+ dp[i + 1, j];
			}
			//if (j < n - 1) {
			//	cool[i][j] += cool[i][j + 1];
			//}
			if (v[i][j]) {
				tmp[i][j]++;
				//cool[i][j]++;
			}
		}
	}
	vector<vector<long>> dp(n, vector<long>(n));
	for (long i = n - 1; i >= 0; i--)
	{
		long nowRow = 0;
		for (long j = n - 1; j >= 0; j--)
		{
			dp[i][j] += tmp[i][j];
			int t = dp[i][j];
			if (j < n - 1) {
				dp[i][j] += nowRow;
			}
			nowRow += t;
		}
	}
	for (long i = 0; i < q; i++)
	{
		long y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
		y1 -= 1;
		x1 -= 1;
		y2 -= 1;
		x2 -= 1;
		int ans = 0;
		ans += dp[y1][x1] - dp[y2][x2];
		if (v[y2][x2])
			ans++;
		if (y2 + 1 < n) {
			ans = ans - (dp[y2 + 1][x1] - dp[y2 + 1][x2]);
		}
		if (x2 + 1 < n) {
			ans = ans - (dp[y1][x2 + 1] - dp[y2][x2 + 1]);
		}
		cout << ans << endl;
	}
}