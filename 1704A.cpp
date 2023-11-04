/*
 * @Author: lurenjia 
 * @Date: 2022-08-07 14:32:08 
 * @Last Modified by: lurenjia
 * @Last Modified time: 2022-08-07 16:26:59
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

char x[55],y[55];
int main(){
    //这是第一次修改的内容
    int t;
    read(t);
    while(t--) {
        int n,m;
        read(n),read(m);
        memset(x,'\0',sizeof x);
        memset(y,'\0',sizeof y);
        scanf("%s%s",x+1,y+1);
        bool f=1,g=0;
        int i,j;
        for(i=n,j=m;j>1;i--,j--) {
            if(x[i]!=y[j]) f=0;
        }
        for(;i;--i) {if(x[i]==y[1]) g=1;}
        if(f&&g) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
