#include<bits/stdc++.h>
using namespace std;
int n, m;
int mat[10][10];
int vis[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> cctv;
bool OOB(int a, int b){
    return a <0 || a >= n || b <0|| b>= m;
}
void upd(int x, int y, int dir){
    dir %= 4;
    while(1){
        x+= dx[dir];
        y+= dy[dir];
        if(OOB(x,y) || vis[x][y] == 6) return;
        if(vis[x][y] != 0) continue;
        vis[x][y] = 7;
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i =0; i < n; i++){
        fill(mat[i], mat[i] + m, 0);
        fill(vis[i], vis[i] + m, 0);
    }
    int mn = 0;
    for(int x =0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin >> mat[x][y];
            if(mat[x][y] != 0 && mat[x][y] != 6) cctv.push_back({x,y});
            if(mat[x][y] ==0) mn++;
        }
    }
    for(int tmp = 0; tmp < (1 <<(2* cctv.size())); tmp++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                vis[x][y] = mat[x][y];
            }
        }
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++){
            int dir = brute % 4;
            brute /= 4;
            int x, y;
            tie(x,y) = cctv[i];
            if(mat[x][y] == 1){
                upd(x,y,dir);
            }
            else if(mat[x][y] ==2){
                upd(x,y,dir);
                upd(x,y,dir+2);
            }
            else if(mat[x][y] ==3) {
                upd(x,y,dir);
                upd(x,y,dir+1);
            }
            else if(mat[x][y] == 4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }
            else {
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
        }
        int val = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                val += (vis[x][y] == 0);
            }
        }
        mn = min(mn, val);
    }
    cout << mn;
}
