#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector<int> bx = { 1,-1,0,0 };
vector<int> by = { 0,0,1,-1 };
vector<vector<char>>map;
vector<vector<pair<char,int>>>way;
vector<vector<int>>way1;
vector<vector<bool>>seen;
queue<pair<int, int>> q;
int n, m;
char p(int i)
{
    if (i == 0)return 'U';
    if (i == 1)return 'D';
    if (i == 2)return 'L';
    return 'R';
}
bool check(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)return false;
    if (map[i][j] == '#' || map[i][j] == 'M')return false;
    if (seen[i][j])return false;//need to reset
    return true;
}
bool check1(int i, int j,pi a)
{
    if (way1[i][j] == -1)return true;
    if (way1[i][j] <= way[a.first][a.second].second + 1)
    {
        seen[i][j] = true;
        return false;
    }
    return true;
}
void bfs()
{
    while (q.size())
    {
        pi a = q.front();
        seen[a.first][a.second] = true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pi k = { a.first + bx[i], a.second + by[i] };
            if (check(k.first,k.second)&&check1(k.first,k.second,a))
            {
                q.push(k);
                way[k.first][k.second].first = p(i);
                way[k.first][k.second].second = way[a.first][a.second].second + 1;
            }
        }
    }
}
void bfs1()
{
    while (q.size())
    {
        pi a = q.front();
        q.pop();
        seen[a.first][a.second] = true;
        for (int i = 0; i < 4; i++)
        {
            pi k = { a.first + bx[i], a.second + by[i] };
            if (check(k.first, k.second)&&way1[k.first][k.second]<0)
            {
                q.push(k);
                way1[k.first][k.second] = way1[a.first][a.second] + 1;
            }
        }
    }
}
char go(char a)
{
    if (a == 'U')return 'D';
    if (a == 'D')return 'U';
    if (a == 'R')return 'L';
    return 'R';
}
int add(char a)
{
    if (a == 'U')return 1;
    if (a == 'D')return 0;
    if (a == 'R')return 2;
    return 3;
}
void print(int i, int j)
{
    cout << "YES\n";
    cout << way[i][j].second << "\n";
    string s;
    while (way[i][j].first!='a')
    {
        s += go(way[i][j].first);
        int tmp = add(way[i][j].first);
        i += bx[tmp];
        j += by[tmp];
    }
    reverse(s.begin(),s.end());
    cout << s;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    char tmp;
    map = vector<vector<char>>(n, vector<char>(m));
    way = vector<vector<pair<char,int>>>(n, vector<pair<char,int>>(m,{'a',-1}));
    way1 = vector<vector<int>>(n, vector<int>(m,-1));
    seen = vector<vector<bool>>(n, vector<bool>(m));
    pi a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            map[i][j] = tmp;
            if (tmp == 'M')
            {
                q.push({ i,j });
                way1[i][j] = 0;
                seen[i][j] = true;
            }
            if (tmp == 'A')a = { i,j };
        }
    }
    bfs1();
    seen = vector<vector<bool>>(n, vector<bool>(m));
    while (q.size())q.pop();
    q.push(a);
    way[a.first][a.second].second = 0;
    bfs();
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        int x = way[0][i].second;
        if (x==-1)continue;
        else
        {
            if (way1[0][i] == -1 || x < way1[0][i])
            {
                flag = true;
                print(0, i);
                i = m;
            }
        }
    }
    if (flag)return 0;
    for (int i = 0; i < m; i++)
    {
        int x = way[n-1][i].second;
        if (x == -1)continue;
        else
        {
            if (way1[n-1][i] == -1 || x < way1[n-1][i])
            {
                flag = true;
                print(n-1, i);
                i = m;
            }
        }
    }
    if (flag)return 0;
    for (int i = 0; i < n; i++)
    {
        int x = way[i][0].second;
        if (x == -1)continue;
        else
        {
            if (way1[i][0] == -1 || x < way1[i][0])
            {
                flag = true;
                print(i, 0);
                i = n;
            }
        }
    }
    if (flag)return 0;
    for (int i = 0; i < n; i++)
    {
        int x = way[i][m-1].second;
        if (x == -1)continue;
        else
        {
            if (way1[i][m-1] == -1 || x < way1[i][m-1])
            {
                flag = true;
                print(i, m - 1);
                i = n;
            }
        }
    }
    if (flag)return 0;
    cout << "NO\n";
}