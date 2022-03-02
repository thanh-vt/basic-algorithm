###Thuật toán định dạng chuỗi

Xóa các khoảng trắng thừa (kí tự cách) trong xâu kí tự cho trước, sao cho giữa các từ chỉ cách nhau bởi 1 khoảng trống. Cũng không có khoảng trống ở đầu và cuối của xâu

Ví dụ

-   Với `input = " abc   a aa  a a "`, kết quả `formatString(input) = "abc a aa a a"`.

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 seconds

-   [Đầu vào] string input\
    xâu kí tự chứa kí tự chữ số và chữ cái in hoa hoặc in thường,\
    *Điều kiện:*\
    `4 ≤ input.length ≤ 50`.

-   [Đầu ra] string

    -   Xâu kí tự sau khi đã xóa các kí tự space thừa.

Hướng dẫn bài tập.
------------------

Để xóa tất cả những ký tự trắng đầu tiên ta dùng một vòng while như sau:

```
    while (s[0] == ' ')
        s.erase(0, 1);
```

Để xóa tất cả những ký tự trắng cuối cùng ta dùng một vòng while như sau:

```
while (s[s.length()-1] == ' ')
        s.erase(s.length()-1, 1);
```

Để xóa những ký tự trắng cạnh nhau ta dùng một vòng while như sau:

```
	while (s.find("  ") != -1)
        s.erase(s.find("  "), 1);
```

Code mẫu:

Ngôn ngữ C++:

```
std::string formatString(std::string input)
{
    string s = input;
    while (s[0] == ' ')
        s.erase(0, 1);
	while (s[s.length()-1] == ' ')
        s.erase(s.length()-1, 1);
	while (s.find("  ") != -1)
        s.erase(s.find("  "), 1);
    return s;
}
```