# 🎓 StudentCare & English Learning App

Chào mừng đến với **StudentCare Manager**! Đây là bộ công cụ "All-in-one" giúp học sinh/sinh viên quản lý việc học, ôn luyện từ vựng Tiếng Anh và rèn luyện sự tập trung, được viết hoàn toàn bằng C++.

## ✨ Tính năng chính

Dự án bao gồm 4 module cốt lõi:

### 1. 📊 GPA Calculator (Tính điểm & Mục tiêu)
* Tính điểm trung bình môn học (GPA).
* **Goal Setting:** Tính toán số điểm cần đạt được trong bài thi cuối kỳ để đạt mục tiêu GPA mong muốn.

### 2. 🔤 FlashCard (Học từ vựng)
* Tạo và quản lý bộ thẻ từ vựng (Flashcards).
* Giúp ôn tập từ mới hiệu quả qua cơ chế lặp lại.

### 3. ❓ Quiz System (Trắc nghiệm)
* Hệ thống bài kiểm tra trắc nghiệm tiếng Anh.
* Tự động chấm điểm và hiển thị kết quả ngay lập tức.

### 4. 🍅 Pomodoro Timer (Đồng hồ tập trung)
* Đồng hồ đếm ngược theo phương pháp Pomodoro (25 phút học / 5 phút nghỉ).
* Giúp duy trì sự tập trung cao độ và tránh mệt mỏi.

---

## 🛠️ Công nghệ sử dụng

* **Ngôn ngữ:** C++ (Standard C++11 trở lên).
* **IDE:** Visual Studio Code / Code::Blocks.
* **Kỹ thuật:** Lập trình hướng đối tượng (OOP), Quản lý file, Đa luồng (Multi-threading cho đồng hồ).

---

## 🚀 Hướng dẫn Cài đặt & Chạy (Build & Run)

Vì dự án chia thành nhiều file (`.cpp` và `.h`), bạn cần biên dịch tất cả cùng lúc.

### Bước 1: Tải code về máy
    git clone https://github.com/Luchuongtam/English-app.git
    cd English-app

### Bước 2: Biên dịch (Compile)
Mở Terminal tại thư mục dự án và chạy lệnh sau để nối tất cả các file:
    g++ *.cpp -o app

### Bước 3: Chạy chương trình
Trên Windows:
    .\app.exe
Trên MacOS / Linux:
    ./app

## Cây thư mục
English-app/
│
├── 📄 main.cpp             # File chính (Chạy chương trình từ đây)
│
├── 🧩 Nhóm file Tiện ích
│   ├── Utils.h             # Khai báo hàm chung (Menu, màu sắc...)
│   └── Utils.cpp           # Code xử lý các hàm chung
│
├── 🔤 Nhóm file FlashCard (Học từ)
│   ├── FlashCard.h         # Khai báo chức năng thẻ từ vựng
│   └── FlashCard.cpp       # Code xử lý học từ vựng
│
├── 📊 Nhóm file GPA (Điểm số)
│   ├── GPACalculator.h     # Khai báo chức năng tính điểm
│   └── GPACalculator.cpp   # Code xử lý tính toán GPA
│
├── 🍅 Nhóm file Pomodoro (Đồng hồ)
│   ├── Pomodoro.h          # Khai báo đồng hồ bấm giờ
│   └── Pomodoro.cpp        # Code chạy đồng hồ
│
├── ❓ Nhóm file Quiz (Trắc nghiệm)
│   ├── Quiz.h              # Khai báo hệ thống câu hỏi
│   └── Quiz.cpp            # Code xử lý bài kiểm tra
│
└── 📝 README.md            # Hướng dẫn sử dụng

👤 Tác giả
Luchuongtam - N24DCCN139

Dự án phục vụ mục đích học tập và chia sẻ kiến thức lập trình C++.