#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
vector<vector<int>> adj;
vector<int> col;
vector<bool> done;
int N, M;
bool flag = true;
ll odds = 0;

ll calc(ll num,ll b) {
	if (!b)return 1;
	ll v = calc(num, b / 2) % MOD;
	ll tmp = v * v % MOD;
	if (b % 2) (tmp *= num);
	return tmp % MOD;
}

ll dfs(int v, int color) {
	ll cnt = 1;
	//if (!flag)return 0;
	done[v] = 1;
	col[v] = color;
	odds += col[v] == 1;
	for (int u : adj[v]) {
		if (done[u]) {
			if (col[v] == col[u]) { flag = 0; }// return; }
		}
		else {
			cnt += dfs(u, 1 - color);
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll ans = 1;
		cin >> N >> M;
		flag = 1;
		adj.assign(N+1, vector<int>());
		col.assign(N+1,0);
		done.assign(N+1,0);
		for (int i = 0; i < M; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= N; i++) {
			if (done[i])continue;
			odds = 0;
			ll total = dfs(i, 0);
			ans *= calc(2, odds) + calc(2, total - odds); ans %= MOD;
		}
		cout << ans*flag << '\n';
	}
}