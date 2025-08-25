#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[53][53];
int b[53][53];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) a[i][j] = s[j] - '0';
    }
    for(int i = 0; i< n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) b[i][j] = s[j] - '0';
    }

    int ans = 0;

    for(int i = 0; i <= n-3; i++){
        for(int j =0; j <= m-3; j++){
            if(a[i][j] != b[i][j]) {
                for(int k = i; k < i+3; k++){
                    for(int l = j; l < j+3; l++){
                        a[k][l] = 1 - a[k][l];
                    }
                }
                ans++;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
