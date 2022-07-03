#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Data{
    int num;
    int index;
}z[100001];
bool cmp(const Data &a,const Data &b){
    if(a.num<b.num) return 1;
    else if(a.num==b.num&&a.index<b.index) return 1;
    else return 0;
}
int main(){
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&z[i].num);
        z[i].index=i+1;
    }
    sort(z,z+n,cmp);
    for(i=0;i<m;i++){
        int a,b,c,j,k=0;
        scanf("%d%d%d",&a,&b,&c);
        for(j=0;j<n;j++){
            if(z[j].index>=a&&z[j].index<=b){
                k++;
            }
            if(k==c){
                printf("%d\n",z[j].num);
                break;
            }
        }
    }
    return 0;
}
