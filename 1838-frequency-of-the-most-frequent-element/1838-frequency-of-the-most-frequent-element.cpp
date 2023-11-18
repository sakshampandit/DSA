class Solution {
public:
    // time/space: O(nlogn)/O(1)
    int maxFrequency(vector<int>& nums, int k) {
        // sort the array
        sort(nums.begin(), nums.end());

        // slide the window with the condition `(sum + k) >= (length * nums[r])`
        int result = 0;
        long sum = 0L;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            sum += nums[r];
            // shrink the window width if the condition doesn't meet
            while ((sum + k) < (long(r - l + 1) * nums[r])) sum -= nums[l++];
            result = max(result, r - l + 1);
        }
        return result;
    }
};