#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
pair<int, int> s, e;
bool seen[1000][1000];
char way[1000][1000];
int room [1000][1000];
int n, m;
vector<int> r = { 1,-1,0,0 };
vector<int> l = { 0,0,1,-1 };
vector<char> h = { 'U','D','L','R' };
bool check(int i, int j)
{
    if (i < 0 || j < 0 || j >= m || i >= n || seen[i][j])return false;
    return (1 - room[i][j]);
}
int f(int a)
{
    if (a == 0)return 1;
    if (a == 1)return 0;
    if (a == 2)return 3;
    if (a == 3)return 2;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    char tmp;   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            if (tmp == '#')room[i][j] = 1;
            else room[i][j] = 0;
            if (tmp == 'A')s = { i,j };
            if (tmp == 'B')e = { i,j };
        }
    }
    queue<pi> q;
    q.push(s);
    seen[s.first][s.second] = true;
    while (q.size())
    {
        pi a = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (check(a.first + r[i], a.second + l[i]))
            {
                q.push({ a.first + r[i], a.second + l[i] });
                seen[a.first + r[i]][a.second + l[i]]=true;
                way[a.first + r[i]][a.second + l[i]] = h[i];
            }
            if (seen[e.first][e.second])
            {
                i = 4; while (q.size())q.pop();
            }
        }
    }
    string str;
    int cnt = 0;
    if (!seen[e.first][e.second])
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    while (e!=s)
    {
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            if (way[e.first][e.second] == h[i])
            {
                e = { e.first + r[f(i)],e.second + l[f(i)] };
                str += h[f(i)];
                break;
            }
        }
    }
    reverse(str.begin(), str.end());
    cout << cnt << "\n";
    cout << str;
}