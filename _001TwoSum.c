#define _CRT_SECURE_NO_WARNINGS 1

// Leetcode 1 : 两数之和 

# include <stdio.h>
# include <assert.h>
# include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    assert(nums != NULL);
    int* p = NULL;
    int i,j;
    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                p = (int*)malloc(sizeof(int) * 2);
                p[0] = i;
                p[1] = j;
                *returnSize = 2;
                return p;
            }
        }
    }
    return p;
}
