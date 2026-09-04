class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int a = source[0];
        int b = source[1];

        int c = target[0];
        int d = target[1];
        if ((a % 2 == b % 2) && (c % 2 != d % 2))
            return -1;
        if ((a % 2 != b % 2) && (c % 2 == d % 2))
            return -1;
        if(abs(c-a)==abs(d-b)) return 1;
        return 2;
    }
};