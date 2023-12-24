#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    long n; cin >> n;
	vector<long> v(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int cnt = n;
	for (long i = 1; i < n; i++)
	{
		if (v[i - 1] == v[i]) { cnt--; }
	}
	cout << cnt << endl;
}