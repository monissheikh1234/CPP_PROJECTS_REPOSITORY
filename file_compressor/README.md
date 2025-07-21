# 🗜️ File Compression Tool (Mini WinRAR) - C++

A powerful mini **file compression tool** built using **C++** that implements **Huffman Coding** to compress and decompress text files. This project showcases core concepts in **Data Structures, Algorithms, and File Handling** — perfect for adding to your resume as a systems-level utility project.

## 🚀 Features
- ✅ Compresses `.txt` files using Huffman coding
- ✅ Decompresses `.huff` files back to original text
- ✅ Calculates and shows compression ratio
- ✅ Displays frequency table of characters
- ✅ Clean console interface with user prompts
- ✅ Cross-platform: works on Windows, Linux, macOS (with g++)

## 📁 Project Structure
FileCompression_CPP/  
├── main.cpp              # Source code with compression & decompression logic  
├── input.txt             # (Example) File to compress  
├── compressed.huff       # Compressed binary output  
├── decompressed.txt      # Decompressed output for verification  
├── README.md             # You’re here  

## Snapshots
<img width="1696" height="946" alt="image" src="https://github.com/user-attachments/assets/3bfaab1e-e29f-453d-93f0-8de1a0c1b708" />


https://github.com/user-attachments/assets/826f6213-c476-472b-b23e-0feea319f75e


## 🔧 How to Run
1. Make sure `g++` or MinGW is installed on your system  
2. Open terminal in project folder  
3. Compile using:  
   `g++ main.cpp -o compressor.exe`  
4. Run using:  
   `.\compressor.exe` (on Windows) or `./compressor.exe` (on Linux/macOS)  

## 📊 How It Works
- Reads the text file and calculates frequency of characters
- Builds a **Huffman Tree** using a priority queue (min-heap)
- Assigns binary codes to characters
- Encodes the file and stores it in a `.huff` format
- Can later decode `.huff` back to original using the tree

## 💡 Learning Highlights
- Huffman Encoding & Decoding (Greedy Algorithm)
- Priority Queue & Tree data structures
- Binary File Handling in C++
- Bitwise manipulation and I/O optimization
- Efficient compression logic using STL

## 🎯 Use Case
This project is perfect for:
- Students learning algorithms like Huffman Coding  
- System-level programming mini or major projects  
- Understanding how tools like WinRAR/7-Zip work internally  
- Practice with advanced file handling in C++  

## 📌 Future Enhancements
- Support for compressing multiple files
- GUI using C++ frameworks (Qt/GTK)
- Progress bar during compression
- Compression of images and binary files
- Add password protection to compressed files

## 👨‍💻 Author
**Monis Sheikh**  
📫 [LinkedIn](https://linkedin.com/in/monissheikh1234)  
🔗 GitHub: [@monissheikh1234](https://github.com/monissheikh1234)  

## ⭐ Give this repo a star if you liked the project!
