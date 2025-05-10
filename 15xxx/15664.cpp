#include<bits/stdc++.h>
using namespace std;
int n, m;
int num[10];
int seq[10];
void func(int cnt, int k){
    if(cnt == m){
        for(int i = 0; i < m; i++) cout << seq[i] <<" ";
        cout << "\n";
        return ;
    }
    int pre = 0;
    for(int i = k; i < n; i++){
        if(pre != num[i]){
            seq[cnt] = num[i];
            pre = seq[cnt];
            func(cnt+1, i+1);
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // constraints
    // 1 <= m <= n <= 8
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num, num +n);
    func(0,0);
}
