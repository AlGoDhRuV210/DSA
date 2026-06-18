class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mn=(minutes*6.00000);
        double hr = (hour*30.00000) + minutes/2.00000;
        return min(abs(hr-mn),360-abs(hr-mn));



    }
};