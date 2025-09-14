#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, mx;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> mx;
    sort(a, a+n);
    ll lo = 1;
    ll en = a[n-1];
    while(lo < en){
        ll mid = (lo + en + 1)/2;
        ll cur = 0;
        for(auto e : a){
            if(e <= mid) cur += e;
            else cur += mid;
        }
        
        if(cur <= mx) lo = mid;
        else en = mid-1;
    }
    cout << lo;
}
