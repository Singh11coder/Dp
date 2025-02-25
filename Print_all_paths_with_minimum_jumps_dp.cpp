//This Problem is combination of DP and BFS algorithm 

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
    vector<long long>dp(n,1e9);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        int k=v[i];
        for(int j=1;j<=k;j++)
        {
            if((i+j)<=n-1)
            {
               dp[i]=min(dp[i],1+dp[i+j]);
            }
        }
    }
    vector<string>ans;
    string p="0";
    queue<pair<int,pair<int,pair<int,string>>>>q;
    q.push({dp[0],{0,{v[0],p}}});
    while(!q.empty())
    {
        int curr=q.front().first;
        int ind=q.front().second.first;
        int jump=q.front().second.second.first;
        string a=q.front().second.second.second;
        curr=curr-1;
        q.pop();
        if(ind==n-1)
        {
            ans.push_back(a);
        }
        else{
        for(int i=ind+1;i<=ind+jump && i<n;i++)
        {
            if(dp[i]==curr)
            {
                string h=a+ "->" + to_string(i);
                q.push({dp[i],{i,{v[i],h}}});
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
