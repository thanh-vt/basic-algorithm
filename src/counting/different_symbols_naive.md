###Thuật toán tìm số ký tự khác nhau trong chuỗi

Cho xâu kí tự. Hãy đếm số lượng kí tự khác nhau trong xâu đó

Ví dụ:

-   Với `s = "cabca"`, thì kết quả `differentSymbolsNaive(s) = 3`.\
    Có `3` kí tự khác nhau là `a`, `b` và `c`.

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 seconds

-   [Đầu vào] string s

    Xâu kí tự chứa các chữ cái in thường.

    *Guaranteed constraints:*\
    `3 ≤ s.length ≤ 1000`.

-   [Đầu ra] integer.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
int differentSymbolsNaive(std::string s)
{
    vector <bool> a(256, false);
    for (int i = 0; i < s.length(); i++)
        b[s[i]] = true;
    int d = 0;
    for (int i = 0; i < s.length(); i++)
    if (b[s[i]]){
        d++;
        b[s[i]] = false;
    }
    return d;
}
```