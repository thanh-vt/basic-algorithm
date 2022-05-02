Một số người đứng thành một số hàng và được chia vào 2 đội

Người đầu tiên được chia vào `team1`, người thứ hai vào `team2`, người thứ ba vào `team1`, người thứ tư vào `team2`, ... cho đến người cuối cùng

Bạn được cho một mảng số nguyên dương thể hiện trọng lượng của mỗi người

Hãy tính toán và trả ra mảng gồm 2 số nguyên dương, thể hiện tổng trọng lượng của `team1` và `team2`

Ví dụ:

-   Với `a = [50, 60, 60, 45, 70]`, thì kết quả `alternatingSums(a) = [180, 105]\
    `Tổng trọng lượng của team1: `50 + 60 + 70 = 180\
    `Tổng trọng lượng của team2: `60 + 45 = 105`

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer a\
    *Điều kiện:*\
    `1 ≤ a.length ≤ 105`\
    `45 ≤ a[i] ≤ 100`.

-   [Đầu vào] array.integer\
    Mảng 2 phần tử chứa tổng trọng lượng của 2 đội.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
std::vector<int> alternatingSums(std::vector<int> a)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < a.size(); i += 2) x+=a[i];
    for (int i = 1; i < a.size(); i += 2) y+=a[i];
    return {x, y};
}
```