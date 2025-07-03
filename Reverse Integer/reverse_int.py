# Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
# Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

# Input: x = 123
# Output: 321
# Example 2:

# Input: x = -123
# Output: -321
# Example 3:

# Input: x = 120
# Output: 21

class Solution:
    def reverse(self, x: int) -> int:
        negativo = False
        lista = []

        if x == 0:
            return 0

        if x < 0:
            x = -x
            negativo = True
        
        while x > 0:
            lista.append(x % 10)
            x = x // 10

        x = int(''.join(map(str, lista)))

        if negativo:
            x = -x

        if x < -2**31 or x > 2**31 - 1:
            return 0

        return x
