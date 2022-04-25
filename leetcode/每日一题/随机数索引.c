//简单模拟法


typedef struct {
    int* nums;
    int numsSize;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->nums = nums;
    obj->numsSize = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int count = 0;
    int* idx = (int*)malloc(sizeof(int) * obj->numsSize);
    for (int i = 0; i < obj->numsSize; i++)
    {
        if (target == obj->nums[i])
        {
            idx[count++] = i;
        }
    }
    int ans = idx[rand() % count];
    free(idx);
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);

 * solutionFree(obj);
*/




//水塘抽样法




typedef struct {
    int* nums;
    int numsSize;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->nums = nums;
    obj->numsSize = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int count = 0;
    int ans;
    for (int i = 0; i < obj->numsSize; i++)
    {
        if (target == obj->nums[i])
        {
            count++;
            if (rand() % count == 0)
                ans = i;
        }

    }
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);

 * solutionFree(obj);
*/
