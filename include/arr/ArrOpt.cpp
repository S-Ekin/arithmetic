#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> arrRef;

arrRef arr = {1, 2, 3, 4, 5};
arrRef arr1 = {1,2,3,4,5,6,7,4,5,6,2,3,5};
arrRef arr2 = {7, 6, 4, 3, 1};
class ArrOpt
{
public:
    void handle();

private:
    int removeDuplicate(arrRef &);
    int maxProfit(arrRef &);
    void rotate(arrRef &, int);
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

void ArrOpt::rotate(arrRef &arr, int k){
     int leg = arr.size();
     int distance = k % leg;
     if(distance == 0){
         return;
     }
    auto begin = arr.begin();
    auto end = arr.end();
    auto bounder = begin + leg - distance;
    if(leg - distance > distance){
        arr.insert(begin,distance,0);
        auto begin = arr.begin();
        auto end = arr.end();
        int leg = arr.size();
        auto bounder = begin + leg - distance;
        swap_ranges(bounder, end, begin);
        arr.erase(end - distance, end);
    }else{
        swap_ranges(bounder, end, begin - 1);
    }
    for (auto &&i : arr)
    {
      cout << i << endl;   
    }
    

}
void ArrOpt::handle()
{
    rotate(arr1, 9);

}
