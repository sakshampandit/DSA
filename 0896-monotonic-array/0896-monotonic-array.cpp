class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return true; // A single element array is considered monotonic.
        }
        
        int direction = 0; // 0: undetermined, 1: increasing, -1: decreasing
        
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            
            if (diff > 0) {
                if (direction == -1) {
                    return false; // Not monotonic if it was decreasing before.
                }
                direction = 1;
            } else if (diff < 0) {
                if (direction == 1) {
                    return false; // Not monotonic if it was increasing before.
                }
                direction = -1;
            }
            // If diff == 0, continue to the next element.
        }
        
        return true;
    }
};