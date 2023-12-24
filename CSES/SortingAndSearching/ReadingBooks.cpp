#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
signed main(){
    int n; cin >> n;
    vector<int> v(n);
    multiset<int> s1,s2,o1,o2;
    long long a,b; a = 0; b = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        s1.insert(v[i]);
        a+=v[i];
    }
    if(n == 1){
        cout << v[0] * 2;
    }
    else{
        long long ans = 0;
    long long c = a;
    while(s1.size() > 1 && a > b){
        int val = *s1.begin();
        a -= val;
        b += val;
        s2.insert(val);
        s1.erase(s1.begin());
    }
    long long d = c;
    c += abs(b - a);
    o1 = s1;
    o2 = s2;
    while(s2.size() > 1 && b > a){
        int val = *s2.begin();
        a += val;
        b -= val;
        s1.insert(val);
        s2.erase(s2.begin());
    }
    d += abs(a - b);
    multiset<pair<bool,int>> f,s;
    if(c > d){
        while(s1.size()){
            f.insert({false,*s1.begin()}); s1.erase(s1.begin());
        }
        while(s2.size()){
            s.insert({false,*s2.begin()}); s2.erase(s2.begin());
        }
    }
    else{
        while(o1.size()){
            f.insert({false,*o1.begin()}); o1.erase(o1.begin());
        }
        while(o2.size()){
            s.insert({false,*o2.begin()}); o2.erase(o2.begin());
        }
    }
    ll t1,t2; t1 = f.begin()->second; t2 = s.begin()->second;
    while(f.size()){
        if(t1 >= t2){
            ans += t2;
            t1 -= t2;
            if(!s.begin()->first){
                f.insert({true,s.begin()->second});
            }
            s.erase(s.begin());
            while(!s.size() && f.size()){
                ans += t1;
                if(!f.begin()->first){
                    s.insert({true,f.begin()->second});
                }
                f.erase(f.begin());
                t1 = f.begin()->second;
            }
            t2 = s.begin()->second;
        }
        else{
            ans += t1;
            t2 -= t1;
            if(!f.begin()->first){
                s.insert({true,f.begin()->second});
            }
            f.erase(f.begin());
            while(!f.size() && s.size()){
                ans += t2;
                if(!s.begin()->first){
                    f.insert({true,s.begin()->second});
                }
                s.erase(s.begin());
                t2 = s.begin()->second;
            }
            t1 = f.begin()->second;
        }
    }
    cout << ans << endl;
    }
}