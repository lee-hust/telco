#include <bits/stdc++.h>
#define ft(i,x,y) for(int i=x; i<=y; i++)
#define ftd(i,x,y) for(int i=x; i>=y; i--)
using namespace std;
int n,m;
int a[21];
int x[21];
int sum;
int res;
int s[21];

void Try(int index){
    if(index > n){

        if(sum == m) res ++;
        return;
    }
    int limit = (m-sum-s[index+1]) / a[index];
    ft(value,1,limit){
        x[index] = value;
        long long prev_sum = sum;
        sum += x[index]*a[index];
        Try(index+1);

        sum = prev_sum;
        x[index] = 0;

    }
}
int main() {
    cin>>n>>m;
    ft(i,1,n){
        cin>>a[i];
    }

    ftd(i,n,1){
        s[i] = s[i+1] + a[i];
    }

    Try(1);
    cout<< res;
    return 0;
}
