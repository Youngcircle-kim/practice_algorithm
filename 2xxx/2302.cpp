#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int d[43];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    vector<int> v;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    v.push_back(0);
    for(int i = 0; i < m; i++){
        cin >> k;
        v.push_back(k);
    }
    v.push_back(n+1);

    for(int i = 3; i <= n; i++) d[i] = d[i-1] + d[i-2];

    int sol = 1;
    for(int i = 1; i <v.size(); i++) sol *= d[v[i] - v[i-1] -1];
    cout << sol;
}
