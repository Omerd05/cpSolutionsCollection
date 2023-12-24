#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    long n; cin >> n;
    vector<pair<long, long>> v(n);
    for (long i = 0; i < n; i++)
    {
        cin >> v[i].second; // end
        cin >> v[i].first;  // start
    }
    sort(v.begin(), v.end());
    long time = v[0].first;
    long cnt = 1;
    long past = 1;
    while (past < v.size()) {
        if (time <= v[past].second) { time = v[past].first; cnt++; }
        past++;
    }
    cout << cnt << endl;
}