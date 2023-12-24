#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long n,x; cin >> n >> x;
    vector<vector<long>> v(1000001,vector<long>(2));
    vector<long> numbers(n);
    for(long i = 0; i < n; i++){
        long num; cin >> num;
        numbers[i] = num;
        v[num][0] = 1;
        v[num][1] = 1;
    }
   for(long i = 1; i <= x; i++){
        for(long j = 0; j < n; j++){
        long idx = i - numbers[j];
          if(idx > 0){
                if(v[idx][1] == 1){
                    if(v[i][1] == 0){
                        v[i][0] = v[idx][0] + 1;
                        v[i][1] = 1;
                    }
                    else{
                        v[i][0] = min(v[i][0],v[idx][0] + 1);
                    }
                }
            }
        }
    }
    if (v[x][1] == 1){
        cout << v[x][0] << endl;
    }
    else{
        cout << -1 << endl;
    }
}