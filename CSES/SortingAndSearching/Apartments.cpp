#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    long n,m,k; cin >> n >> m >> k;
	vector<long> a(n);
	vector<long> dep(m);
	for (long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (long i = 0; i < m; i++)
	{
		cin >> dep[i];
	}
	sort(a.begin(), a.end(), greater<long>());
	sort(dep.begin(), dep.end(), greater<long>());
	int astart = 0;
	int depstart = 0;
	int cnt = 0;
	while (astart < n && depstart < m) {
		if (abs(a[astart] - dep[depstart]) <= k) {
			cnt++;
			astart++;
			depstart++;
		}
		else {
			if (a[astart] - dep[depstart] > 0) { astart++; }
			else { depstart++; }
		}
	}
	cout << cnt << endl;
}
