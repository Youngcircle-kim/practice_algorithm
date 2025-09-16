#include<bits/stdc++.h>
using namespace std;
int n,d,k,c;
int a[30005], cnt[30005];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int mx = 0;
    for(int st = 0; st < n; st++){
        int tot = 0;
        int rec = 0;
        int en = st-1;

        while(rec <k){
            en++;
            if(en == n) en = 0;
            if(!cnt[a[en]]) tot++;
            cnt[a[en]]++;
            rec++;
        }
        if(!cnt[c]) tot++;
        mx = max(mx, tot);
        fill(cnt, cnt+d+5, 0);
    }
    cout << mx;
}
