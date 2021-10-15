#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int count=0;
    while(t--)
    {
        count++;
        int n;
        cin>>n;
        int a[n][n];
        int row=0,col=0,dia=0;
        for(int i=0; i<n; i++)
        {
            unordered_map<int,int>m;
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                if(i==j)
                {
                    dia+=a[i][j];
                }
                m[a[i][j]]++;
            }
            for(auto x:m)
            {
                if(x.second>1)
                {
                    row++;
                    break;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            unordered_map<int,int>m;
            for(int j=0; j<n; j++)
            {
                m[a[i][j]]++;
            }
            for(auto x:m){
                if(x.second>1)
                {
                    col++;
                    break;
                }
            }
        }
        
        cout<<"Case #"<<count<<": "<<dia<<" "<<row<<" "<<col<<endl;
    }
}
