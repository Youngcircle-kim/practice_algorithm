#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int dist[103][103];
int solution(vector<vector<int> > maps)
{
    int n = maps.size()-1;
    int m =  maps[0].size()-1;
    queue<pair<int,int>> Q;
    Q.push({0,0});
    dist[0][0] =1;
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        if(dist[n][m] != 0){
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            if(dist[nx][ny] || !maps[nx][ny]) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    if(!dist[n][m]){
        return -1;
    }
    return dist[n][m];
}
