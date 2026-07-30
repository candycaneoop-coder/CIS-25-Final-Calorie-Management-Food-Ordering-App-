#include <iostream>
#include "HungryTummy.h"

using namespace std;

int main() {
    Receipt savedReceipts [100];
    int ReceiptCount = 0;
    loadFromFile(savedReceipts, ReceiptCount);
    
    int option;
    
    do{
        cout << "===HUNGRY TUMMY: #1 ONLINE FOOD ORDERING APP===" << endl;
        cout << "1. Create an Order" << endl;
        cout << "2. Update Order" << endl;
        cout << "3. Update Address" << endl;
        cout << "4. View Saved Reciepts" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose Option: " << endl;
        cin >> option;
        
    if (option == 1) {
            createNewOrder(savedReceipts, ReceiptCount);
        }
        else if (option == 2) {
            updateOrder(savedReceipts, ReceiptCount);
        }
        else if (option == 3) {
            changeAddress(savedReceipts, ReceiptCount);
        }
        else if (option == 4) {
            viewAllReceipts(savedReceipts, ReceiptCount);
        }
        else if (option == 5) {
            saveToFile(savedReceipts, ReceiptCount);
            cout << "Thank you! Come back soon!" << endl;
        }
        else {
            cout << "Invalid option, only choose between 1-5" << endl;
        }

    } while (option != 5);

    return 0;
}
