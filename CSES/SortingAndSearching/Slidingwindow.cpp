#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ordered_set s;
    int l = 0; int r = 0;
    while (r < k) {
        s.insert({v[r],r});
        r++;
    }
    auto it = s.find_by_order(k / 2 - (k+1)%2);
    int med = it->first;
    int idxmed = it->second;
    ll tmp = 0;
    for(int i = l; i < r; i++){
        tmp += abs(med - v[i]);
    }
    cout << tmp << " ";
    int last = med;
    bool flag = false;
    while(r < n){
        tmp -= abs(v[l] - med);
        s.erase(s.find({v[l],l}));
 
        int ord = (k - 1) / 2;
        ord -= v[l++] <= med && l-1 != idxmed;
 
        s.insert({v[r],r});
        last = med;
        med = s.find_by_order((k - 1)/2)->first;
        tmp += abs(v[r++] - med);
        
        if(tmp == 5){
            int olsdjkasdas = 0;
        }
 
        ord += med > last && l-1 != idxmed; //ord -= flag;
        tmp += ord*(med - last);
        tmp -= (k - 1 - ord)*(med - last);
 
 
        idxmed = s.find_by_order((k - 1)/2)->second;
        cout << tmp << " ";
    }
}