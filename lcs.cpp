#include<bits/stdc++.h>
using namespace std;

int lis (int i,int p,vector<int>&nums)
{
    if(i>=nums.size())
        return 0;
    int skip=lis(i+1,p,nums);
    int take=0;
    if(p==-1||nums[p]<nums[i]){
        take=1+lis(i+1,i,nums);
    }
    return max(take,skip);
}
int main(){
vector<int>nums={0,1,2,3,4};
cout<<lis(0,-1,nums);
return 0;
}
