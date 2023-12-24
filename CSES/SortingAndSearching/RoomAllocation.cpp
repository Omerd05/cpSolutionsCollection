#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
 
using namespace std;
const int inf = -2147483648;
int ans[200005];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    multiset<tuple<int,int,int>> time; //when leave, room number and index.
    set<int> used; // which rooms r being used.
    set<int> free; // which rooms r not being used.
    vector<tuple<int, int,int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        //v[i].first = a;
        //v[i].second = b;
        v[i] = { a,b,i };
    }
    sort(v.begin(), v.end());
    time.insert({ get<1>(v[0]),1,get<2>(v[0])});
    used.insert(1);
    int maxi = 1;
    ans[get<2>(v[0])] = 1;
    for (int i = 1; i < n; i++) {
        while (time.size() && get<0>(*time.begin()) < get<0>(v[i])) {
            used.erase(get<1>(*time.begin()));//  time.begin()->second);
            free.insert(get<1>(*time.begin()));//(time.begin()->second);
            time.erase(time.begin());
        }
        if (!free.size()) {
            auto tmp = used.end();
            tmp--;
            int val = (*tmp) + 1;
            used.insert(val);
            time.insert({get<1>(v[i]),val,get<2>(v[i])});
            ans[get<2>(v[i])] = val;
            maxi = max(maxi, val);
        }
        else {
            int val = (*free.begin());
            ans[get<2>(v[i])] = val;
            time.insert({ get<1>(v[i]),val,get<2>(v[i]) });
            used.insert(val);
            free.erase(free.begin());
        }
        maxi = max(maxi, (int)used.size());
    }
    cout << maxi << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}