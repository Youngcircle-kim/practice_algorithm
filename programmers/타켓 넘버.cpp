#include<bits/stdc++.h>
using namespace std;
int cnt, len, t;
void dfs(int sum, int depth, vector<int> numbers, int target){
    // base condition
    if(depth == numbers.size()){
        if(sum == target){
            cnt++;
        }
        return ;
    }
    dfs(sum + numbers[depth], depth+1, numbers, target);
    dfs(sum - numbers[depth], depth+1, numbers, target);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    cnt = 0;
    dfs(0,0,numbers, target);
    return cnt;
}
