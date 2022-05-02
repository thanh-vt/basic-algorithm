Cho một mảng số nguyên

Hãy viết chương trình tìm ra một mảng mới, sao cho các phần tử trong 2 mảng này chứa đủ các số nguyên liên tiếp của một khoảng nào đó

Ví dụ:

-   Với `sequence = [6, 2, 3, 8]`, thì kết quả `makeArrayConsecutive(sequence) = [4, 5, 7]`.

    Với mảng mới gồm các số `[4,5,7]`, thì hai mảng có chứa đủ các số nguyên liên tiếp từ `2` tới `8`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 seconds

-   [Đầu vào] array.integer sequence\
    Mảng chứa các số nguyên khác nhau\
    *Điều kiện:*\
    `1 ≤ sequence.length ≤ 10`,\
    `-10 ≤ sequence[i] ≤ 10`.

-   [Đầu ra] array.integer

    -   Mảng đã sắp xếp có độ dài ngắn nhất thỏa mãn yêu cầu đề bài.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
std::vector<int> makeArrayConsecutive(std::vector<int> sequence)
{
    std::vector<int> a;
    sort(sequence.begin(), sequence.end());
    int k = sequence[0];
    int h=0;
    while(k!=sequence[sequence.size()-1]){
        if (k==sequence[h]){
            k++;
            h++;
        }
        else{
            while(k!=sequence[h]){
                a.push_back(k);
                k++;
            }
        }
    }
    return a;
}
```