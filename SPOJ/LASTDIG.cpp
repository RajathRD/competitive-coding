
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{int t,a,p,b,q;
    int n[10]={1,1,4,4,2,1,1,4,4,2};
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        if(a%10==1||b==0)
            cout<<"1"<<endl;
        else if(a%10==5||a%10==6||a%10==0)
            cout<<(a%10)<<endl;
        else
           { q=b%n[a%10];
           if(q==0)
           q=n[a%10];
            p=1;
            for(int j=0;j<q;j++)
            {
                p=p*(a%10);
            }
            cout<<(p%10)<<endl;
        }
    }
     return 0;
}
