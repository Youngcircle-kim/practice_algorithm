#include<bits/stdc++.h>
using namespace std;
int s[304];
int d[304][3];
int k, n;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for(int i = 1; i < k+1; i++){
        cin >> s[i];
    }
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];
    for(int i = 3; i < k+1; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + s[i];
        d[i][2] = d[i-1][1] + s[i];
    }

    cout << max(d[k][1], d[k][2]);
}
