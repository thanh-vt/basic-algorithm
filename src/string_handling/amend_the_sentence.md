###Thuật toán chèn ký tự

Cho một xâu kí tự `s` gồm nhiều từ. Trong đó mỗi từ sẽ được bắt đầu bởi một kí tự in hoa.

Vì một lí do gì đó, người ta quên chèn các khoảng trắng giữa các từ.

Hãy viết chương trình sửa lại xâu kí tự đó theo yêu cầu sau: 

-   Tách các từ, và thêm `1` kí tự cách (space) giữa `2` từ liên tiếp
-   Chuyển đổi các kí tự in hoa thành kí tự in thường

Ví dụ

-   Với `s = "CodelearnIsAwesome"`, thì kết quả `amendTheSentence(s) = "codelearn is awesome"`
-   Với `s = "Hello"`, thì kết quả `amendTheSentence(s) = "hello"`.

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây với C++, 3s với Java và C#, 4s với Python, JS và GO

-   [Đầu vào] string s\
    Một xâu chứa kí tự chữ cái in hoa và in thường.\
    *Điều kiện:*\
    `3 ≤ s.length ≤ 1000`.

-   [Đầu ra] string\
    Câu đã thay đổi.

Hướng dẫn bài tập.
------------------

Các ký tự từ `'A'` đến `'Z'` nằm ở vị trí từ `65` đến `90` trong bảng mã ASCII.

Các ký tự từ `'a'` đến `'z'` nằm ở vị trí từ `97` đến `122` trong bảng mã ASCII.

Suy ra các ký tự in hoa và in thường của `1` ký tự chữ chênh lệch nhau một khoảng là `32`. Ví dụ:

`'A' + 32 = 'a'; h - 32 = 'H'`

Code mẫu:

Ngôn ngữ C++:

```
string amendTheSentence(string s)
{
    string result;
    if (s[0] >= 'A' && s[0] <= 'Z')
        s[0] += 32;
    for (int i = 0; i <s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            result = result + " " + char(s[i] + 32);
        else
            result = result + s[i];
    return result;
}
```