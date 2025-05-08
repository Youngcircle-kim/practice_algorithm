#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int r, c;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string mat[1003];
int visF[1003][1003];
int visJ[1003][1003];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Qf={}, Qj ={};
    // constraints
    // 1 <= R, C <= 1_000
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        fill(visF[i], visF[i] + 1002, -1);
        fill(visJ[i], visJ[i] + 1002, -1);
        cin >> mat[i];
    }
    for(int x = 0; x < r; x++){
        for(int y = 0; y < c; y++){
            if(mat[x][y] == 'F'){
                Qf.push({x,y});
                visF[x][y] = 0;
            }
            if(mat[x][y]=='J'){  
                Qj.push({x,y});
                visJ[x][y] = 0;
            }
        }
    }
    
    while(!Qf.empty()){
        auto cur = Qf.front(); Qf.pop(); 
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx <0 || nx >= r || ny < 0 || ny >= c) continue;
            if(mat[nx][ny] == '#') continue;
            if(visF[nx][ny]>=0) continue;
            visF[nx][ny] = visF[cur.X][cur.Y] + 1;
            Qf.push({nx,ny});
        }
    }
    
    bool isEscape = 0;
    
    while(!Qj.empty()){
        auto cur = Qj.front(); Qj.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx >= r || nx < 0 || ny >= c || ny <0){
                cout << visJ[cur.X][cur.Y]+1;
                isEscape = 1;
                return 0;
            }
            if(mat[nx][ny] == '#') continue;
            if(visJ[nx][ny]>=0) continue;
            if(visF[nx][ny] != -1 && visF[nx][ny] <=visJ[cur.X][cur.Y]+1) continue;
            visJ[nx][ny] = visJ[cur.X][cur.Y] +1;
            Qj.push({nx,ny});
        }
    }
    
    if(!isEscape) cout << "IMPOSSIBLE";
    return 0;
}
