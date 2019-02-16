#include <fstream>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,i,s1,s2,y,d,c,g,vt,s,x;
long long r[1000001],v[1000001],L[1000001],R[1000001];
int main()
{
    freopen("robot.inp","r",stdin);
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=n;i++) scanf("%lld",&r[i]);
    for (i=1;i<=m;i++) scanf("%lld",&v[i]);
    sort(v+1,v+1+m);
    L[1]=0;
    for (i=2;i<=m;i++) L[i]=L[i-1]+(v[i]-v[i-1])*(i-1);
    R[m]=0;
    for (i=m-1;i>0;i--) R[i]=R[i+1]+(v[i+1]-v[i])*(m-i);
    for (i=1;i<=n;i++)
    {
        d=1,c=m,vt=0;
        do
        {
            g=(d+c)/2;
            if (r[i]>=v[g])
            {
                vt=g;
                d=g+1;
            }
            else c=g-1;
        }while (d<=c);
        if (vt==m) y=0;
        s1=L[vt]+(r[i]-v[vt])*vt;
        s2=R[vt+1]+(y)*(m-vt);
        s=s1+s2;
        x=max(s,x);
    }
    freopen("robot.out","w",stdout);
    printf("%lld",x);
    return 0;
}
