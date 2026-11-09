class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int cur = nums[nums.size() - 1];

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[cur - 1] != cur) {
                int tmp = nums[cur - 1];
                nums[cur - 1] = cur;
                cur = tmp;
            }
            else {
                return cur;
            }
        }
    }
};
