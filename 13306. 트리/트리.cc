#include<bits/stdc++.h>
using namespace std;
int parent[200001],arr[200001];
vector<tuple<int,int,int> >v;
stack<bool>s;
int getParent(int x){
    if(parent[x]==x)return x;
    else return parent[x]=getParent(parent[x]);
}

void unionParent(int a,int b){
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

bool findParent(int a,int b){
    a=getParent(a);
    b=getParent(b);
    if(a==b) return true;
    else return false;
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n-1;i++){
        int a;
        scanf("%d",&a);
        arr[i+1]=a;
    }
    for(int i=1;i<=n-1+q;i++){
        int a;
        scanf("%d",&a);
        if(a==0){
            int b;
            scanf("%d",&b);
            v.push_back({a,b,0});
        }
        else{
            int b,c;
            scanf("%d%d",&b,&c);
            v.push_back({a,b,c});
        }
    }
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=v.size()-1;i>=0;i--){
        int a=get<0>(v[i]),b=get<1>(v[i]),c=get<2>(v[i]);
        if(a==1){
            s.push(findParent(b,c));
        }
        else{
            unionParent(b,arr[b]);
        }
    }
    while(!s.empty()){
        if(s.top()==false) printf("NO\n");
        else printf("YES\n");
        s.pop();
    }
    return 0;
}
