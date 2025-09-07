class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """ 
        max_num = ""  # store as string directly
        for i in range(len(num)-2):
            sub = num[i:i+3] 
            # check if all three digits are the same
            if sub[0] == sub[1] == sub[2]:
                if sub > max_num:
                    max_num = sub  
        return max_num  # will be empty string if none found
