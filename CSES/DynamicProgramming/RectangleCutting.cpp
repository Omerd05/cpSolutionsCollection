#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll maxVal = 9223372036854775807;
 
int main(){
    int a,b; cin >> a >> b;
    vector<vector<ll>> dp(a+1,vector<ll>(b+1));
    vector<vector<bool>> able(a+1,vector<bool>(b+1));
    int tmp = min(a,b) + 1;
    for (int i = 0; i < a + 1; i++)
    {
        for (int j = 0; j < b + 1; j++)
        {
            dp[i][j] = 1e18;
            able[i][j] = false;
        }
    }
    for (int i = 1; i < tmp; i++)
    {
        dp[i][i] = 0;
        able[i][i] = true;
    }
    for (int i = 1; i < a + 1; i++)
    {
        for (int j = 1; j < b + 1; j++)
        {
            for (int dist = 1; dist < a; dist++)
            {
                int idx = i - dist;
                if(idx > 0 && able[idx][j]){
                    dp[i][j] = min(dp[i][j],dp[idx][j] + dp[dist][j] + 1);
                    able[i][j] = true;
                }
            }
            
            for (int dist = 1; dist < b; dist++)
            {
                int idx = j - dist;
                if(idx > 0 && able[i][idx]){
                    dp[i][j] = min(dp[i][j],dp[i][idx] + dp[i][dist] + 1);
                    able[i][j] = true;
                }
            }
        }
    }
    cout << dp[a][b] << '\n';
}