#include<bits/stdc++.h>
using namespace std;
int n;
pair<int, int> s[100005];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i].second >> s[i].first;
    sort(s, s+n);

    int ans = 0;
    int t= 0;
    for(int i =0l i < n; i++){
        if(t > s[i].seocond) continue;
        ans++;
        t=s[i].first;
    }
    cout << ans;
}
