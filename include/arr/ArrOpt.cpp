#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef vector<int> arrRef;

arrRef arr = {1, 2, 2, 2, 3, 4, 3, 3, 3, 5};
arrRef arr1 = {2, 14, 18, 22, 22};
arrRef arr2 = {7, 6, 4, 3, 1};
arrRef arr3 = {7, 6, 7, 3, 6 };
class ArrOpt
{
public:
    void handle();

private:
    int removeDuplicate(arrRef &);
    int maxProfit(arrRef &);
    void rotate(arrRef &, int);
    bool containsDuplicate(arrRef &);
    int singleNumber(arrRef &);

protected:
    void turnArr(arrRef &, int, int);
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

void ArrOpt::rotate(arrRef &arr, int k)
{
    int end = arr.size();
    int distance = k % end;
    if (distance == 0)
    {
        cout << "原样输出" << endl;
        return;
    }
    int leg = end - 1;
    turnArr(arr, 0, leg);
    turnArr(arr, 0, distance - 1);
    turnArr(arr, distance, leg);

    for (auto &&i : arr)
    {
        cout << i << endl;
    }
}

// 翻转数组
void ArrOpt::turnArr(arrRef &arr, int begin, int end)
{
    while (begin < end)
    {
        int tem = arr[begin];
        arr[begin] = arr[end];
        arr[end] = tem;
        begin++;
        end--;
    }
}

bool ArrOpt::containsDuplicate(arrRef &arr)
{
    auto leg = arr.size();
    arrRef hashArr(leg, 0);
    int count0 = 0;
    for (int begin = 0; begin < leg; begin++)
    {
        int &val = arr[begin];
        if (val == 0)
        {
            if (count0 > 0)
            {
                return true;
            }
            count0++;
        }
        else
        {

            int hasIndex = val % leg;
            if (hasIndex < 0)
            {
                hasIndex += leg;
            }

            if (!hashArr[hasIndex])
            {
                hashArr[hasIndex] = val;
            }
            else
            {
                while (hashArr[hasIndex])
                {
                    if (hashArr[hasIndex] == val)
                    {
                        return true;
                    }
                    hasIndex = (hasIndex + 1) % leg;
                }
                hashArr[hasIndex] = val;
            }
        }
    }

    return false;
}

int ArrOpt::singleNumber(arrRef &arr){
    int res = 0;
    for (auto &&i : arr)
    {
        res = res ^ i;
    }
    
    return res;
}

void ArrOpt::handle()
{
    int res = singleNumber(arr3);
    cout << res << endl;
}
