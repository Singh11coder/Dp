#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>>v(n,vector<long long>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<long long>>dp(n,vector<long long>(m,1e9));
    dp[n-1][m-1]=v[n-1][m-1];
    for(int j=m-2;j>=0;j--)
    {
        dp[n-1][j]=v[n-1][j]+dp[n-1][j+1];
    }
    for(int i=n-2;i>=0;i--)
    {
        dp[i][m-1]=v[i][m-1]+dp[i+1][m-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            dp[i][j]=v[i][j]+min(dp[i+1][j],dp[i][j+1]);
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    vector<string>ans;
    string p="{0,0}";
    queue<pair<int,pair<int,string>>>q;
    q.push({0,{0,p}});
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second.first;
        string h=q.front().second.second;
        q.pop();
        if(r==n-1 && c==m-1)
        {
            ans.push_back(h);
        }
        else{
        if(r==n-1 || c==m-1)
        {
        
            if(r==n-1)
            {
                int col=c+1;
                string j=h+" , "+"{"+to_string(r)+","+to_string(col) + "}";
                q.push({r,{col,j}});
            }
            if(c==m-1)
            {
                int row=r+1;
                string j=h + " , " + "{" + to_string(row) + "," + to_string(c) + "}";
                q.push({row,{c,j}});
            }
            
        }
        else
        {
            if(dp[r+1][c]<dp[r][c+1])
            {
                string j=h+" , "+"{"+to_string(r+1)+","+to_string(c)+ "}";
                q.push({r+1,{c,j}});
            }
            else if(dp[r+1][c]>dp[r][c+1])
            {
                string j=h+" , "+"{"+to_string(r)+","+to_string(c+1) + "}";
                q.push({r,{c+1,j}});
            }
            else
            {
                string j=h+" , "+"{"+to_string(r+1)+","+to_string(c) + "}";
                q.push({r+1,{c,j}});
                string u=h+" , "+"{"+to_string(r)+","+to_string(c+1) + "}";
                q.push({r,{c+1,u}});
            }
        }
      }
        
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<endl;

}
