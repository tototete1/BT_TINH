#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
long long i,n,d,c,g,vt,j;
long long a[45001],b[45001];
int main()
{
    ifstream fi ("thadieu.inp");
    ofstream fo ("thadieu.out");
    fi >>n;
    for (i=1;i<=n;i++)
    {
        fi >>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n,greater<int>());
    for (i=1;i<=n;i++)
    {
        d=1,c=i;
        do
        {
            g=(d+c)/2;
            if (b[g]>=a[i])
            {
                vt=g;
                d=g+1;
            }
            else c=g-1;
        }while (d<=c);
        fo <<vt<<endl;
    }
    return 0;
}
