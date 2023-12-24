#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
 
typedef long long ll;
using namespace std;
 
int main()
{
    int n; cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({ a, 1 });
        v.push_back({ b,-1 });
    }
    sort(v.begin(), v.end());
    int maxi, cur; maxi = 0; cur = 0;
    for (pair<int,int> x : v) {
        cur += x.second;
        maxi = max(cur, maxi);
    }
    cout << maxi << endl;
}