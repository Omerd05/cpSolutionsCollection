#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;
typedef long double ll;
#define pb push_back

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> arr(N); 
    vector<pair<int,int>> subseq(N,{1,N});//(N, 1);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if (N == 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    map<int, int> seen;
    for (int i = N - 1; i > -1; i--) {
        if (seen.count(arr[i]+1)) {
            subseq[i].first = subseq[seen[arr[i]+1]].first + 1;
            subseq[i].second = seen[arr[i]+1];
        }
        seen[arr[i]] = i;
    }
    int maxIdx = 1;
    for (int i = 0; i < N; i++) {
        if (subseq[maxIdx].first < subseq[i].first) {
            maxIdx = i;
        }
    }
    cout << subseq[maxIdx].first << '\n';
    int idx = maxIdx;
    while (idx < N) {
        cout << idx + 1 << " ";
        idx = subseq[idx].second;
    }
}









/*
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    set<pair<int, int>> seen;
    for (int i = 0; i < N; i++) {
        if (seen.count({ arr[i] - 1,0 }) || seen.count({ arr[i] - 1,1 })) {
            seen.insert({ arr[i],1 });
            seen.erase({ arr[i],0 });
        }
        else if (seen.count({ arr[i],0 }) == 0)seen.insert({ arr[i],0 });
    }
    auto it = seen.begin();
    int ans = 1, tmp = 1;
    vector<int> idxs;
    while (it != seen.end()) {
        if (it->second) {
            tmp += 1;
        }
        else {
            tmp = 1;
        }
        ans = max(ans, tmp);
        it++;
    }
    cout << ans << '\n';
*/