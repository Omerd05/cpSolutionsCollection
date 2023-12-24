#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(); cin.tie(0);
    ll x; cin >> x;
    x = abs(x);
    ll N = ceil((-1 + sqrt(1 + 8 * x)) / 2);
    ll dist = N * (N + 1) / 2;
    while (dist % 2 != x % 2) {
        N++;
        dist = N * (N + 1) / 2;
    }
    cout << N;
}