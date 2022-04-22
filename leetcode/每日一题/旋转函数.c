

int maxRotateFunction(int* nums, int numsSize) {
    int sum_nums = 0;
    int fx = 0;
    for (int i = 0; i < numsSize; i++)
    {
        fx += i * nums[i];
        sum_nums += nums[i];
    }
    int res = fx;
    for (int i = numsSize - 1; i > 0; i--)
    {
        fx = fx + sum_nums - numsSize * nums[i];
        res = res > fx ? res : fx;
    }
    return res;
}
