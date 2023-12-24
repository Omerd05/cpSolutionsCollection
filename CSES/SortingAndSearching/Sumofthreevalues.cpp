#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 2147483648;
 
int binarysearch(vector<pair<int,int>>& v, int target, int a, int b){
    int l,r; l = 0; r = v.size() - 1;
    while(l < r){
        int mid = (l+r)/2;
        if(v[mid].first >= target){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(v[l].first == target){
        if(v[l].second != a && v[l].second != b){
            return v[l].second;
        }
        bool flag = false;
        while(l > 0 && v[l-1].first == v[l].first){
            if(v[l-1].second != a && v[l-1].second != b){
                flag = true;
                break;
            }
            else{
                break;
            }
            l--;
        }
        if(flag){return l;}
        flag = false;
        while(r < v.size() - 1 && v[r+1].first == v[r].first){
            if(v[r+1].second != a && v[r+1].second != b){
                flag = true;
                r++;
                break;
            }
            else{
                break;
            }
            r++;
        }
        if(flag){return v[r].second;}
        return -1;
    }
    else{
        return -1;
    }
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,x; cin >> n >> x;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)continue;
            int idx = binarysearch(v,x - v[i].first - v[j].first,v[i].second,v[j].second);
            if(idx != v[i].second && idx != v[j].second && idx != -1){
                cout << v[i].second + 1 << " " << v[j].second + 1<< " " << idx + 1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}