#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i = 1; i < n; i++){
        int curSum = 0;
        for(int j = i; j < n; j++){
            curSum += j;
            if(curSum > n) break;
            if(curSum == n) answer++;
        }
    }
    return answer;
}
