#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[200005];
int cnt[100005];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
       cin >> a[i]; 
    }
    int mx = 0;
    int en = 0;
    ++cnt[a[en]];
    for(int st = 0; st < n; st++){
        while(en+1 != n && cnt[a[en+1]] < k){
            en++;
            cnt[a[en]]++;
        }
        mx = max(mx, en-st+1);
        cnt[a[st]]--;
    }
    cout << mx;
}
