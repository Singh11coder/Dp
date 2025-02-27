#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(long long i=0;i<n;i++)
    {
        cin>>v[i];
    }
    long long t;
    cin>>t;
    vector<vector<long long>>dp(n+1,vector<long long>(t+1,0));
    for(long long j=0;j<=t;j++)
    {
        dp[0][j]=0;
    }
    for(long long i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(long long ind=1;ind<=n;ind++)
    {
        for(long long target=1;target<=t;target++)
        {
            int not_pick=dp[ind-1][target];
            int pick=0;
            if(target>=v[ind-1])
            {
                pick=dp[ind-1][target-v[ind-1]];
            }
            dp[ind][target]=(pick | not_pick);
        }
    }

 
    
    if(dp[n][t]==0)
    {
        cout<<"No subset is present with the given sum";
    }
    queue<pair<int,pair<bool,pair<int,pair<int,string>>>>>q;
    q.push({v[n-1],{1,{n,{t,""}}}});
    vector<string>ans;
    while(!q.empty())
    {
        long long val=q.front().first;
        bool dpval=q.front().second.first;
        long long row=q.front().second.second.first;
        long long col=q.front().second.second.second.first;
        string p=q.front().second.second.second.second;
        q.pop();
        if(row==0 && col==0)
        {
            reverse(p.begin(),p.end());
            ans.push_back(p);
            continue;
        }
        else{
        if((row-1)>=0 && dp[row-1][col]==1)
        {
            q.push({v[row-2],{1,{row-1,{col,p}}}});
        }
        if((row-1)>=0 && (col-val)>=0 && dp[row-1][col-val]==1)
        {
            string h=p+" "+to_string(val);
            q.push({v[row-2],{1,{row-1,{col-val,h}}}});
        }
        }
    
    }
   for(long long i=0;i<(long long)ans.size();i++)
   {
        cout<<ans[i]<<endl;
   }
}
