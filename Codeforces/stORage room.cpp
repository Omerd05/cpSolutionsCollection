#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
#define PI pair<int,int>
const int MOD = 1e9 + 7;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<ll> A(N,(1<<30) - 1);
        vector<vector<ll>> M(N, vector<ll>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> M[i][j];
                if (i == j)continue;

                for (int p = 0; p < 30; p++) {
                    if (((1 << p) & M[i][j]) == 0) {
                        if (((1 << p) & A[i])) {
                            A[i] -= (1 << p);
                        }
                        if (((1 << p) & A[j])) {
                            A[j] -= (1 << p);
                        }
                    }
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j)continue;

                if ((A[i] | A[j]) != M[i][j]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            cout << "YES" << '\n';
            for (int i = 0; i < N-1; i++) {
                cout << A[i] << " ";
            }
            cout << A[N - 1] << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}