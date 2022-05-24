﻿# projectcuoiki
# BÁO CÁO DỰ ÁN CUỐI KÌ
# 1 HƯỚNG DẪN CÀI ĐẶT 
- Hãy tải phần soure code về máy tính của bạn
- Hướng dẫn cách chạy trò chơi
    - Đối với người dùng: 
        + Có thể chạy trực tiếp file main.exe để chơi
    - Nếu muốn sửa đổi code thì có thể thực hiện như sau:
        + Đầu tiên phải cài g++ (https://pie-cheque-188.notion.site/C-i-t-h-a-C-Windows-ef0a99a8dcae4dae86a39dc1cbc35980)- có hướng dẫn cụ thể khá ngắn nên cài đặt rất nhanh
        + Sau đó mở phần source code đã tải bằng phần mền visual studio code hoặc terminal của máy tính -> chạy lệnh make file -> tiếp tục chạy lệnh ./main(visual studio code) hay .\main(terminal)
# 2 MÔ TẢ CHUNG VỀ TRÒ CHƠI, CÁC Ý TƯỞNG CHÍNH
- Trò chơi là một trò chơi đơn giản, có các thành phần:
    + 1. Màn hình
    + 2. Người chơi
    + 3. Các đối tượng trong trò chơi { lTexture, viên gạch(brick),, quả bóng (dot), mái chèo để di chuyển (Paddle), các Button để người chơi có thể ấn trực tiếp vào để thực hiện các hành động(LButton1), đối tượng theGame để làm game loop }
- Cách chơi và luật chơi
    + Cách chơi người chơi ấn phím cách để bắt đầu cho quả bóng di chuyển
    + Khi gặp các viên gạch thì nó sẽ phá vỡ viên gạch đó là sẻ di chuyển lại theo va chạm vật lí tự nhiên
    + Yêu cầu của người chơi là sẽ phải di chuyển mái chèo bằng các phím left(), right() để hứng quả bóng sao cho quả bóng không bị rơi xuống cạnh dưới của màn hình game
    + Khi phá hết các viên gạch này thì sẽ tự động chuyển động sang level tiếp theo
    + Điều kiện thắng Người chơi chơi lần lượt 5 level mà không bị thua thì sẽ thắng
    + Điều kiện thua ban đầu mỗi người chơi sẽ được cung cấp cho 3 lượt chơi, khi để rơi xuống cạnh dưới của màn hình game thì sẽ bị trừ đi 1 lượt chơi, đến khi người chơi hết lượt chơi thì sẽ thua. 
# 3 MÔ TẢ CÁC CHỨC NĂNG ĐÃ CÀI ĐẶT, KÈM VIDEO MINH HỌA 
- Các chức năng đã cài đặt
    + Hình ảnh, music, sounde effect, font chữ ...
    + Có điểm cao, hiện thị số mạng còn lại, có thể thay đổi màu quả bóng, ở level 5 thì sẽ khác hơn các level còn lại khi không thể phá được các viên gạch màu xám ( tường )
    + Có thể dừng game  để bật tắt âm thanh và có thể tiếp tục chơi tiếp bằng cách ấn vào nút ở trên màn hình.
    + Game loop sau khi thắng thua có thể chơi lại bằng cách ấn vào các nút ở trên màn hình
    + Link video test: https://www.youtube.com/watch?v=wE6wZliP6n4
# 4 CÁC KĨ THUẬT LẬP TRÌNH ĐƯỢC SỬ DỤNG 
- Sử dụng các class, struct, vector, string, file, enum, mảng, con trỏ
- sử dụng đồ họa SDL2, SDL2_image, SDL2_ttf, SDL2_mixer

# 5 KẾT LUẬN HƯỚNG DẪN PHÁT TRIỂN, CÁC ĐIỀU KIỆN TÂM ĐẮC SAU KHI HOÀN THIỆN CHƯƠNG TRÌNH
- Kết luận 
    chương trình với độ phức tạp thuật toán vừa phải sử dụng các lớp, cấu trúc dữ liệu tự định nghĩa và đồ họa SDL2 
    Có đồ họa âm thanh game ở mức vừa phải chưa quá đẹp nhưng trực quan người chơi dễ sử dụng
    Về code đã có reafactor nhưng chưa hoàn thiện lắm, chỉ mới tạo ra các headfile tạo thành 1 thư viện của mình nhưng có thể chưa áp dụng cho việc muốn phát triển game khác mà mới chỉ dừng lại ở game này và viết các hàm vào trong headfile luôn chứ chưa tách ra file.h và file.cpp 
    
- Những điều tâm đắc sau khi hoàn thiện chương trình 
    + sử dụng tốt về phần class và kết nối giữa các class với nhau 
    + biết đưa tạo thành các file mylibrary và có thể sử dụng trong game của mình
    + học hỏi được từ thầy cô và bàn bè xung quanh và từ nguồn trên mạng
    + biết các bước quy trình để khi thực hiện 1 dự án 

- Hướng phát triển game
    + Tạo ra đồ họa đẹp hơn có thể mở rộng màn hình để chơi, 
    + Sẽ tạo ra các Power để khi quả bóng di chuyển vào thì sẽ có thể + (tăng tốc độ, đổi màu quả bóng( hoặc không màu để tạo khó khăn cho người chơi), tạo ra boom để phá vỡ gạch, tạo ra cái mái chèo để hứng quả bóng thay đổi kích thước dài hoặc ngắn hơn mặc định, có thể các viên gạch sẽ bị di chuyển )
# 6 NGUỒN DATA
- Đồ họa SDL2 em học ở Lazyfoo.net link:https://lazyfoo.net/tutorials/SDL/index.php
- Thuật toán của game là chủ yếu xử lý va chạm và di chuyển các đối tưởng trong game    
- Âm thanh hình ảnh em lấy và chỉnh sửa từ folder Data của game  Arkanoid-Break the Brick Game link( sau khi dowload file exe về thì mình chạy file cài đặt và sẽ có phần data): https://sourceforge.net/projects/arkanoid-break-the-bricks-game/
- Các hình ảnh background khác lấy ở trên mạng và chỉnh sửa cắt ghép
