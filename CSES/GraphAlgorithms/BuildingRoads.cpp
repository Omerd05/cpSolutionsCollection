#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
using namespace std;
 
vector<int> comps;
vector<vector<int>> g;
void dfs(int id,int v) {
    comps[v] = id;
    for (int u : g[v]) {
        if (comps[u] == -1) {
            dfs(id, u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    comps.resize(n + 1, -1);
    g.resize(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (comps[i] == -1) {
            dfs(cnt++, i);
        }
    }
    queue<int> q1;
    queue<int> q2;
    set<int> solved;
    for (int i = 2; i <= n; i++)
    {
        if (comps[i-1] != comps[i]) {
            if (!solved.count(comps[i - 1]) || !solved.count(comps[i])) {
                q1.push(i - 1);
                q2.push(i);
                solved.insert(comps[i - 1]);
                solved.insert(comps[i]);
            }
        }
    }
    cout << cnt - 1 << '\n';
    while (q1.size()) {
        cout << q1.front() << " " << q2.front() << '\n';
        q1.pop();
        q2.pop();
    }
}