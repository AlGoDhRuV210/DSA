#include <bits/stdc++.h>
class Solution {
public:
int day(vector<int> &weights,int weight){
    int n = weights.size();
    int day = 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
         if(sum + weights[i] > weight){
            day++;
            sum = weights[i];
         } 
         else sum += weights[i];
    }
    return day;
}

int summation(vector<int> &weights){
    int sum = 0;
    for(auto i : weights)
    {
        sum+=i;
    }
    return sum;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int high =summation(weights);
        int low = *max_element(weights.begin(),weights.end());
        while(low < high){
            int mid = low + (high-low)/2;
int din = day(weights,mid);
if(din > days) low = mid +1;
else high = mid;
        }
        return high;
    }
};