#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

int lis(int i,int p,vector<int>&nums){
if(i >= nums.size())
    return 0;
if(dp[i][p+1]!=-1)
    return dp[i][p+1];
int skip=lis(i+1,p,nums);
int take=0;
if(p==-1||nums[p]<nums[i]){
    take=1+lis(i+1,i,nums);
}
return dp[i][p+1]=max(take,skip);
};
int main(){
vector<int>nums={0,1,3,2};
cout<<lis(0,-1,nums);
return 0;
}
