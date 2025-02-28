#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long>val(n);
    vector<long long>wt(n);
    for(long long i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(long long i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    long long cap;
    cin>>cap;
    vector<vector<long long>>dp(n+1,vector<long long>(cap+1,0));
    for(long long ind=1;ind<=n;ind++)
    {
        for(long long capacity=1;capacity<=cap;capacity++)
        {
            long long not_pick=dp[ind-1][capacity];
            long long take=0;
            if(capacity>=wt[ind-1])
            {
                take=val[ind-1]+dp[ind-1][capacity-wt[ind-1]];
            }
            dp[ind][capacity]=max(not_pick,take);
        }
    }

    // for(long long i=0;i<=n;i++)
    // {
    //     for(long long j=0;j<=cap;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    set<string>ans;
    queue<pair<int,pair<int,pair<int,string>>>>q;
    q.push({dp[n][cap],{n,{cap,""}}});
    while(!q.empty())
    {
        int profit=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second.first;
        string p=q.front().second.second.second;
        q.pop();
        if(row==0 || col==0)
        {
            p=p.substr(1);
            ans.insert(p);
        }
        else
        {
            if(dp[row-1][col]==profit)
            {
                q.push({dp[row-1][col],{row-1,{col,p}}});
            }
            if(dp[row-1][col-wt[row-1]]==(profit-val[row-1]))
            {
                string h=p+" "+to_string(val[row-1]);
                q.push({dp[row-1][col-wt[row-1]],{row-1,{col-wt[row-1],h}}});
            }
        }
    }
    for(auto i:ans)
    {
        cout<<i<<endl;
    }

}