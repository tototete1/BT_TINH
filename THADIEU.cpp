#include <iostream>
#include <fstream>
#define chiadoan 500
using namespace std;
long long n,s,i,doan,vt,j,d,c,res,g;
long long a[1000001],b[91][501];
int main()
{

    ifstream fi ("THADIEU.inp");
    ofstream fo ("thadieu.out");
    fi >>n;
    j=1;
    for (i=1;i<=n;i++)
    {
        fi >>a[i];
        if (i<=500*j)
        {
            b[j][i%501]=a[i];
            if (i==500) j++;
        }
    }
    for (i=1;i<=n;i++)
    {
        s=0;
        doan=(i-1)/500+1;
        vt=(i-1)%500+1;
        for (j=1;j<=doan;j++)
        {
            d=1;
            if (j<doan) c=500;
            else c=vt-1;
            res=c+1;
            while (d<=c)
            {
                g=(d+c)/2;
                if (b[j][g]<a[i]) d=g+1;
                else
                {
                    res=g;
                    c=g-1;
                }
            }
            s+=res-1;
            //fo <<s<<endl;
        }
        fo <<i-s<<endl;
        for (j=vt;j>res;j--) b[doan][j]=b[doan][j-1];
        b[doan][res]=a[i];
    }
    return 0;
}
