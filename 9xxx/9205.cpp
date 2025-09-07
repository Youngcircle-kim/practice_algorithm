#include<bits/stdc++.h>
using namespace std;
int tc, cs; // tc = 테케, cs = 편의점
int sx, sy; // (sx, sy) = 시작 정점
int csx, csy; // 편의점 x, y
int fx, fy; // 페스티벌 x, y
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    while(tc--){
        cin >> cs;
        cin >> sx >> sy;
        vector<pair<int,int>> stores(cs);
        for(int i = 0; i < cs; ++i){
            cin >> stores[i].first >> stores[i].second;
        }
        
        cin >> fx >> fy;

        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        
        vector<int> vis(cs, 0);
        bool isPossible=0;
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();

            if(abs(cur.first - fx) + abs(cur.second-fy) <= 1000){
                isPossible = 1;
                break;
            }
            for(int i = 0; i < cs; ++i){
                if(vis[i]) continue;
                if(abs(cur.first - stores[i].first) + abs(cur.second-stores[i].second) <= 1000){
                    vis[i] = 1;
                    Q.push(stores[i]);
                }
            }
        }
        cout << (isPossible ? "happy\n" : "sad\n");
    }
}
