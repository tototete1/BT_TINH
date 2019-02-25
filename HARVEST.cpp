#include <bits/stdc++.h>

using namespace std;
long long n,i,s;
long long a[1000003],L[1000003],R[1000003];
int main()
{
    ifstream fi ("harvest.inp");
    fi >>n;
    for (i=1;i<=n;i++) fi >>a[i];
    for (i=3;i<=n;i++) L[i]=max(L[i-1],a[i]+a[i-1]+a[i-2]);
    for (i=n-2;i>0;i--) R[i]=max(R[i+1],a[i]+a[i+1]+a[i+2]);
    ofstream fo ("harvest.out");
    for (i=2;i<=n-2;i++) s=max(s,L[i-2]+a[i-1]+a[i]+a[i+1]+R[i+2]);
    fo <<s;
    return 0;
}
