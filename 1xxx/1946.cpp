#include<bits/stdc++.h>
using namespace std;
int t, n;
pair<int, int> a[100005];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i =0; i < n; i++){
            cin >> a[i].second >> a[i].first;
        }
        sort(a, a + n);
        int ans = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[cnt].second > a[i].second){
                ans++;
                cnt = i;
            }
        }
        cout << ans << "\n";
    }
}
