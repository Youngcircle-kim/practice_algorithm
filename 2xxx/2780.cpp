#include<bits/stdc++.h>
using namespace std;
int t, n;
int mod = 1234567;
int d[1003][12];
int a[1003];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 10; i++){
        d[1][i] = 1;
    }
    a[1] = 10;
    for(int i = 2; i < 1001; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0) d[i][j] = d[i-1][7];
            else if(j == 1) d[i][j] = d[i-1][2] + d[i-1][4];
            else if(j == 2) d[i][j] = d[i-1][1] + d[i-1][3] + d[i-1][5];
            else if(j == 3) d[i][j] = d[i-1][2] + d[i-1][6];
            else if(j == 4) d[i][j] = d[i-1][1] + d[i-1][5] + d[i-1][7];
            else if(j == 5) d[i][j] = d[i-1][2] + d[i-1][4] + d[i-1][6] + d[i-1][8];
            else if(j == 6) d[i][j] = d[i-1][3] + d[i-1][5] + d[i-1][9];
            else if(j == 7) d[i][j] = d[i-1][4] + d[i-1][8] + d[i-1][0];
            else if(j == 8) d[i][j] = d[i-1][5] + d[i-1][7] + d[i-1][9];
            else if(j == 9) d[i][j] = d[i-1][6] + d[i-1][8];
            d[i][j] %= mod;
            a[i] += d[i][j];
            a[i] %= mod;
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << a[n] << "\n";
    }
}
