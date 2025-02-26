#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>>v(n,vector<long long>(m));
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    int dr[]={-1,0,1};
    int dc[]={1,1,1};
    vector<vector<long long>>dp(n,vector<long long>(m,0));
    long long maxi=0;
    for(long long i=0;i<n;i++)
    {
        dp[i][m-1]=v[i][m-1];
    }
    for(long long j=m-2;j>=0;j--)
    {
        for(long long i=n-1;i>=0;i--)
        {
            long long ans=0;
            for(int k=0;k<3;k++)
            {
                long long newr=i+dr[k];
                long long newc=j+dc[k];
                if(newr>=0 && newr<n)
                {
                    ans=max(ans,dp[newr][newc]);
                }
            }
            dp[i][j]=v[i][j]+ans;
            maxi=max(maxi,dp[i][j]);
        }
    }
    cout<<"Maximum gold obtain "<<maxi<<endl<<endl;
    queue<pair<int,pair<int,pair<int,pair<int,string>>>>>q;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(dp[i][j]==maxi)
           {
              string h="{"+to_string(i)+ ","+ to_string(j)+"}";
              q.push({v[i][j],{maxi,{i,{j,h}}}});
           }    
        
        }
    }
    vector<string>str;
    while(!q.empty())
    {
       int value=q.front().first;
       int maxi=q.front().second.first;
       int row=q.front().second.second.first;
       int col=q.front().second.second.second.first;
       string p=q.front().second.second.second.second;
       int req=maxi-value;
       q.pop();
       if(col==m-1)
       {
           str.push_back(p);
       }
       else{
       for(int w=0;w<3;w++)
        {
           int newr=row+dr[w];
           int newc=col+dc[w];
           if(newr>=0 && newr<n && newc>=0 && newc<m)
           {
                if(dp[newr][newc]==req)
                {
                     string h=p+" -> "+"{"+to_string(newr)+ ","+ to_string(newc)+"}";
                     q.push({v[newr][newc],{dp[newr][newc],{newr,{newc,h}}}});
                }
           }
        }
       }
       
    }
    for(int i=0;i<str.size();i++)
    {
        cout<<"Path "<<i+1<<" : "<<str[i]<<endl;
    }

}
