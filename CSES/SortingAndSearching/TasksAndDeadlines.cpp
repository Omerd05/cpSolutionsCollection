#include <bits/stdc++.h>
 
using namespace std;
 
signed main(){
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        v[i] = {a,b};
    }
    sort(v.begin(),v.end());
    long long now = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        now += v[i].first;
        ans += v[i].second - now;
    }
    cout << ans << endl;
}