#include<bits/stdc++.h>
using namespace std;
int k;
int a[100004][5];
long long d[100004][5];
vector<long long> v;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> k;
        if(k==0) break;
        for(int i = 1; i <= k; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        
        d[1][1] = 987654321;
        d[1][2] = a[1][2];
        d[1][3] = a[1][3] + d[1][2];

        for(int i = 2; i <= k; i++){
            d[i][1] = min(d[i-1][1], d[i-1][2]) + a[i][1];
            d[i][2] = min(min(d[i-1][1], d[i-1][2]), min(d[i][1], d[i-1][3])) + a[i][2];
            d[i][3] = min(min(d[i-1][2], d[i-1][3]),d[i][2]) + a[i][3];
        }
        v.push_back(d[k][2]);
    }
    int j =1;
    for(auto e : v){
        cout << j << '.' << " " << e << "\n";
        j++;
    }
}
