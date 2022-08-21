#include <iostream>
#include <vector>

class NumArray
{
public:
	NumArray(std::vector<int> &nums) : arr(nums)
	{
	}

	inline int sumRange(int left, int right)
	{
		return (left > right) ? 0 : arr[left] + sumRange(left + 1, right);
	}

private:
	std::vector<int> arr;
};

int main()
{
	std::vector<int> nums = {1, 2, 3};
	NumArray *obj = new NumArray(nums);
	int param_1 = obj->sumRange(1, 3);
	return 0;
}
