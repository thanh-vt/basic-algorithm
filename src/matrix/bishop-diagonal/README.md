Một bài nâng cao về [con tượng](https://codelearn.io/LearningTask/Index?Id=3477&TaskId=3775) trong cờ vua

Trong thế giới cờ vua, con tượng không thích con tượng khác. Trong thực tế, khi 2 con tượng cùng đứng chung 1 đường chéo, chúng lập tức di chuyển tới hai đầu của đường chéo đó

Cho vị trí ban đầu của hai con tượng trên bàn cờ vua, hãy tính toán vị trí của chúng sau khi di chuyển tới hai đầu của đường chéo mà chúng đang đứng. Nhớ rằng con tượng sẽ không di chuyển trừ khi chúng đứng chung trên một đường chéo

Ví dụ

-   Với `bishop1 = "d7"` và `bishop2 = "f5"`, kết quả `bishopDiagonal(bishop1, bishop2) = ["c8", "h3"]`.

    ![](https://codesignal.s3.amazonaws.com/tasks/bishopDiagonal/img/ex_1.jpg?_tm=1551432804841)

-   Với `bishop1 = "d8"` và `bishop2 = "b5"`, kết quả `bishopDiagonal(bishop1, bishop2) = ["b5", "d8"]`.

    2 con tượng không đứng trên cùng 1 đường chéo, vì vậy chúng không di chuyển\
    ![](https://codesignal.s3.amazonaws.com/tasks/bishopDiagonal/img/ex_2.jpg?_tm=1551432805142)

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] string bishop1, bishop2\
    Tọa độ của hai con tượng\
    *Guaranteed constraints:*\
    `bishop1.length = bishop2.length = 2`\
    `'a' ≤ bishop1[0],bishop2[0] ≤ 'h'`\
    `1 ≤ bishop1[1],bishop2[1] ≤ 8`

-   [Đầu ra] array.string

    -   Mảng 2 phần tử thể hiện tọa độ của 2 con tượng theo thứ tự từ điển tăng dần sau khi thực hiện phép di chuyển .

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
std::vector<std::string> bishopDiagonal(std::string bishop1, std::string bishop2)
{
    if (bishop1 > bishop2) swap(bishop1, bishop2);
    if (abs(bishop1[0] - bishop2[0]) != abs(bishop1[1] - bishop2[1])){
        return{bishop1 ,bishop2};
    }
    if (bishop1[1] < bishop2[1]){
        while (bishop1[0] != 'a' && bishop1[1] != '1'){
            bishop1[0]--;
            bishop1[1]--;
        }
        while (bishop2[0] != 'h' && bishop2[1] != '8'){
            bishop2[0]++;
            bishop2[1]++;
        }
        return{bishop1, bishop2};
    }
    else{
        while (bishop1[0] != 'a' && bishop1[1] != '8'){
            bishop1[0]--;
            bishop1[1]++;
        }
        while (bishop2[0] != 'h' && bishop2[1] != '1'){
            bishop2[0]++;
            bishop2[1]--;
        }
        return{bishop1, bishop2};
    }
}
```