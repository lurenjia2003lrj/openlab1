/*
 * @Author: lurenjia 
 * @Date: 2022-08-20 20:15:09 
 * @Last Modified by: lurenjia
 * @Last Modified time: 2022-08-21 00:20:19
 */
#include <bits/stdc++.h>
using namespace std;
#define Isdigit (ch>='0'&&ch<='9')
typedef long long L;
typedef unsigned long long UL;

template<class T>
void read(T &x){
    x=0;int f=1;
    char ch=getchar();
    while(!Isdigit) {if(ch=='-') f=-1;ch=getchar();}
    while(Isdigit) x=x*10+ch-'0',ch=getchar();x*=f;
}

struct G{
    int to,nxt,p,q;
}a[400005];
int head[200005],_cnt;
inline void addedge(int x,int y,int p,int q) {a[++_cnt].to=y;a[_cnt].nxt=head[x];a[_cnt].p=p;a[_cnt].q=q;head[x]=_cnt;}

L pre[400005];
int r[400005];

void dfs(int x,int f,int deep,L p,L q) {
    // cout<<x<<' '<<f<<' '<<deep<<endl;
    if(deep!=0) {
        pre[deep]=pre[deep-1]+q;
        // cout<<"deep:";
        // for(int i=0;i<=deep;++i) cout<<pre[i]<<' ';
        // cout<<endl;
        r[x]=upper_bound(pre+1,pre+deep+1,p)-pre-1;
        // cout<<p<<' '<<lower_bound(pre+1,pre+deep+1,p)-pre<<' '<<endl;
    }
    for(int i=head[x];i;i=a[i].nxt) {
        int y=a[i].to;
        if(y==f) continue;
        dfs(y,x,deep+1,p+a[i].p,a[i].q);
    }
}
int main(){
    //freopen("1.in","r",stdin);
    int t;
    read(t);
    while(t--) {
        memset(head,0,sizeof head);
        _cnt=0;
        int n;
        read(n);
        for(int i=2;i<=n;++i) {
            int y,p,q;
            read(y),read(p),read(q);
            addedge(i,y,p,q);addedge(y,i,p,q);
        }
        dfs(1,0,0,0,0);
        for(int i=2;i<=n;++i) printf("%d ",r[i]);
        putchar('\n');
    }
    return 0;
}
