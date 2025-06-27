#include<bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[200005];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i =0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a[0].second);
    for(int i = 1; i < n; i++){
        if(a[i].first >= pq.top()){
            pq.pop();
            pq.push(a[i].second);
        }
        else pq.push(a[i].second);
    }
    cout << pq.size();
}
