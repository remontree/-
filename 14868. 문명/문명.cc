#include<bits/stdc++.h>
using namespace std;
#define INF 123456789
int parent[100001],arr[3000][3000],check[3000][3000],p[3000][3000],way1[4]={-1,1,0,0},way2[4]={0,0,-1,1},n,k;
int bfs(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(check[i][j]==0&&arr[i][j]==1){
                queue<pair<int,int> >q;
                q.push({i,j});
                check[i][j]=1;
                ans++;
                p[i][j]=ans;
                while(!q.empty()){
                    int row=q.front().first,col=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int y=row+way1[k],x=col+way2[k];
                        if(y>=1&&y<=n&&x>=1&&x<=n&&check[y][x]==0&&arr[y][x]==1){
                            check[y][x]=1;
                            q.push({y,x});
                            p[y][x]=ans;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x]=getParent(parent[x]);
}

void unionParent(int a,int b){
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

bool findParent(int cnt){
    int comp=parent[1];
    for(int i=2;i<=cnt;i++){
        if(getParent(i)!=comp){
            return false;
        }
    }
    return true;
}
int main(){
    queue<tuple<int,int,int> >q;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        arr[y][x]=1;
        q.push({0,y,x});
    }
    int cnt=bfs(),day=0;
    for(int i=1;i<=cnt;i++) parent[i]=i;
    if(findParent(cnt)==true){
        printf("0");
        return 0;
    }
    while(!q.empty()){
        int days=get<0>(q.front()), row=get<1>(q.front()), col=get<2>(q.front());
        q.pop();
        if(day!=days){
            if(findParent(cnt)==true){
                printf("%d",days);
                return 0;
            }
            day=days;
        }
        for(int k=0;k<4;k++){
            int y=row+way1[k],x=col+way2[k];
            if(y>=1&&y<=n&&x>=1&&x<=n&&(check[y][x]==0)){
                check[y][x]=1;
                if(p[y][x]==0) p[y][x]=p[row][col];
                else{
                    ///p[y][x]=p[row][col];
                    unionParent(p[y][x],p[row][col]);
                }
                for(int kk=0;kk<4;kk++){
                    int yy=y+way1[kk],xx=x+way2[kk];
                    if(yy>=1&&yy<=n&&xx>=1&&xx<=n&&p[yy][xx]!=0&&p[yy][xx]!=p[y][x]){
                        unionParent(p[yy][xx],p[y][x]);
                    }
                }
                q.push({days+1,y,x});
            }
        }
    }
    return 0;
}
