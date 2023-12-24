#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int main() {
    int n,k; cin >> n >> k;
    ordered_set s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int target = k;
    while(s.size()){
        if(target >= s.size()){
            target %= s.size();
        }
        int ans = *s.find_by_order(target);
        cout << ans << " ";
        s.erase(s.find_by_order(target));
        target += k;
    }
}