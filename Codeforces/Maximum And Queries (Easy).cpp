#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
#define PI pair<int,int>
const int MOD = 1e9 + 7;
//ll dist[1048577][22]; //myb change to (1e5+5)


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll N, Q; cin >> N >> Q;
    vector<ll> A(N);

    /*for (int i = 0; i < (1 << 20); i++) {
        for (int bit = 0; bit <= 20; bit++) {
            ll tempo = ((1 << (bit + 1)) - 1) & i;
            dist[i][bit] = (1 << bit) - tempo;//price to turn on the i'th bit
            dist[i][bit] = max(dist[i][bit], (ll)0);
        }
    }*/

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }


    vector<ll> AB(N);
    for (int i = 0; i < N; i++)AB[i] = A[i];
    while (Q--) {
        ll K; cin >> K;

        ll bit = 59;
        ll result = 0;
        while ((K >= 0) && (bit >= 0)) {
            ll price = 0;

            if (bit == 35) {
                int pause = 0;
            }

            for (int i = 0; i < N; i++) {
                ll pause = pow(2,bit);//(1 << bit);
                ll pause2 = pow(2, bit + 1) - 1;
                ll discount = pause2 & A[i];
                ll pay = max(pause - discount, (ll)0);

                price += pay;//dist[A[i]][bit];
                if (price > K)break;
            }

            if (price <= K) {
                if (K > 10) {
                    int asd = 0;
                }
                K -= price;
                result += pow(2, bit);//(1 << bit);

                for (int i = 0; i < N; i++) {
                    ll pause = pow(2, bit);//(1 << bit);
                    ll pause2 = pow(2, bit + 1) - 1;
                    ll discount = pause2 & A[i];
                    ll pay = max(pause - discount, (ll)0);

                    A[i] += pay;//dist[A[i]][bit];
                }
            }
            bit--;
        }

        cout << result << '\n';
        for (int i = 0; i < N; i++)A[i] = AB[i];
    }
}