#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

vector<Item> item;
int dp=[50][50];

int knapsack(int i, int cap){
    // Base case
    if(i == item.size() || cap == 0)
        return 0;

    // If already computed
    if(dp[i][cap] != -1)
        return dp[i][cap];

    // Skip
    int skip = knapsack(i + 1, cap);

    // Take
    int take = 0;
    if(item[i].weight <= cap){
        take = item[i].value + knapsack(i + 1, cap - item[i].weight);
    }

    // Store and return
    return dp[i][cap] = max(skip, take);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;

    item.resize(n);
    for(int i = 0; i < n; i++){
        cin >> item[i].weight >> item[i].value;
    }

    // Initialize DP table
    dp.assign(n, vector<int>(capacity + 1, -1));

    cout << knapsack(0, capacity) << endl;
    return 0;
}
