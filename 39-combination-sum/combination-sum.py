class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        result = []

        def backtrack(start, path, total):
            # If target is reached
            if total == target:
                result.append(path[:])
                return

            # If sum exceeds target
            if total > target:
                return

            for i in range(start, len(candidates)):
                path.append(candidates[i])

                # Same index i because elements can be reused
                backtrack(i, path, total + candidates[i])

                # Backtrack
                path.pop()

        backtrack(0, [], 0)

        return result