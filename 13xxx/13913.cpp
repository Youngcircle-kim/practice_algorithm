#include<bits/stdc++.h>
using namespace std;
int dist[200003];
int n, k;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist + 200002, -1);
    // constraints
    // 0 <= n,k <= 100_000
    cin >> n >> k;    
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, 2*cur}){
            if(nxt <0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1;
            Q.push(nxt);
        }
        if(dist[k] != -1) break;
    }
    cout << dist[k] << "\n";
    stack<int> s;
    while(k != n){
        s.push(k);
        if(k-1 >= 0&&dist[k] == dist[k-1] +1){
            k = k-1;
        }
        else if (k+1 <= 100000&&dist[k] == dist[k+1] +1){
            k = k+1;
        }
        else if (k%2 == 0 && dist[k] == dist[k/2] + 1){
            k = k/2;
        }
    }
    s.push(n);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
