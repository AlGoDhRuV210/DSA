class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = min(rec1[0], rec1[2]);
        int x2 = max(rec1[0], rec1[2]);

        int y1 = min(rec1[1], rec1[3]);
        int y2 = max(rec1[1], rec1[3]);

        int xx1 = min(rec2[0], rec2[2]);
        int xx2 = max(rec2[0], rec2[2]);

        int yy1 = min(rec2[1], rec2[3]);
        int yy2 = max(rec2[1], rec2[3]);

        if (xx1 >= x2 || yy1 >= y2 || xx2 <= x1 || yy2 <= y1)
            return false;
        return true;
    }
};