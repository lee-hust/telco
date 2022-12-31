#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int > ii;
ii A[100];
int n;
int S;
int mem[100][100];

int Opt(int i, int S){
    if(i < 0 || S <= 0)
        return 0;
    if(mem[i][S] != -1)
        return mem[i][S];
    int res;
    if(A[i].second > S){
        res = Opt(i-1, S);
    }
    else
        res = max((Opt(i-1, S)),A[i].first + Opt(i-1,S-A[i].second));
    mem[i][S] = res;
    return res;
}

int main(){
    memset(mem, -1, sizeof(mem));
    cin >> S;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }
    int res = Opt(n-1, S);
    cout << res;
    return 0;
}
