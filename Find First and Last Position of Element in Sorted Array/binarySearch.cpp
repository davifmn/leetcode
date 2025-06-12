class Solution {
public:
    // Função auxiliar para encontrar a primeira ou última ocorrência
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                result = mid;
                if (findFirst) {
                    right = mid - 1;  
                } else {
                    left = mid + 1; 
                }
            }
        }

        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);   // busca primeira posição
        int last = binarySearch(nums, target, false);   // busca última posição
        return {first, last};
    }
};
