#include<bits/stdc++.h>
using namespace std;

vector<int> price;
int n;

// Write your recursive function here
int RC(int i, int len){
    // Base case
if(len==0 || i>n)
    return 0;
    // Skip case
int skip=RC(i+1,len);
    // Take case (if possible)
int take =0;
if(i<=len)
    { take=price[i+1]+RC(i,len-i);}
    // Return max of take and skip
    return max(skip,take);
}

int main(){
    int len;
    cin >> n >> len;

    price.resize(n+1);

    for(int i = 0; i <= n; i++){
        cin >> price[i];
    }

    cout << RC(1, len) << endl;

    return 0;
}
