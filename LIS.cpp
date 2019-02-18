#include <iostream>

using namespace std;
long long n,i,j,d,c,g,vt,a[100001],b[100001];
int main()
{
    cin >>n;
    for (i=1;i<=n;i++) cin >>a[i];
    b[1]=a[1];
    j=1;
    for (i=2;i<=n;i++)
    {
        d=1,c=j,vt=0;
        do
        {
            g=(d+c)/2;
            if (a[i]>b[g])
            {
                vt=g;
                d=g+1;
            }
            else c=g-1;
        }while (d<=c);
        if (vt<j) b[vt+1]=a[i];
        else
        {
            j++;
            b[j]=a[i];
        }
    }
    cout <<j;
    return 0;
}
