class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $miprice = $prices[0];
        $profit = 0;

        foreach($prices as $price){
            $profit = max($profit, ($price - $miprice));
            $miprice = min($miprice,$price);
        }
        return $profit;
        
    }
}