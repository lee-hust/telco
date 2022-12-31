#include <bits/stdc++.h>

using namespace std;
int n, m;
int A[11][31];
int conflict[31][31];
int res = -1;
int x[31];
int Max = -1;
vector<int>P[11];
void Check(int teacher, int course ){
    if(A[teacher][course] == false) return false;
    for(int _course : P[teacher]){
        if(conflict[-course][course] == true) return false;
    }
    return true;
}
void Try(int course_index) {
    if (course_index > n) {
        for (int i = 1; i <= m; i++) {
            if (P[i].size() < 1) return;// dieu kien so non giao vien day > 1
        }
        for (int i = 0; i <= m; i++) {
            for (int course: P[i]) {
                for (int _course: P[i]) {
                    if (course != _course && conflict[course][_course] == true) return;
                }
            }
        }


        for (int i = 1; i <= m; i++) {
            Max = max(Max, (int) P[i].size());
        }
        res = min(res, Max);
        return;
    }
    for(int teacher_index = 1; teacher_index <= m; teacher_index++){
        x[course_index] = teacher_index;
        P[teacher_index].push_back(course_index);

        int prev_Max = Max;
        if(A[teacher_index][course_index] == true)
            Try(course_index+1);

        Max = prev_Max;
        x[course_index] = 0;
        P[teacher_index].pop_back();

    }
}
int main() {
    cin>>m>>n;
    for(int i=1; i<=m; i++){
        int k;
        cin >> k;
        while (k--){
            int c;
            cin>>c;
            A[i][c] = true;
        }
    }
    int k;
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        conflict[a][b] = true;
        conflict[b][a] = true;
    }
    Try();
    cout<< res;

    return 0;
}
