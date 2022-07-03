#include<bits/stdc++.h>
using namespace std;
int arr[2000][2000],check[2000][2000],union_find[2000][2000],way1[4]={0,0,-1,1},way2[4]={-1,1,0,0},r,c,parent[4000000];
vector<pair<int,int> >v;

void cnt_lake(){
    int num=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0&&check[i][j]==0){
                check[i][j]=1;
                union_find[i][j]=num;
                queue<pair<int,int> >q;
                q.push({i,j});
                while(!q.empty()){
                    int row=q.front().first, col=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_row=row+way1[k], next_col=col+way2[k];
                        if(next_row>=0&&next_row<r&&next_col<c&&next_col>=0&&arr[next_row][next_col]==0&&check[next_row][next_col]==0){
                            union_find[next_row][next_col]=num;
                            check[next_row][next_col]=1;
                            q.push({next_row,next_col});
                        }
                    }
                }
                num++;
            }
        }
    }
    for(int i=1;i<num;i++) parent[i]=i;
    return;
}

int getParent(int x){
    if(x==parent[x]) return x;
    else return parent[x]=getParent(parent[x]);
}

void unionParent(int a,int b){
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else if(a>b) parent[a]=b;
    return;
}

bool findParent(){
    int a = union_find[v[0].first][v[0].second],b = union_find[v[1].first][v[1].second];
    a=getParent(a);
    b=getParent(b);
    if(a==b) return true;
    else return false;
}
queue<pair<int,int> >q2;

void bfs(){
    queue<pair<int,int> >q1;
    while(!q2.empty()){
        q1.push({q2.front().first,q2.front().second});
        q2.pop();
    }
    while(!q1.empty()){
        int row=q1.front().first,col=q1.front().second;
        q1.pop();
        for(int i=0;i<4;i++){
            int next_row=row+way1[i], next_col=col+way2[i];
            if(next_row>=0&&next_row<r&&next_col<c&&next_col>=0&&arr[next_row][next_col]==1){
                union_find[next_row][next_col]=union_find[row][col];
                arr[next_row][next_col]=0;
                for(int j=0;j<4;j++){
                    int nr=next_row+way1[j],nc=next_col+way2[j];
                    if(nr>=0&&nr<r&&nc<c&&nc>=0&&union_find[nr][nc]!=union_find[next_row][next_col]&&union_find[nr][nc]!=0){
                        unionParent(union_find[nr][nc],union_find[next_row][next_col]);
                    }
                }
                q2.push({next_row,next_col});
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        string a;
        cin>>a;
        for(int j=0;j<c;j++){
            if(a[j]=='X'){
                arr[i][j]=1;
            }
            else{
                if(a[j]=='L') v.push_back({i,j});
                arr[i][j]=0;
                q2.push({i,j});
            }
        }
    }
    cnt_lake();
    int day=0;
    while(!findParent()){
        bfs();

        day++;
    }
    cout<<day;
    return 0;
}
