#include <iostream>
#include <cstring>
using namespace std;
char s[100];
long long t,n,s1,x,x1,j,s2,s3,s4,i,r;
long long gcd(long long d,long long z)
{
    if (z==0) return d;
    else return gcd(z,d%z);
}
int main()
{
    cin >>s>>t;
    n=strlen(s);
    i=0;
    s1=0;
    while (s[i]!='.' && i<n)
    {
        s1=s1*10+(s[i]-48);
        i++;
    }
    i++;
    x=n-i;
    x1=n-i-t;
    j=i;
    while (x1--)
    {
        s2=s2*10+(s[j]-48);
        j++;
    }
    j=i;
    while (x--)
    {
        s3=s3*10+(s[j]-48);
        j++;
    }
    x1=t;
    while (x1--)
    {
        s4=s4*10+9;
    }
    x1=n-i-t;
     while (x1--)
    {
        s4=s4*10+0;
    }
    x=s3-s2+s1*s4;
    //cout <<x;
    r=gcd(x,s4);
    s1=x/r;
    s2=s4/r;
    cout <<s1<<"/"<<s2;
    return 0;
}
