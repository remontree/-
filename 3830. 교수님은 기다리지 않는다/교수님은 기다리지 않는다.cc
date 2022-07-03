#include<bits/stdc++.h>
using namespace std;

int getParent(int parent[],long long int w[], int x){
    if(parent[x]==x) return x;
    else{
        int a = getParent(parent,w,parent[x]);
        w[x] = w[x]+w[parent[x]]; /// 만약 부모가 새로 갱신 되면 그에 맞게 무게 값 변경
        parent[x]=a; /// 경로 압축
        return a;
    }
}
void unionParent(int parent[],long long int w[],int a,int b,long long int c){
    int aa,bb;
    aa=getParent(parent,w,a); /// a의 부모 값
    bb=getParent(parent,w,b);/// b의 부모 값
    parent[aa]=bb;
    c=-c;
    w[aa] = (w[b]+c-w[a]);
}

bool findParent(int parent[],long long int w[],int a,int b){
    a=getParent(parent,w,a);
    b=getParent(parent,w,b);
    if(a==b) return true;
    else return false;
}

int main(){
    int t;
    while(true){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;
        int parent[100001];
        long long int w[100001];
        for(int i=1;i<=n;i++) parent[i]=i,w[i]=0;
        for(int i=1;i<=m;i++){
            char a;
            scanf("\n%c",&a);
            if(a=='!'){
                int b,c,d;
                scanf("%d%d%d",&b,&c,&d);
                unionParent(parent,w,b,c,d);
            }
            else{
                int b,c;
                scanf("%d%d",&b,&c);
                if(findParent(parent,w,b,c)==false){
                    printf("UNKNOWN\n");
                }
                else{
                    long long int ans=w[c]-w[b];
                    printf("%lld\n",ans);
                }
            }
        }
    }
    return 0;
}
