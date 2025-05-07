#include<bits/stdc++.h>
using namespace std;
int n;
int mat[66][66];
bool chk(int n, int x, int y){
    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            if(mat[i][j] != mat[x][y]) return false;
        }
    }
    return true;
}
void func(int n, int x, int y){
    if(chk(n,x,y)){
        cout << mat[x][y];
        return ;
    }
    cout << "(";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            func(n/2, x + i*n/2, y + j*n/2);
        }
    }
    cout << ")";
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            mat[i][j] = s[j] - '0';
        }
    }

    func(n,0,0);
}
