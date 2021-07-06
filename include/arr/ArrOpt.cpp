#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> arrRef;

arrRef arr = {1, 2, 3, 4, 5};
arrRef arr1 = {7, 1, 5, 3, 6, 4};
arrRef arr2 = {7, 6, 4, 3, 1};
class ArrOpt
{
public:
    void handle();

private:
    int removeDuplicate(arrRef &);
    int maxProfit(arrRef &);
};
int ArrOpt::removeDuplicate(arrRef &arr)
{
    int size = arr.size();
    if (size < 2)
    {
        return size;
    }
    // 遍历器从 1 开始，数组是从0开始
    for (auto it = arr.begin() + 1; it != arr.end(); it++)
    {
        int pre = *(it - 1);
        int cur = *it;
        if (cur == pre)
        {
            arr.erase(it); // 这里删除该遍历器指向的值时，遍历器会下移一位。
            it = it - 1;
        };
        if (it == arr.end())
        {
            break;
        }
    }

    for (auto &&i : arr)
    {
        cout << i << endl;
    }

    // 此方法会非常的慢，可以考虑 把不相同的元素往前移，覆盖相同的元素！
    // arr[i] = arr[i + 1]
    return arr.size();
}

int ArrOpt::maxProfit(arrRef &arr)
{
    // 找出波谷，波谷买，波峰卖；
    int j = 0;
    int buyCount = 0;
    int sellCount = 0;
    bool isSell = false;
    int leg = arr.size() - 1;
    if (leg == 0)
    {
        return 0;
    }
    for (auto &&i : arr)
    {
        int next = j == leg ? arr[leg] - 1 : arr[j + 1];
        if (i < next && !isSell)
        {
            buyCount += i;
            isSell = !isSell;
        }
        else if (i > next && isSell)
        {
            sellCount += i;
            isSell = !isSell;
        }
        j++;
    }

    return sellCount - buyCount;
}
void ArrOpt::handle()
{
    cout << maxProfit(arr) << endl;
    cout << maxProfit(arr1) << endl;
    cout << maxProfit(arr2) << endl;
    cout << "撒旦发射点erer"<< endl;
}
