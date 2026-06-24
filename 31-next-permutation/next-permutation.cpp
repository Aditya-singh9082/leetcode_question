class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int gola_index = -1;

        // Step 1: Find pivot
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                gola_index = i - 1;
                break;
            }
        }

        // Step 2: Find element just greater than pivot
        if (gola_index != -1) {
            int swap_index = gola_index;

            for (int j = n - 1; j >= gola_index + 1; j--) {
                if (nums[j] > nums[gola_index]) {
                    swap_index = j;
                    break;
                }
            }

            // Step 3: Swap
            swap(nums[gola_index], nums[swap_index]);
        }

        // Step 4: Reverse suffix
        reverse(nums.begin() + gola_index + 1, nums.end());
    }
};