#include <iostream>
#include <vector>
 
using namespace std;
typedef long long ll;
 
void dfs(vector<vector<int>>& v, int x, int y, int n, int m) {
    if (x < n && x >= 0 && y >= 0 && y < m && v[x][y] == 1) {
        v[x][y] = 0;
        dfs(v, x + 1, y, n , m);
        dfs(v, x - 1, y, n , m);
        dfs(v, x, y + 1, n , m);
        dfs(v, x, y - 1, n , m);
    }
}
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch; cin >> ch;
            if (ch == '.') { v[i][j] = 1; }
            if (ch == '#') { v[i][j] = 0; }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j]) {
                dfs(v, i, j, n, m);
                ans++;
            }
        }
    }
    cout << ans << '\n';
}