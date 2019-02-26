#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct data
{
    long long s,id;
};
data a[100001],dem[100001];
bool cmp(data x,data y)
{
    return (x.s<y.s || (x.s==y.s && x.id <y.id));
}
long long n,k,i,s;
int main()
{
    ifstream fi ("NUMBER.inp");
    fi >>n>>k;
    for (i=1;i<=n;i++)
    {
        fi >>a[i].s;
        a[i].s=a[i].s%k;
        a[i].id=i;
    }
    //for (i=1;i<=n;i++) cout <<a[i].s<<" ";
    for (i=1;i<=n;i++)
    {
        dem[a[i].s].s++;
        dem[a[i].s].id=1;
    }

    int x;
    for (i=0;i<k;i++)
    {
        x=i;
        if (dem[x].s>dem[k-x].s && dem[x].id==1)
        {
            if (dem[k-x].s==0 && (x*2)%k==0) s++;
            if (dem[k-x].s==0 && (x*2)%k!=0)s+=dem[x].s;
            if (dem[k-x].s!=0) s+=dem[x].s;
            dem[x].id=0;

        }
        if (dem[x].s<dem[k-x].s && dem[k-x].id==1)
        {
            if (dem[x].s==0 && ((k-x)*2)%k==0) s++;
            if (dem[x].s==0 && ((k-x)*2)%k!=0)s+=dem[k-x].s;
            if (dem[x].s!=0) s+=dem[k-x].s;
            dem[k-x].id=0;
        }
    }
    ofstream fo ("NUMBER.out");
    fo <<s;
    return 0;
}
