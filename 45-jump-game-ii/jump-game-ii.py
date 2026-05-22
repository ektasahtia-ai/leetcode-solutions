class Solution(object):
    def jump(self, nums):
        n = len(nums)

        # If only one element, no jump needed
        if n == 1:
            return 0

        jumps = 0
        current_end = 0
        farthest = 0

        for i in range(n - 1):

            # Find the farthest position reachable
            farthest = max(farthest, i + nums[i])

            # When we reach the end of current jump range
            if i == current_end:
                jumps += 1
                current_end = farthest

        return jumps