# 🛒 Supermarket Billing System

A modern and simple **Supermarket Billing System** written in **C++**, designed for managing item inventories, generating bills, and tracking customer purchases. Ideal for local stores or as a hands-on project to demonstrate C++ and file handling concepts.

## 🚀 Features

- ✅ Add and update inventory items  
- ✅ Support for multiple entries of the same item with different prices  
- ✅ Real-time billing with quantity validation  
- ✅ Customer bill generation with total amount  
- ✅ Admin login system *(optional)*  
- ✅ Customer details recording *(optional)*  
- ✅ Export bills for reference  
- ✅ Console-based user-friendly interface

## 📁 Project Structure

```
SupermarketBillingSystem/
├── main.cpp            # Main C++ source file
├── Inventory.txt       # Stores inventory items
├── Bills/              # (Optional) Stores generated bills
│   └── bill_2025-07-21.txt
├── Customers/          # (Optional) Stores customer details
├── README.md           # Project documentation
```

## 🔧 How to Run

1. Ensure you have a C++ compiler installed (e.g., g++, MinGW).
2. Open terminal or CMD in the project directory.
3. Compile the project using:
   ```
   g++ main.cpp -o billing.exe
   ```
4. Run the executable:
   ```
   .\billing.exe   // On Windows
   ```

## 🔄 Inventory Behavior

- If an item with the **same name and rate** is added, its quantity is updated.
- If an item has the **same name but a different rate**, it is treated as a **new variant** and added as a separate entry.

## 💡 Future Enhancements

- 🧑‍💼 Admin login system
- 👥 Store and view customer details
- 🧾 Export generated bills to text or PDF
- 📊 View inventory and sales analytics
- 🌐 GUI interface using Qt or Web integration
- 💾 Use of database like SQLite or MongoDB for persistent storage

## 🎯 Use Cases

This system can be used for:
- Grocery shops
- College projects
- Inventory demonstrations
- C++ file handling practice

## 📷 Screenshots
![Screenshot 2025-07-21 232719](https://github.com/user-attachments/assets/ed5f6c16-bbd5-42e3-8d2c-ea3f38c57c8e)


## 👨‍💻 Author

**Monis Sheikh**  
📫 [LinkedIn](https://linkedin.com/in/monissheikh1234)  
🔗 GitHub: [@monissheikh1234](https://github.com/monissheikh1234)


If you find this project helpful, consider giving it a ⭐ on GitHub!
