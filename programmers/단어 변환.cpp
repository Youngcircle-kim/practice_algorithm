#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
bool vis[51];
int solution(string begin, string target, vector<string> words) {
    fill(vis, vis + words.size(), 0);
    queue<pair<string,int>> Q;
    Q.push({begin, 0});
    // BFS
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur.X == target){
            return cur.Y;
        }
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            int cnt = 0;
            // 단어 체크
            for(int j = 0; j < cur.X.length(); j++){
                if(word[j] != cur.X[j]) cnt++;
            }
            if(cnt != 1) continue;
            if(vis[i]) continue;
            Q.push({word, cur.Y+1});
            vis[i] =1;
        }        
    }
    return 0;
}
