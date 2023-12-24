#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[100005];
int done[100005];
vector<int> ps;
 
bool dfs(int v, vector<int>& cyc , int p){
    if(done[v]){
        for(int i = ps.size()-1; i>=0; i--){
            cyc.push_back(ps[i]);
            if(ps[i] == v)break;
        }
        reverse(cyc.begin(),cyc.end());
        cyc.push_back(v);
        return true;
    }
    done[v] = 1; ps.push_back(v);
    for(int u : adj[v]){
        if(u != p){
            dfs(u,cyc,v);
            if(cyc.size())return 1;
        }
    }
    ps.pop_back();
    return false;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> cyc;
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!done[i] && dfs(i,cyc,-1)){
            cout << cyc.size()<< '\n';
            for(int i = 0; i < cyc.size(); i++){
                cout << cyc[i] << " ";
            }
            break;
        }
    }
    cout << "IMPOSSIBLE";
}