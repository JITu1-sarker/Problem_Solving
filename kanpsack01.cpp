#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

vector<Item> item;

int knapsack(int i, int cap){
    // Base case
    if(i == item.size() || cap == 0)
        return 0;

    // Skip
    int skip = knapsack(i + 1, cap);

    // Take
    int take = 0;
    if(item[i].weight <= cap){
        take = item[i].value + knapsack(i + 1, cap - item[i].weight);
    }

    // Store and return
    return max(skip, take);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;

    item.resize(n);
    for(int i = 0; i < n; i++){
        cin >> item[i].weight >> item[i].value;
    }

    cout << knapsack(0, capacity) << endl;
    return 0;
}
