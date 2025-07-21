#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

class Bill {
private:
    string Item;
    int Rate, Quantity;
public:
    Bill() : Item(""), Rate(0), Quantity(0) { }

    void setItem(string item) { Item = item; }
    void setRate(int rate) { Rate = rate; }
    void setQuant(int quant) { Quantity = quant; }

    string getItem() { return Item; }
    int getRate() { return Rate; }
    int getQuant() { return Quantity; }
};

bool adminLogin() {
    string username, password;
    cout << "\n\tEnter Username: ";
    cin >> username;
    cout << "\tEnter Password: ";
    cin >> password;

    if (username == "admin" && password == "1234") {
        cout << "\tLogin Successful!\n";
        Sleep(1000);
        return true;
    } else {
        cout << "\tInvalid Credentials! Exiting...\n";
        Sleep(2000);
        return false;
    }
}
void addItem(Bill b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\n\t1. Add Item\n\t2. Back\n\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;
            cout << "\tEnter Item Name: ";
            cin >> item;
            cout << "\tEnter Rate Of Item: ";
            cin >> rate;
            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;

            ifstream in("Inventory.txt");
            ofstream temp("TempInventory.txt");
            string invItem;
            int invRate, invQty;
            bool found = false;

            while (in >> invItem >> invRate >> invQty) {
                if (invItem == item && invRate == rate) {
                    found = true;
                    invQty += quant;
                    temp << invItem << " " << invRate << " " << invQty << endl;
                } else {
                    temp << invItem << " " << invRate << " " << invQty << endl;
                }
            }

            if (!found) {
                // Add as new entry
                temp << item << " " << rate << " " << quant << endl;
            }

            in.close();
            temp.close();
            remove("Inventory.txt");
            rename("TempInventory.txt", "Inventory.txt");

            cout << "\tItem Added or Updated Successfully!\n";
            Sleep(1500);
        } else if (choice == 2) {
            close = true;
        }
    }
}



void viewInventory() {
    ifstream in("Inventory.txt");
    string item;
    int rate, quant;
    cout << "\n\tItem\tRate\tQuantity\n";
    cout << "\t------------------------------\n";
    while (in >> item >> rate >> quant) {
        cout << "\t" << item << "\t" << rate << "\t" << quant << endl;
    }
    in.close();
    system("pause");
}

void generateBill() {
    system("cls");
    string customer;
    cout << "\n\tEnter Customer Name: ";
    cin >> customer;

    int total = 0;
    ofstream exportBill;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream filename;
    filename << "Bill_" << customer << "_"
             << 1900 + ltm->tm_year << "_"
             << 1 + ltm->tm_mon << "_"
             << ltm->tm_mday << "_"
             << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << ".txt";

    exportBill.open(filename.str());

    exportBill << "Customer Name: " << customer << endl;
    exportBill << "--------------------------------------\n";
    exportBill << "Item\tRate\tQty\tAmount\n";

    bool done = false;
    while (!done) {
        string item;
        int buyQty;
        cout << "\n\tEnter Item Name: ";
        cin >> item;
        cout << "\tEnter Quantity: ";
        cin >> buyQty;

        ifstream in("Inventory.txt");
        ofstream out("TempInventory.txt");
        string invItem;
        int invRate, invQty;
        bool found = false;

        while (in >> invItem >> invRate >> invQty) {
            if (item == invItem) {
                found = true;
                if (buyQty <= invQty) {
                    int amount = invRate * buyQty;
                    total += amount;
                    exportBill << invItem << "\t" << invRate << "\t" << buyQty << "\t" << amount << endl;
                    invQty -= buyQty;
                } else {
                    cout << "\tNot enough stock!\n";
                }
            }
            out << invItem << " " << invRate << " " << invQty << endl;
        }

        if (!found)
            cout << "\tItem not found!\n";

        in.close();
        out.close();
        remove("Inventory.txt");
        rename("TempInventory.txt", "Inventory.txt");

        char more;
        cout << "\tAdd more items? (y/n): ";
        cin >> more;
        if (more == 'n' || more == 'N')
            done = true;
    }

    float gst = total * 0.18;
    float finalTotal = total + gst;
    exportBill << "--------------------------------------\n";
    exportBill << "Subtotal:\t\t" << total << endl;
    exportBill << "GST (18%):\t\t" << gst << endl;
    exportBill << "Total:\t\t\t" << finalTotal << endl;
    exportBill << "--------------------------------------\n";
    exportBill << "Thank you for shopping with us!\n";

    exportBill.close();
    cout << "\n\tBill Generated & Saved As: " << filename.str() << "\n";
    Sleep(3000);
}

int main() {
    if (!adminLogin()) return 0;

    Bill b;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\n\tWelcome to Supermarket Billing System";
        cout << "\n\t************************************";
        cout << "\n\t1. Add Item to Inventory";
        cout << "\n\t2. View Inventory";
        cout << "\n\t3. Create and Print Bill";
        cout << "\n\t4. Exit";
        cout << "\n\tEnter Choice: ";
        cin >> val;

        switch (val) {
            case 1: system("cls"); addItem(b); break;
            case 2: system("cls"); viewInventory(); break;
            case 3: system("cls"); generateBill(); break;
            case 4: exit = true; break;
            default: cout << "\tInvalid Option!\n"; Sleep(1000); break;
        }
    }

    cout << "\n\tGoodbye!\n";
    return 0;
}
