﻿# projectcuoiki
# BÁO CÁO DỰ ÁN CUỐI KÌ
# BrickBreak Game
* Họ tên : Nguyễn Quang Thành
* MSSV : 21020791
* Lớp môn học: INT2215 1, nhóm 9

## Mục lục
* [1. Hướng dẫn cài đặt](#huong-dan-cai-dat) 
* [2. Mô tả chung về trò chơi các ý tưởng chính](#mo-ta-chung-ve-tro-choi-chinh)
* [3. Mô tả chung về các chức năng đã cài đặt ](#mo-ta-chuc-nang)
* [4. Các kỹ thuật lập trình được sử dụng trong chương trình](#cac-ky-thuat-lap-trinh)
* [5. Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình ](#ket-luan-huong-phat-trien)

<a name="huong-dan-cai-dat"/>

## 1. HƯỚNG DẪN CÀI ĐẶT 
### Cài đặt môi trường g++
* Tải [MinGW-W64 GCC-7.3.0-SEH](https://drive.google.com/file/d/1D5DuD-GapJfmGzNnF1_3YSypZ-teG51F/view?usp=sharing)

* Cài đặt MingW-W64 GCC-7.3.0-SEH
    * Giải nén file x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z
    * Copy thư mục `mingw64` vào **<ROOTDIR>** (Ví dụ `E:\software`)
    * Cài đặt đường dẫn PATH đến **<ROOTDIR>\mingw64\bin**
    * Kiểm tra bằng cách gọi `g++` và `mingw32-make` trong terminal
    * Nếu chưa thực hiện thì được thì đọc thêm hướng dẫn ở [đây](https://drive.google.com/file/d/15yXL2YfQy6K7LA3l_AkqUQAzjW7BParn/view?usp=sharing) 

### Cách lấy source về từ [GitHub](https://github.com/quang1409thanh/projectcuoiki)
* Tải source ở dạng zip từ [GitHub](https://github.com/quang1409thanh/projectcuoiki) về máy tính của bạn - sau đó giải nén 
* Sau đó có 3 cách 
    + cách 1: là chạy trực tiếp file main.exe trong source tải về
    + cách 2: Mở bằng visual studio code (nếu có phần mền visual studio code)
        - vào visual studio code
        - chọn New -> Open folder -> chọn thư mục source đã tải về và giải nén ở trên
        - chọn `Terminal` -> chọn `New Terminal` -> gõ lệnh `mingw32-make` -> sau đó gõ lệnh `./main` để chạy chương trình 
    + cách 3: Mở bằng terminal cửa máy tính (nếu không có phần mền visual studio code)
        - vào folder đã giải nén ở trên sau đó-> chuột phải chọn `terminal` -> gõ lệnh `mingw32-make` -> sau đó gõ lệnh `.\main` để chạy chương trình
    + Nếu chưa thực hiện được thì hãy xem chi tiết ở [đây](https://drive.google.com/file/d/1JDuWD0twPNNipZkn_RUDQCwhc8V-lteP/view?usp=sharing)
<a name="mo-ta-chung-ve-tro-choi-chinh"/>

## 2. MÔ TẢ CHUNG VỀ TRÒ CHƠI, CÁC Ý TƯỞNG CHÍNH

### Trò chơi là một trò chơi đơn giản, có các thành phần:

1. Màn hình
2. Người chơi
3. Các đối tượng trong trò chơi { lTexture, viên gạch(brick),, quả bóng (dot), mái chèo để di chuyển (Paddle), các Button để người chơi có thể ấn trực tiếp vào để thực hiện các hành động(LButton1), đối tượng theGame để làm game loop }

### Cách chơi và luật chơi

+ Cách chơi người chơi ấn phím `Spacebar` (cách) để bắt đầu cho quả bóng di chuyển
+ Khi gặp các viên gạch thì nó sẽ phá vỡ viên gạch đó là sẽ di chuyển lại theo va chạm vật lí tự nhiên

+ Yêu cầu của người chơi là sẽ phải di chuyển mái chèo bằng các phím left(A), right(D) để hứng quả bóng sao cho quả bóng không bị rơi xuống cạnh dưới của màn hình game

+ Khi phá hết các viên gạch này thì sẽ tự động chuyển động sang level tiếp theo

+ Điều kiện thắng Người chơi chơi lần lượt 5 level mà không bị thua thì sẽ thắng

+ Điều kiện thua ban đầu mỗi người chơi sẽ được cung cấp cho 3 lượt chơi, khi để rơi xuống cạnh dưới của màn hình game thì sẽ bị trừ đi 1 lượt chơi, đến khi người chơi hết lượt chơi thì sẽ thua. 

<a name="mo-ta-chuc-nang"/>

## 3 MÔ TẢ CÁC CHỨC NĂNG ĐÃ CÀI ĐẶT, KÈM VIDEO MINH HỌA 

[Video minh họa ]( https://www.youtube.com/watch?v=wE6wZliP6n4)

###  Giao diện người dùng 

* Màn hình menu game:
    * Nút `Play` bắt đầu vào màn hình chơi game
    * Nút `About` để xem thông tin của trò chơi
    * Nút `Sound` để bật tắt âm thanh game 
    * Nút `Exit` để thoát game 
* Màn hình chơi game
    * Dùng nút `Spacebar` trên bàn phím để bắt đầu cho quả bóng di chuyển
    * Nút `Pause` để dừng lại game và có thể tiếp tục hoặc bật tắt âm thanh ở màn hình này
    * dừng phím `left(A)` để di chuyển sang trái để hứng quả bóng tránh va chạm thành dưới của màn hình game
    * dùng phím `right(D)` để di chuyển sang phải để hứng quả bóng tránh va chạm thành dưới của màn hình game

### Điểm số
* gồm điểm cao và điểm của người chơi 
* sau mỗi lần phá được viên gạch thì người chơi sẽ được 50 điểm số 
* Nếu điểm của người chơi cao hơn điểm cao thì điểm cao sẽ được cập nhật lại

### Xử lý va chạm
* khi quả bóng va chạm với các phần của màn hình game trên phải và trái thì sẽ di chuyển lại theo va chạm vật lí tự nhiên, còn va chạm với phía dưới của màn hình thì người chơi sẽ mất một lượt chơi
* khi va chạm với các viên gạch thì sẽ phá vỡ viên gạch đó là sẽ di chuyển lại theo va chạm vật lí tự nhiên( nếu va chạm điểm giữa 2 viên gạch thì sẽ phá vỡ cả 2 viên gạch đó và tiếp tục đi thẳng )
* ở level 5 thì tạo ra các viên gạch màu xám làm bức tường nếu va chạm với viên gạch này thì sẽ di chuyển lại theo va chạm vật lí tự nhiên và không phá vỡ gạch 

### Âm thanh

* Cài đặt âm thanh game music và sfx
* ở mỗi màn hình thì sẽ có các music khác nhau ( màn hình menu, play game, win, lose)
* âm thanh hiệu ứng game sfx ( các hiệu ứng âm thanh khác nhau khi va chạm vào viên gạch và tường )
* có thể bật tắt âm thanh bằng nút `Sound` trong màn hình menu game và pause

### Game loop
+ Game loop sau khi thắng hoặc thua có thể chơi lại bằng cách ấn vào các nút `Menu` hoặc `Restart` ở trên màn hình

<a name="cac-ky-thuat-lap-trinh"/>

## 4 CÁC KĨ THUẬT LẬP TRÌNH ĐƯỢC SỬ DỤNG 
  
    * Sử dụng các struct, vector, string, file, enum, mảng, con trỏ
    * Sử dụng tham chiếu, tham trị, hằng tham chiếu.

    * Sử dụng nhiều nhất là các class để quản lí các đối tượng trong game ( hàm khởi tạo- constructor,
    hàm hủy-Destrucor, hàm setter- getter, hàm nhận sự kiện từ người dùng, hàm tính toán, hàm xử lý va chạm, hàm render )

    * Tách hàm, tách file, quản lý file `.cpp` và file `.h`.

    - Sử dụng đồ họa SDL2, SDL2_image, SDL2_ttf, SDL2_mixer

<a name ="ket-luan-huong-phat-trien">

## 5 KẾT LUẬN HƯỚNG DẪN PHÁT TRIỂN, CÁC ĐIỀU KIỆN TÂM ĐẮC SAU KHI HOÀN THIỆN CHƯƠNG TRÌNH
### Kết luận 
    Chương trình với độ phức tạp thuật toán vừa phải sử dụng các lớp, cấu trúc dữ liệu tự định nghĩa và đồ họa SDL2 

    Có đồ họa âm thanh game ở mức vừa phải chưa quá đẹp nhưng trực quan người chơi dễ sử dụng
    Về code đã có reafactor nhưng chưa hoàn thiện lắm, có thể có các lỗi không cần thiết
    
    Có thể có nhiều ý tưởng nhưng việc đưa vào game chưa chắc đã thực hiện được 

    Thư viện đồ họa và người dùng tạo ra giao diện đẹp là điều quan trong khi làm game 
    
### Những điều tâm đắc sau khi hoàn thiện chương trình 
    + sử dụng tốt hơn về phần class và kết nối giữa các class với nhau 
    + biết đưa tạo thành các file mylibrary và có thể sử dụng trong game của mình
    + học hỏi được từ thầy cô và bàn bè xung quanh và từ nguồn trên mạng
    + biết các bước quy trình để khi thực hiện 1 dự án 
    + phải hiểu được logic của game các bước thiết kế xây dựng game 

### Hướng phát triển game
+ Tạo ra đồ họa đẹp hơn có thể mở rộng màn hình để chơi, 
+ Sẽ tạo ra các Iteam để khi quả bóng di chuyển vào thì sẽ có thể 

    + (tăng tốc độ, đổi màu quả bóng( hoặc không màu để tạo khó khăn cho người chơi)
    + tạo ra boom để phá vỡ gạch
    + tạo ra cái mái chèo để hứng quả bóng thay đổi kích thước dài hoặc ngắn hơn mặc định 
    + có thể các viên gạch sẽ bị di chuyển 

## NGUỒN DATA

- Đồ họa SDL2 em học ở Lazyfoo.net link:https://lazyfoo.net/tutorials/SDL/index.php
- Thuật toán của game là chủ yếu xử lý va chạm và di chuyển các đối tưởng trong game    
- Âm thanh hình ảnh em lấy và chỉnh sửa từ folder Data của game  Arkanoid-Break the Brick Game link( sau khi dowload file exe về thì mình chạy file cài đặt và sẽ có phần data): https://sourceforge.net/projects/arkanoid-break-the-bricks-game/
- Các hình ảnh background khác lấy ở trên mạng và chỉnh sửa cắt ghép
