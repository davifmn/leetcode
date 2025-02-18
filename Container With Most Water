class Solution:
    def maxArea(self, height: list[int]) -> int:
        max = 0
        i, j = 0,  len(height) -1
        
        while i < j:
            
            if ((j - i ) * min(height[i], height[j])) > max:
                max = (j - i ) * min(height[i], height[j])
                
            if height[i] <  height[j]:
                i +=  1 
            else:
                 j -= 1
            
        return max
            

