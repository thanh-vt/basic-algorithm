###Kiểm tra tần suất bằng nhau

Cho một mảng số nguyên\
Hãy kiểm tra xem tần số xuất hiện của tất cả các số nguyên trong mảng có bằng nhau hay không

Ví dụ:

-   Với `inputArray = [1, 2, 2, 1]`, thì kết quả `checkEqualFrequency(inputArray) = true\
    `Số `1` và số `2` đều có tần số xuất hiện là `2`
-   Với `inputArray = [1, 2, 2, 3, 1, 3, 1, 3]`, thì kết quả `checkEqualFrequency(inputArray) = false`.\
    Số `1` có tần số xuất hiện là `3`, khác vs số `2` và số `3` có tần số xuất hiện là `2`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer inputArray\
    Đ*iều kiện:*\
    `1 ≤ inputArray.length ≤ 5 - 104`,\
    `1 ≤ inputArray[i] ≤ 4 - 108`.

-   [Đầu ra] boolean.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool checkEqualFrequency(std::vector<int> inputArray)
{
    sort(inputArray.begin(), inputArray.end());
    int k = 1;
    for (int i = 1; i < inputArray.size(); i++)
        if (inputArray[i] == inputArray[i - 1])
            k++;
        else
            break;
    inputArray.push_back(INT_MIN);
    int d = 1;
    for (int i = k + 1; i < inputArray.size(); i++)
        if (inputArray[i] == inputArray[i - 1])
            d++;
        else{
            if (d != k)
                return false;
            d = 1;
    }
    return true;
}

```

`\
`

[](https://codelearn.io/learning/thuat-toan-can-ban/3778#)