/*
 * @Author: lurenjia 
 * @Date: 2022-08-07 15:06:40 
 * @Last Modified by: lurenjia
 * @Last Modified time: 2022-08-07 16:26:47
 */
#include <bits/stdc++.h>
using namespace std;
#define Isdigit (ch>='0'&&ch<='9')
typedef long long L;
typedef unsigned long long UL;

namespace IO{
    const int siz=(1<<21)+1;
    char ibuf[siz+1],obuf[siz+1],qu[65];
    char *is=ibuf,*it=ibuf,*os=obuf,*ot=obuf+siz-1;
    #define gec (is==it?(it=(is=ibuf)+fread(ibuf,1,siz,stdin),(is==it?EOF:*is++)):*is++)
    template<class T>
    inline void read(T& x){
        x=0;int f=1;
        char ch=gec;
        while(!Isdigit) {if(ch=='-') f=-1;ch=gec;}
        while(Isdigit) x=x*10+ch-'0',ch=gec;x*=f;
    }
    inline void flush(){
        fwrite(obuf,1,os-obuf,stdout);
        os=obuf;
    }
    inline void puc(char x){
        if(os==ot)flush();
        *os++=x;
    }
    template<class T>
    inline void print(T x,bool flag=false){
        if(x<0) puc('-'),x*=-1;
        if(!x) puc('0');
        int qr=0;
        while(x) qu[++qr]=x%10+'0',x/=10;
        while(qr) puc(qu[qr--]);
        flag? puc('\n'):puc(' ');
    }
    class flusher{
        public:
        ~flusher(){
            flush();
        }
    }io_flusher;
};
using IO::read;
using IO::print;

int main(){
    //freopen("1.in","r",stdin);
    int t;
    read(t);
    while(t--) {
        L n,m,x;
        L sum1=0,sum2=0;
        int pos1=0,pos2=0;
        int tag=0;
        read(n),read(m);
        for(int i=1;i<=n;++i) {
            L sump=0;
            for(int j=1;j<=m;++j) {
                read(x);
                sump+=x*j;
            }
            //cout<<sum1<<' '<<sum2<<' '<<pos1<<' '<<pos2<<' '<<sump<<' '<<tag<<endl;
            if(sum1==0) sum1=sump,pos1=i;
            else if(sump==sum1) tag=1;
            else if(sum2==0) sum2=sump,pos2=i;
            else tag=2;
        }
        if(tag==2) print(pos1),print(sum1-sum2,1);
        else print(pos2),print(sum2-sum1,1);
    }
    return 0;
}