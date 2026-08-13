class Solution {
public:

// use to calculate number of boquet on that day TC = O(n) SC = O(1)
int flowers(vector<int> &bloomDay, int day,int k){
    int count = 0;
    int current = 0;
    for(int i = 0 ; i < bloomDay.size(); i++){
        if(bloomDay[i] <= day){
            current++;
            if(current == k){
                count++;
                current = 0;
            }
        }
            else current = 0;
        
    }
    return count;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
     int n = bloomDay.size();
     if(m > n/k) return -1;
int low = *min_element(bloomDay.begin(),bloomDay.end());
int high = *max_element(bloomDay.begin(),bloomDay.end());
while(low < high){
    int mid = low + (high-low)/2;
  int boquet = flowers(bloomDay,mid,k);
  if(boquet < m ) low = mid +1;
  else high = mid;
}
return high;
    }
};