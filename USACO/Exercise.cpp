#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll N,MOD;
vector<ll> primes;


//Main idea - a permutation is a union of disjoint cycles. the minimal k for which : p^k = I is the lcm of the cycle sizes.
//The last observation is that you shouldn't consider cases where there is a cycle of size not a prime power, as pq>= p+q while the lcm isn't effected. 

void init() {
	//ios::sync_with_stdio(0); cin.tie(0);
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	cin >> N >> MOD;

	for (int i = 2; i <= N; i++) {
		bool flag = true;
		for (int x = 2; x <= sqrt(i); x++) {
			if (i % x == 0)flag = false;
		}
		if (flag)primes.push_back(i);
	}
}

int main()
{
	init();
	if (N == 1) {
		cout << 1;
		return 0;
	}
	int psz = primes.size();
	vector<vector<ll>> dp(N+1, vector<ll>(psz+1,0));

	ll pref = 0;
	ll twopow = 1;
	for (int x = 1; x <= N; x++) {
		if (x >= twopow) {
			pref += twopow;
			twopow *= 2;
		}
		dp[x][0] = pref;
	}
	for (int j = 0; j < psz; j++)dp[0][j] = 1;

	for (int j = 1; j < psz; j++) {
		for (int x = 1; x <= N; x++) {
			if(j>0) dp[x][j] += dp[x][j - 1];
			ll num = primes[j];
			while (x >= num) {
				dp[x][j] += dp[x - num][j - 1] * num;
				num *= primes[j];
				dp[x][j] %= MOD;
			}
		}
	}

	cout << dp[N][primes.size()-1];
}
