#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	vector<bool> seen(n + 1);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (!seen[arr[i] - 1])
			count++;
		seen[arr[i]] = true;
	}
	vector<int> idx(n+1);
	for (int i = 1; i <= n; i++)
	{
		idx[arr[i-1]] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		int tmp = max(a, b);
		int t = min(a, b);
		a = t;
		b = tmp;
		int l = arr[a - 1];
		int r = arr[b - 1];
		if (l > 1 && idx[l - 1] > a && idx[l - 1] < b){
			count--;
		}
		if (l < n && idx[l + 1] > a && idx[l + 1] < b) {
			count++;
		}
		if (r > 1 && idx[r - 1] > a && idx[r - 1] < b) {
			count++;
		}
		if (r < n && idx[r + 1] > a && idx[r + 1] < b) {
			count--;
		}
		if (l == r + 1)
			count--;
		if (l == r - 1)
			count++;
		swap(arr[a - 1], arr[b - 1]);
		swap(idx[l], idx[r]);
		cout << count << endl;
	}
}
