#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> temp(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            temp[i][j] = ch-'0';
        }
    }
    vector<vector<int>> matrix;
    if (n > m) {
        swap(n, m);
        matrix.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = temp[j][i];
            }
        }
    }
    else {
        matrix = temp;
    }
    if (n > 3) { cout << -1; return 0; }
    if (n == 1) { cout << 0; return 0; }
    
    if (n == 2) {
        vector<int> cols(m);
        int result = 0;
        for (int i = 0; i < m; i++) {
            cols[i] = matrix[0][i] ^ matrix[1][i];
        }

        int f1 = 0; int f2 = 1;

        int last = cols[0];
        for (int i = 1; i < m; i++) {
            
            if (cols[i] ^ last) {
                last = cols[i];
            }
            else {
                f1++;
                last = cols[i] ^ 1;
            }            
        }

        last = cols[0]^1;
        for (int i = 1; i < m; i++) {

            if (cols[i] ^ last) {
                last = cols[i];
            }
            else {
                f2++;
                last = cols[i] ^ 1;
            }
        }

        cout << min(f1, f2);
        return 0;
    }

    if (n == 3) {
        vector<int> cols1(m);
        vector<int> cols2(m);

        for (int i = 0; i < m; i++) {
            cols1[i] = matrix[0][i] ^ matrix[1][i];
            cols2[i] = matrix[1][i] ^ matrix[2][i];
        }

        int f[4] = { 0,1,1,1};
        int last1[2] = {cols1[0],cols1[0]^1};
        int last2[2] = {cols2[0],cols2[0]^1};

        //f1 is no change at start, f2 is changine up col, 
        //f3 changing bottom col and f4 is changing both cols.


        //c%2 decides fixes first col's stage
        // floor(c/2) fixes second col's stage
        for (int c = 0; c < 4; c++) {
            for (int i = 1; i < m; i++) {
                if (cols1[i] ^ last1[c % 2]) {
                    last1[c % 2] = cols1[i];
                }
                else {
                    last1[c % 2] = 1 ^ cols1[i];
                    f[c]++;
                }

                if (cols2[i] ^ last2[c / 2]) {
                    last2[c / 2] = cols2[i];
                }
                else {
                    last2[c / 2] = 1 ^ cols2[i];
                    f[c]++;
                }

                if (last1[c % 2] != cols1[i] && last2[c/ 2] != cols2[i]){// && cols1[i] == cols2[i]) {
                    f[c]--;
                }
            }
            last1[0] = cols1[0]; last1[1] = cols1[0] ^ 1;
            last2[0] = cols2[0]; last2[1] = cols2[0] ^ 1;
        }

        cout<< min(min(f[0], f[1]), min(f[2], f[3]));
        return 0;
    }
}