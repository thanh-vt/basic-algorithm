Cho 2 mảng `A` và `B` chứa số nguyên. Tìm ra một mảng đã được sắp xếp chứa các phần tử xuất hiện trong mảng `B` nhưng lại không xuất hiện `A

`Chú ý các phần tử giống nhau chỉ tính là 1 lần xuất hiện

Ví dụ:

-   Với `A=[7,2,5,3,5,3]` và `B=[7,2,5,4,6,3,5,3]` thì kết quả `missingValue(A, B) = [4, 6]`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 1 giây

-   [Đầu vào] Array.integer a,b\
    Mảng chứa số nguyên

-   [Đầu ra] Array.integer

### Hướng dẫn bài tập.

Code mẫu:

Ngôn ngữ C++:

Cách 1:

```
std::vector<int> missingValue(std::vector<int> a, std::vector<int> b)
{
    vector<int> check(100001);
    for (int i = 0; i < a.size(); i++){
        check[a[i]] = 1;
    }
    vector<int> ans;
    for (int i = 0; i < b.size(); i++){
        if (!check[b[i]]){
            ans.push_back(b[i]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

```

`\
`

[](https://codelearn.io/learning/thuat-toan-can-ban/17429#)