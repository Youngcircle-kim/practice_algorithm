#include<bits/stdc++.h>
using namespace std;
int n, k, w, vv, d[103][100003];

vector<pair<int, int>> v;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    v.push_back({0,0});
    cin >> n >> k;
    for(int i =1; i <=n; i++){
        cin >> w >> vv;
        v.push_back({w,vv});
    }
    fill(d[0], d[0] + n, 0);
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= k; j++){
            int wei = v[i].first;
            int val = v[i].second;
            if(wei > j){
                d[i][j] = d[i-1][j];
            } else {
                d[i][j] = max(d[i-1][j], val + d[i-1][j-wei]);
            }
        }
    }
    cout << d[n][k];
}
