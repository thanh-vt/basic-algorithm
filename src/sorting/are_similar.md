Two arrays are called *similar* if one can be obtained from another by swapping at most one pair of elements in one of the arrays.

Hai mảng `a` và `b` được gọi là tương đồng nếu ta có thể thu được mảng `b` bằng cách đổi chỗ tối đa 1 lần 2 phần tử bất kì trong mảng `a`

Cho hai mảng `a` và `b`, kiểm tra hai mảng có tương đồng hay không?

Ví dụ

-   Với `a = [1, 2, 3]` và `b = [1, 2, 3]`, kết quả `areSimilar(a, b) = true`.

    Hai mảng này giống nhau mà không cần đổi chỗ phần tử nào

-   For `a = [1, 2, 3]` and `b = [2, 1, 3]`, kết quả `areSimilar(a, b) = true`.

    Chúng ta thu được mảng `b` từ mảng `a` bằng cách đổi chỗ 2 phần tử `2` và `1`.

-   Với `a = [1, 2, 2]` và `b = [2, 1, 1]`, kết quả `areSimilar(a, b) = false`.

    Đổi chỗ bất kì cặp số nào trong mảng `a` cũng không thể thu được mảng `b`

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer a, b

    Mảng chứa số nguyên.\
    *Điều kiện:*\
    `3 ≤ a.length, b.length ≤ 105`\
    `1 ≤ a[i], b[i] ≤ 1000`.

-   [Đầu ra] boolean

    -   `true` nếu `a` và `b` tương đồng, `false` ngược lại.

Hướng dẫn bài tập:
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool areSimilar(std::vector<int> a, std::vector<int> b)
{
    int d = 0;
    for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i])
        d++;
    if (d != 0 && d != 2)
        return false;
    int h = 0;
    for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i]){
        h = i;
        break;
    }
    for (int i = h + 1; i < a.size(); i++)
    if (a[i] != b[i]){
        return (a[i] == b[h] && a[h] == b[i]);
    }
    return true;
}
```