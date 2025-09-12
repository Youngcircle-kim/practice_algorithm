#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // t초: 건너는 queue 안에 첫번째 트럭이 들어옴 => 무게에서 트럭 무게를 뺀다.
    // t+1초: 건너간 트럭이 있으면 제외, 다음 트럭의 무게와 현재 버틸 수 잇는 무게를 비교
    queue<int> q1; // 지난 queue
    queue<pair<int,int>> q2, dump, emptyQ; // 건너는 queue
    int t = 0;
    int v_idx = 0;
    while(true){
        if(q1.size() == truck_weights.size()) return t;
        ++t;
        int cur = truck_weights[v_idx];
        
        while(!q2.empty()){
            auto inc = q2.front();
            q2.pop();
            if(inc.second >= bridge_length){
                weight += inc.first;
                q1.push(inc.first);
            } else {
                inc.second++;
                dump.push(inc);
            }
        }
        if(!dump.empty()){
            q2.swap(dump);
            dump.swap(emptyQ);
        }
        
        if(weight >= cur && v_idx < truck_weights.size()){
            q2.push({cur, 1});
            weight -= cur;
            v_idx += 1;
        }
    }
}
