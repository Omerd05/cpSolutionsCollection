#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
 
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
vector<int> par,sz;
int N, M;
 
int find_set(int a) {
	if (a == par[a])
		return a;
	return par[a] = find_set(par[a]);
}
 
bool unite(int a,int b) {
	int pa = find_set(a), pb = find_set(b);
	if (pa == pb)
		return false;
	if (sz[pa] > sz[pb])
		swap(pa, pb);
	par[pa] = pb;
	sz[pb] += sz[pa];
	return true;
}
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int comps = N; int maxi = 1;
	par.resize(N + 1); sz.resize(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (unite(a, b))--comps;
		maxi = max(maxi, max(sz[find_set(a)], sz[find_set(b)]));
		cout << comps << " ";
		cout << maxi << '\n';
	}
}