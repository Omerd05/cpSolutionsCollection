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
int N, M;
vector<vector<int>> adj;
vector<vector<int>> Gt;
vector<int> ord,comp;
 
void dfs1(int v, vector<bool>& done) {
    done[v] = 1;
    for (int u : adj[v]) {
        if (done[u])continue;
        dfs1(u, done);
    }
    ord.push_back(v);
}
 
void dfs2(int v, vector<bool>& done) {
    done[v] = 1;
    for (int u : Gt[v]) {
        if (!done[u])
            dfs2(u,done);
    }
    comp.push_back(v);
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    adj.resize(N + 1, vector<int>());
    Gt.resize(N + 1, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        Gt[b].push_back(a);
    }
    vector<bool> done(N + 1);
    for (int i = 1; i <= N; i++)
        if (!done[i])dfs1(i,done);
    done.assign(N + 1, 0);
    reverse(ord.begin(), ord.end());
    dfs2(ord[0], done);
    for (int vertex : ord) {
        if (!done[vertex]) {
            cout << "NO" << '\n';
            cout << vertex << " " << ord[0];
            return 0;
        }
    }
    cout << "YES";
    /*if (comp.size() == N)cout << "YES";
    else {
        for (int i = 2; i <= N; i++) {
            if (!done[i]) {
                cout << "NO" << '\n';
                cout << i << " " << 1;
                break;
            }
        }
    }*/
}