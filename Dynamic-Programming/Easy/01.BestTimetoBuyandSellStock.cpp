#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int min_price=prices[0];
    int max_profit=0;
    for(int i=1; i<prices.size(); i++)
    {
        if(min_price>prices[i])
        {
            min_price=prices[i];

        }
        else
        {
            int profit = prices[i] - min_price;
            max_profit = max(profit,max_profit);
        }
    }
    return max_profit;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}