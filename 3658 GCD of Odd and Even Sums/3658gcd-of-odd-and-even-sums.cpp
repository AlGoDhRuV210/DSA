class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = n * n;
        n *= 2;
        int sumeven = ((n * (n + 1)) / 2) - sumodd;
        return __gcd(sumodd,sumeven);
    }
};