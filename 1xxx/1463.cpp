#include<bits/stdc++.h>
using namespace std;
int dist[1000005];
int k;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    dist[1] = 0;
    for(int i = 2; i <= k; i++){
        dist[i] = dist[i-1] + 1;
        if(i%2 == 0) dist[i] = min(dist[i], dist[i/2]+1);
        if(i%3 == 0) dist[i] = min(dist[i], dist[i/3]+1);
    }
    cout << dist[k];
}
