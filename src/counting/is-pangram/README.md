###Thuật toán kiểm tra số Pangram

Một pangram là một câu mà mỗi kí tự chữ cái (`a-z`) được sử dụng ít nhất một lần

Cho một xâu kí tự, kiểm tra xem nó có phải là một pangram hay không?

Ví dụ:

-   Với `sentence = "The quick brown fox jumps over the lazy dog."`, thì kết quả `isPangram(sentence) = true`;
-   Với `sentence = "abcdefghijklmnopqrstuvwxya"`, thì kết quả `isPangram(sentence) = false`.

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] string sentence

    Xâu kí tự chứa các kí tự ASCII có mã nằm trong khoảng `[32, 126]`.

    *Điều kiện:*\
    `1 ≤ sentence.length ≤ 100`.

-   [Đầu ra] boolean

    -   `true` nếu `sentence` là một câu pangram, `false` nếu ngược lại.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool isPangram(std::string sentence)
{
    vector <int> a(256, 0);
    for (int i=0; i<sentence.length(); i++)
        a[sentence[i]]++;
    for (int i = 65; i <= 90; i++) a[i + 32] += a[i];
    for (int i = 97; i <= 122; i++)
        if (a[i] <= 0)
            return false;
    return true;
}
```