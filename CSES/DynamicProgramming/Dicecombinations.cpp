#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    long n; cin >> n;
    vector<long> dp(n+1);
    dp[1] = 1;
    if (n > 6) {
        for (long i = 2; i <= 6; i++)
        {
            for (long j = 1; j < i; j++)
            {
                dp[i] += dp[j];
            }
            dp[i]++;
        }
        for (long i = 7; i <= n; i++)
        {
            for (long j = 1; j <= 6; j++)
            {
                dp[i] += dp[i - j];
                if (dp[i] >= 1000000007) { dp[i] %= 1000000007; }
            }
        }
    }
    else {
        for (long i = 2; i <= n; i++)
        {
            for (long j = 1; j < i; j++)
            {
                dp[i] += dp[j];
            }
            dp[i]++;
        }
    }
    cout << dp[n] << endl;
}