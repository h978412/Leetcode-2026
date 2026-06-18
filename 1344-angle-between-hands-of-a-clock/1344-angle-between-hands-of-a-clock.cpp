class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mint = 6*minutes;
        double h = (double)(30*hour%360) + (double)(0.5)*minutes;
        double angle = abs(mint-h);

        return min(angle,abs(angle-360));
    }
};