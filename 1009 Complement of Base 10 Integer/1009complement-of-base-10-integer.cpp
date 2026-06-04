class Solution {
public:
    int bitwiseComplement(int n) {
      int m=0;
      if(n==0) return 1;
      int temp=n;
      while(temp)
      {
        m=m<<1;
        m= m | 1;
        temp=temp>>1;
      }
      return n ^ m;
    }
};