#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool solve(ll x, const vector<int>& times ,ll n){
    ll cur = 0;
    for(int t: times) cur += x / t;
    return cur >= n;
}

ll solution(int n, vector<int> times) {
    sort(times.begin(), times.end());  
    ll st = 0;
    ll en = (ll)times.back() * n; 
    while(st < en){
        ll mid = st + (en-st)/2;
        if(solve(mid, times, n)) en = mid;
        else st = mid+1;
        
    }
    return st;
}
