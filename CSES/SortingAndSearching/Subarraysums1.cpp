#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main(){
    ll n,x; cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll l = 0;
    ll r = 0;
    ll ans = 0;
    ll sum = v[0];
    while (l < n)
    {
        if(sum > x){
            sum -= v[l];
            l++;
        }
        if(sum < x && r < n){
            r++;
            sum += v[r];
        }
        if(sum == x){
            ans++;
            sum -= v[l];
            l++;
        }
        if(r == n){l++;}
    }
    cout << ans << '\n';
}