#include<bits/stdc++.h>
using namespace std;
int m, n;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    vector<int> v(n,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int st = 1;
    int end = v[n-1];
    
    int res = 0;
    while(st <= end){
        int mid = (st + end)/2;
        int cnt = 0;
        for(int i =0; i < n; i++){
            cnt+= v[i]/mid;
        }
        if(cnt<m){
            end = mid -1;
        }else {
            res = mid;
            st = mid + 1;
        }
    }
    cout << res;
}
