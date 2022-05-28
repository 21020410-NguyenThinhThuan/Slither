# 1. DỰ ÁN LẬP TRÌNH GAME (INT2215_1)
- Họ và tên: *Nguyễn Thịnh Thuận* - MSV: 21020410
- Lớp: K66-CB
- Tên dự án: **slither** (rắn săn mồi - bản cổ điển)
# 2. HƯỚNG DẪN CÀI ĐẶT
- Lấy source code từ github về máy: [https://github.com/21020410-NguyenThinhThuan/Slither.git](https://github.com/21020410-NguyenThinhThuan/Slither.git)
- Nhập trên terminal: 
                      - git clone [https://github.com/21020410-NguyenThinhThuan/Slither.git](https://github.com/21020410-NguyenThinhThuan/Slither.git)
                      - mingw32-make
                      - .\main.exe
- Các thư viện sử dụng: SDL2-2.0.20, SDL_image, SDL2_mixer-2.0.4, SDL2_ttf-2.0.18, mingw64
# 3. MÔ TẢ CHUNG VỀ GAME
- **Cách chơi:**
        - Sử dụng phím mũi tên trên bàn phím để chơi.
        - Điều khiển rắn ăn mồi để đạt điểm cao nhất có thể.
        - tránh các bức tường và thân rắn.
- **chức năng của game:**
    - Tính điểm.
    - Có tường bao quanh.
    - Có âm thanh khi rắn ăn mồi và khi rắn va vào tường hoặc thân rắn.
    - Giao diện đơn giản (chưa có menu Game).
- **video demo:**
                * [demo-music](https://drive.google.com/file/d/1tHqirewJ5X_awJNNrZWyJLGqhz3rfzke/view?usp=sharing).
# 4. CÁC KỸ THUẬT LẬP TRÌNH
- Cách set up môi trường, tích hợp thư viện
- Refactor, phân chia file và sử dụng github
- Sử dụng mảng, hàm, struct, Vector, con trỏ, đồ họa SDL2,...
# 5. KẾT LUẬN, HƯỚNG PHÁT TRIỂN
- Game có tham khảo từ slide bài giảng, ý kiến bạn bè và các nguồn trên mạng:
 - [lazyfoo.net]( https://lazyfoo.net/tutorials/SDL/)
 - [phattrienphanmem123az.com]( https://phattrienphanmem123az.com/lap-trinh-game-cpp/bai-15-18-them-tinh-nang.html)
 - [SDL2 Game Tutorials](https://www.parallelrealities.co.uk/tutorials/)
- **Hướng phát triển:** 
```
        - Làm menu Game, tạo nhiều loại đồ ăn cho rắn
        - Xây dựng chức năng chọn màu sắc cho rắn, làm thêm các lever
        - Làm các chế độ cho game 
            (các chướng ngại vật, đi xuyên tường, tăng tốc độ cho rắn).
        - Sửa code cho gọn, sạch đẹp, refactor.
        - Hoàn thiện khả năng code, dùng struct, class, mảng, con trỏ, SDL,...
```
# 6. Đánh giá Game
- Game còn sơ sài khá nhiều, tính năng chưa đầy đủ
- Hình ảnh game chưa đẹp
- Code chưa được sạch, gọn, refactor.
- Vẫn còn tham khảo nhiều trên mạng
- Tự chấm điểm : 6 - 7/10.
        
        
