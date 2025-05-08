#include<bits/stdc++.h>
using namespace std;
int l, c;
int cnt1, cnt2; // 모음, 자음 cnt
char arr[17];
char ans[17];
bool vis[17];
void func(int cnt, int k){
    if(cnt == l){
        cnt1 = 0, cnt2 = 0;
        for(int i =0; i<l; i++){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i'|| ans[i] == 'o' || ans[i] == 'u') cnt1++;
            else cnt2++;
        }
        if(cnt1 > 0 && cnt2 >1){
            for(int i =0; i <l; i++) cout << ans[i];
            cout << "\n";
            return ;
        }
        return ;
    }
    for(int i = k; i < c; i++){
        if(!vis[i]){
            vis[i] = 1;
            ans[cnt] = arr[i];
            func(cnt+1, i);
            vis[i] =0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> c;
    fill(arr, arr+16, 'z');
    for(int i = 0; i < c; i++) cin >> arr[i];
    sort(arr, arr+16);
    func(0, 0);
}
