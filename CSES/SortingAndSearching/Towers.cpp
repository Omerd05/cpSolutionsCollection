#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, tmp; cin >> n;
    multiset <int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        auto a = s.lower_bound(tmp+1);
        //auto a = lower_bound(s.begin(), s.end(), tmp+1);
        if (a == s.end())
        {
            s.insert(tmp);
        }
        else
        {
            s.erase(a);
            s.insert(tmp);
        }
    }
    cout << s.size();
}