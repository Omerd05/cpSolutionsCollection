#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    long n; cin >> n;
    long sum = -2147483647;
    long now = 0;
    vector<long> v(n);
    for (int i = 0; i < n; i++) { cin >> v[i]; }
    for (int i = 0; i < n; i++)
    {
        now = max(now + v[i], v[i]);
        sum = max(now, sum);
    }
    cout << sum << endl;
}