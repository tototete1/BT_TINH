#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
long long n,m;
long long a[100001];
bool check(long long x)
{
    int t=1,j=1,i;
    for (i=2;i<=n;i++)
    {
        if (a[i]>=a[t]+x)
        {
            t=i;
            j++;
            if (j==m) return true;
        }
    }
    return false;
}
int main()
{
    long long i,d,c,vt=1e9,g;
    freopen("danbo.inp","r",stdin);
    ofstream fo ("danbo.out");
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    d=1,c=1e9;
    long long x=1e9;
    do
    {

        g=(d+c)/2;
        if (check(g))
        {
            vt=g;
            d=g+1;
        }
        else c=g-1;
    }while (d<=c);
    fo <<vt;
    return 0;
}
