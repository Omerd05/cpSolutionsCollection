#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll maxVal = 9223372036854775807;
 
ll maxDigit(ll x){
    int best = x % 10;
    x/= 10;
    while(x > 0){
        int digit = x % 10;
        x /= 10;
        best = max(best,digit);
    }
    return best;
}
 
int main(){
    ll n; cin >> n;
    ll ans = 0;
    while(n > 0){
        ll digit = maxDigit(n);
        n -= digit;
        ans++;
    }
    cout << ans << '\n';
}