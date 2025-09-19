#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int n, k;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> s[i];
    int cnt = 0;
    int ans = 0;

    if(s[0]%2 == 1) cnt++;
    int en = 0;

    for(int st = 0; st < n; st++){
        while(en < n-1 && cnt + s[en+1] %2 <= k) {
            en++;
            cnt += s[en] %2;
        }
        ans = max(ans, en - st + 1 - cnt);
        cnt -= s[st] % 2;
    }
    cout << ans;
}
