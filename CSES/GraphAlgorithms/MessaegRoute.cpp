#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
 
using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> g;
/*vector<int> comps;
void dfs(int id,int v) {
    comps[v] = id;
    for (int u : g[v]) {
        if (comps[u] == -1) {
            dfs(id, u);
        }
    }
}*/
vector<bool> seen;
vector<int> len;
vector<int> father;
void bfs(int n) {
    queue<int> q; q.push(1);
    while (q.size()) {
        if (q.front() == n) {
            cout << len[q.front()] + 1 << '\n';
            int last = father[q.front()];
            stack<int> res;
            while (last) {
                res.push(last);
                last = father[last];
            }
            while (res.size())
            {
                cout << res.top() << " ";
                res.pop();
            }
            cout << n;
            return;
        }
        for (int u : g[q.front()]) {
            if (!seen[u]) {
                seen[u] = true;
                q.push(u);
                len[u] = len[q.front()] + 1;
                father[u] = q.front();
            }
        }
        seen[q.front()] = true;
        q.pop();
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    //comps.resize(n + 1, -1);
    father.resize(n + 1);
    seen.resize(n + 1, false);
    len.resize(n + 1, 0);
    g.resize(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int u : g[1]) {
        if (u == n) {
            cout << n << '\n';
            cout << "1 " << n << '\n';
            return 0;
        }
    }
    bfs(n);
    /*for (int i = 1; i <= n; i++)
    {
        if (comps[i] == -1) {
            dfs(cnt++, i);
        }
    }*/
}