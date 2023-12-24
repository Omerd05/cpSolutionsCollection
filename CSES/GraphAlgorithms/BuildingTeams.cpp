#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<int>> g;
vector<int> comps;
int len;
int dfs(int v) {
    int loc = 0;
    for (int u : g[v])
    {
        if (u == -10) { loc++;continue; }
        //g[v][u] = -10;
        int was = u;
        g[v][loc] = -10;
        if (comps[u] == -1) {
            int idx = 3 - dfs(u);
            g[v][loc] = was;
            if (comps[v] == -1) {
                comps[v] = idx;
            }
            else {
                if (idx != comps[v]) {
                    return -2;
                }
            }
        }
        else {
            if (comps[v] == -1) {
                comps[v] = 3 - comps[u];
            }
            else {
                if (comps[v] != 3 - comps[u]) {
                    return -2;
                }
            }
        }
        loc++;
    }
    /*for (int u = 1; u <= len; u++)
    {
        if (g[v][u]) {
            g[v][u] = 0;
            if (comps[u] == -1) {
                int idx = 3 - dfs(u);
                g[v][u] = 1;
                g[u][v] = 1;
                if (comps[v] == -1) {
                    comps[v] = idx;
                }
                else {
                    if (idx != comps[v]) {
                        return -2;
                    }
                }
            }
            else {
                if (comps[v] == -1) {
                    comps[v] = 3 - comps[u];
                }
                else {
                    if (comps[v] != 3 - comps[u]) {
                        return -2;
                    }
                }
            }
        }
    }*/
    if (comps[v] == -1) { comps[v] = 2; }
    return comps[v];
}
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    len = n;
    g.resize(n + 1, vector<int>()); //����� ��������� �������� ������ ������, ��� �� �� ����. ���� ��� ����� (?) ������ ������ ���� �� ���� ����� �� ���'
    comps.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        int idx = dfs(i);
        if (idx == -2) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
        else {
            comps[i] = idx;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << comps[i] << " ";
    }
}