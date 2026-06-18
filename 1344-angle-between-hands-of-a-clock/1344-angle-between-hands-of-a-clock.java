class Solution {
    public double angleClock(int hour, int minutes) {
        double h = (double)(hour*30 %360) + (0.5*minutes);
        double mint = 6*minutes;

        double diff = Math.abs(mint-h);

        return Math.min(diff,360-diff);
    }
}