#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<vector<int>> grid;
vector<vector<vector<pair<int, int>>>> adj;
vector<vector<bool>> done;
set<pair<int, int>> dots;

int N, M;

bool dfs(pair<int,int> p) {
    dots.erase(p);
    done[p.first][p.second] = 1;
    if (p.first == N - 1 && p.second == M - 1)return 1;
    for (auto u : adj[p.first][p.second]) {
        if (done[u.first][u.second])continue;
        if (dfs(u))return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> N >> M;
        grid.resize(N, vector<int>(M));
        adj.resize(N, vector<vector<pair<int,int>>>(M,vector<pair<int, int>>()));
        done.resize(N, vector<bool>(M));
        vector<pair<int, int>> bads,goods;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char ch; cin >> ch;
                if (ch == '.')grid[i][j] = 0;
                if (ch == '#')grid[i][j] = -1;
                if (ch == 'G') { grid[i][j] = 1; goods.push_back({ i,j }); dots.insert({ i,j }); }
                if (ch == 'B') { grid[i][j] = 2; bads.push_back({i,j}); }
            }
        }
        bool ans = 1;
        for (auto p : bads) {
            int x = p.first, y = p.second;
            if (x > 0) {
                if (grid[x - 1][y] == 1) { ans = 0; break; }
                grid[x - 1][y] = -1;
            }
            if (y > 0) {
                if (grid[x][y-1] == 1) { ans = 0; break; }
                grid[x][y-1] = -1;
            }
            if (x < N - 1) {
                if (grid[x + 1][y] == 1) { ans = 0; break; }
                grid[x + 1][y] = -1;
            }
            if (y < M - 1) {
                if (grid[x][y+1] == 1) { ans = 0; break; }
                grid[x][y+1] = -1;
            }
        }
        if (ans == 0) { cout << "No" << '\n'; continue; }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == -1)continue;
                if (i < N-1 && grid[i + 1][j] != -1) {
                    adj[i][j].push_back({ i + 1,j });
                    adj[i + 1][j].push_back({ i,j });
                }
                if (j < M-1 && grid[i][j + 1] != -1) {
                    adj[i][j].push_back({ i,j + 1 });
                    adj[i][j + 1].push_back({ i,j });
                }
            }
        }
        for (auto pp : goods) {
            if (dots.count(pp) == 0)continue;
            if (!dfs(pp)) { ans = 0; break; }
            done.assign(N, vector<bool>(M));
        }
        if (ans)cout << "Yes" << '\n';
        else cout << "No" << '\n';
        grid.clear();
        adj.clear();
        done.clear();
    }
}