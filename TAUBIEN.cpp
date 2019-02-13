#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
long long a[10001],cx[10001];
int main()
{
    long long n,m,i,s,j,day=0;
    freopen("taubien.inp","r",stdin);
    ofstream fo ("taubien.out");
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n,greater<int>());
    for (i=1;i<=n;i++)
    {
        s=a[i];
        if (cx[i]==0)
        {

            cx[i]=1;
            for (j=1;j<=n;j++)
            {
                if (cx[j]==0)
                {
                    if (s+a[j]<=m)
                    {
                        s=s+a[j];
                        cx[j]=1;
                    }
                }
            }
            day++;
        }

    }
    fo <<day;
    return 0;
}
