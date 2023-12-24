#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int main(){
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
    while(r < n){
        auto it = s.find_by_order(k / 2 - (k+1)%2);
        cout << it->first << " ";
        s.erase({v[l],l});
        s.insert({v[r],r});
        l++; r++;
    }
    cout << s.find_by_order(k / 2 - (k+1)%2)->first;
}
