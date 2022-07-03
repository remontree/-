#include<bits/stdc++.h>
#define INF 123456789
using namespace std;

/**
1
3 100 3
1 2 1 1
2 3 1 1
1 3 3 30
**/

struct Edge{
    int from;
    int to;
    int cost;
    int time;
    Edge(int a,int b,int c,int d){
        from = a;
        to = b;
        cost = c;
        time = d;
    }
};

vector<Edge>air;
int dist[101][10001]={{0,}};
void ballman(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++) dist[i][j] = i==1?0:INF;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<air.size();j++){
            int from = air[j].from, to = air[j].to, cost = air[j].cost, time = air[j].time;
            for(int k=0;k+cost<=m;k++){
                if(dist[from][k]==INF)continue;
                if(dist[from][k]+time<dist[to][k+cost]) dist[to][k+cost]=dist[from][k]+time;
            }

        }
    }
    int ans = INF;

    for(int i=1;i<=m;i++) ans=min(ans,dist[n][i]);
    if(ans==INF)printf("Poor KCM\n");
    else printf("%d\n",ans);
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        air.clear();
        for(int j=0;j<k;j++){
            int u,v,c,d;
            scanf("%d%d%d%d",&u,&v,&c,&d);
            air.push_back(Edge(u,v,c,d));
        }
        ballman(n,m);
    }
    return 0;
}
