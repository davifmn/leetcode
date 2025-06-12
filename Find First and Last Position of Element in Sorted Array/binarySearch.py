from typing import List

class Solution:
    def binarySearch(self, nums: List[int], target: int, findFirst: bool) -> int:
        left, right = 0, len(nums) - 1
        result = -1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                result = mid
                if findFirst:
                    right = mid - 1  # continue buscando à esquerda
                else:
                    left = mid + 1   # continue buscando à direita
        return result

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = self.binarySearch(nums, target, True)
        last = self.binarySearch(nums, target, False)
        return [first, last]
