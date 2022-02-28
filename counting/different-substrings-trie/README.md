###Thuật toán tìm số ký tự khác nhau trong chuỗi

Cho một xâu kí tự, tìm số lượng xâu con khác nhau của xâu đó (không tính xâu rỗng)

Ví dụ

-   Với `inputString = "abac"`, thì kết quả `differentSubstringsTrie(inputString) = 9.`\
    9 xâu con khác nhau của xâu đầu vào là:\
    `"a", "b", "c", "ab", "ac", "ba", "aba", "bac", "abac"`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] string inputString\
    Xâu kí tự chỉ chứa kí tự chữ cái in thường\
    *Điều kiện:*\
    `3 ≤ inputString.length ≤ 15`.

-   [Đầu ra] integer

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
int differentSubstringsTrie(std::string inputString)
{
    int d = 0;
    string  s = inputString;
    string p = " ";
    for (int i = 0; i < s.length(); i++){
        string h = "";
        for (int j = i; j < s.length(); j++){
            h = h + s[j];
            string k = " " + h + " ";
            if (p.find(k) < 0 || p.find(k) > p.length() - 1) {
                d++;
                p = p + h + " ";
            }
        }
    }
    return d;
}
```