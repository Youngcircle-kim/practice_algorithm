#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0, mx = 0;
int s[10], w[10];
void solve(int a){
    // base condition
    if(a == n){
        mx = max(mx, cnt);
        return;
    }
    // a번째 계란의 내구도가 0이하거나 모든 계란을 다 했을 때
    if(s[a] <= 0 or cnt == n-1){
        solve(a+1);
        return ;
    }
    // brute-force로 모든 계란 치기
    for(int t = 0; t < n; t++){ // t번째 계란을 내려치고 싶다
        if(t == a or s[t] <= 0) continue;
        // 내구도 빼기
        s[a] -= w[t];
        s[t] -= w[a];
        if(s[a] <= 0) cnt++;
        if(s[t] <= 0) cnt++;
        solve(a+1);
        // backtracking 후 복귀
        if(s[a] <= 0) cnt--;
        if(s[t] <= 0) cnt--;
        s[a] += w[t];
        s[t] += w[a];
    }

}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // constraints
    // 1 <= n <= 8
    // 1 <= s_i, w_i <= 300
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> w[i];
    }
    solve(0);
    cout << mx;
}
