###Kiểm tra ký tự song song

Cho một xâu kí tự `s`

Hãy kiểm tra xem xâu `s` có thể tạo ra bằng cách ghép một xâu vào chính nó hay không?  

Ví dụ:

-   Với `inputString = "tandemtandem"`, kết quả `isTandemRepeat(inputString) = true\
    `Có thể tạo ra xâu `"tandemtandem"` bằng cách ghép xâu `"tandem"` vào phía sau của chính nó
-   Với `inputString = "qqq"`, kết quả `isTandemRepeat(inputString) = false`
-   Với `inputString = "2w2ww"`, kết quả `isTandemRepeat(inputString) = false`

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 seconds

-   [Đầu vào] string inputString

    *Điều kiện:*\
    `2 ≤ inputString.length ≤ 20`.

-   [Đầu ra] boolean.

Hướng dẫn bài tập.
------------------

Chia chuỗi thành `2` phần và số sánh chúng.

Code mẫu:

Ngôn ngữ C++:

```
bool isTandemRepeat(std::string inputString)
{
    string s = inputString;
    if (s.length() % 2 != 0)
        return false;
    if (s.substr(s.length() / 2, s.length() / 2) == s.substr(0, s.length() / 2))
        return true;
    return false;
}
```