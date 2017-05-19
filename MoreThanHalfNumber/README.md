## Problem
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

## Solution

### 思路1
如果某个数出现次数出现超过一半，那么将数组排序之后，出现在中间位置的数一定是所要找的数。我们使用快排中partition的思想，求出中间位置的数即可。时间复杂度O(nlogn)。

### 思路2
上面的思路由于使用了快排的思想，因此时间复杂度为O(nlogn)，并不是最优的。
另外一种方法是，我们记录之前出现过的数和次数，当当前出现的数字与之前相同时，次数加1.不同时，次数减1.由于我们要找的数字比所有其他数字出现的次数都要多，因此使次数最后一次变为1的数字就是我们要找的数字。
