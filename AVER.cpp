#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct data
{
    long long s,id;
};
data a[100001];
long long n,k,i,x,m[100001],c,d,g,vt;
bool cmp(data a,data b)
{
    return (a.s<b.s || (a.s==b.s && a.id<b.id));
}
int main()
{
    ifstream fi ("aver.inp");
    fi >>n>>k;
    for (i=1;i<=n;i++)
    {
        fi >>x;
        x=x-k;
        a[i].s=a[i-1].s+x;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    m[1]=a[1].id;
    //for (i=1;i<=n;i++) cout <<a[i].id<<" ";cout <<endl;
    for (i=2;i<=n;i++) m[i]=min(m[i-1],a[i].id);
    //for (i=1;i<=n;i++) cout <<m[i]<<" ";
    //cout <<endl;
    for (i=2;i<=n;i++)
    {
        d=1,c=i-1,vt=0;
        do
        {
            g=(d+c)/2;
            if (m[g]<a[i].id)
            {
                c=g-1;
                vt=g;
            }
            else d=g+1;
        }while (d<=c);
        if (vt!=0)
        {
            x=max(x,a[i].id-m[vt]);
            k=m[vt]+1;
        }
    }
    ofstream fo ("AVER.out");
    fo <<x<<" "<<k;
    return 0;
}
