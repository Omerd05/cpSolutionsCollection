#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
 
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int N, Q;
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> Q;
    vector<int> A(N);
    vector<vector<int>> P(N, vector<int>(32));
    vector<int> tpow(N + 5, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        P[i][0] = A[i];
        tpow[i + 2] = tpow[(i+2) / 2] + 1;
    }
    for (int k = 1; k <= tpow[N]; k++) {
        for (int i = 0; i < N; i++) {
            P[i][k] = min(P[i][k - 1], P[min(i + (int)pow(2, k - 1),N-1)][k - 1]);
        }
    }
    while (Q--) {
        int L, R; cin >> L >> R; L--;R--;
        if (L > R)swap(L, R);
        int K = tpow[R - L + 1];
        int mini = min(P[L][K], P[R - pow(2, K) + 1][K]);
        cout << mini << '\n';
    }
}