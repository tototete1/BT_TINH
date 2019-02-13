#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
long long n,i,x,r,l=1000001;
long long a[1000001];
int main()
{
    freopen("linhkien.inp","r",stdin);
    scanf("%lld",&n);
    for (i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        r=a[i]/x;
        l=min(r,l);
    }
    ofstream fo ("linhkien.out");
    fo<<l;
    return 0;
}
