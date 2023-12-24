#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll maxVal = 9223372036854775807;
 
ll firstBigger(vector<ll>& v, ll x){
    ll l = 0;
    ll r = v.size() - 1;
    while (l < r)
    {
        ll mid = (l + r - 1) / 2;
        if(v[mid] >= x){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}
 
int main(){
    ll n; cin >> n;
    vector<ll> nums(n);
    vector<ll> A(n+1,maxVal);
    A[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll idx = firstBigger(A,nums[i]);
        A[idx] = min(A[idx],nums[i]);
    }
    for (ll i = n; i > 0; i--)
    {
        if(A[i] != maxVal){
            cout << i << '\n';
            break;
        }
    }
}