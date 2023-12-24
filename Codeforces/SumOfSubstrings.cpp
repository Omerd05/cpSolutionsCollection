#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <stack>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int N, K;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)
#define x first
#define y second
#define print(x) cout << x << '\n'

void solve() {
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        char ch; cin >> ch;
        v[i] = ch - '0';
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] == 1) {
            ans += 11;
        }
    }
    reverse(v.begin(), v.end());
    vector<int> tmp = v;
    bool flag = false;
    int idx = 1;
    for (int i = 0; i <= K && i < N; i++, idx++) {
        if (v[i] == 1) {
            flag = true;
            for (int j = i; j > 0; j--) {
                int t = v[j];
                v[j] = v[j - 1];
                v[j - 1] = v[j];
            }
            ans -= 10;
            K -= i;
            break;
        }
    }
    if (!flag)v = tmp;
    reverse(v.begin(), v.end());
    for (int i = 0; i <= K && i < N - 1; i++) {
        if (v[i] == 1) {
            ans -= 1;
            break;
        }
    }
    print(ans);
}

int main()
{
    fast;
    int T; cin >> T;
    while (T--) {
        solve();
    }
}