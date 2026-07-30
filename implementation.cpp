#include "HungryTummy.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char* getItemName(int otherChoice, int option) {
    if (otherChoice == 1) { // Peppers
        if (option == 1) return "Bottled_Water";
        else if (option == 2) return "Coca_Cola";
        else if (option == 3) return "French_Fries";
        else if (option == 4) return "Steak_Fajitas";
        else if (option == 5) return "Chips_and_Guacamole";
        else if (option == 6) return "Molten_Chocolate_Cake";
    }
    else if (otherChoice == 2) { // Pho Pho
        if (option == 1) return "Bottled_Water";
        else if (option == 2) return "Hot_Tea";
        else if (option == 3) return "Spring_Rolls";
        else if (option == 4) return "Combination_Pho";
        else if (option == 5) return "Oxtail_Pho";
        else if (option == 6) return "Banh_Flan";
    }
     return "Unknown Item";
}

double getItemPrice(int otherChoice, int option) {
    if (otherChoice == 1) { // Peppers
        if (option == 1) return 1.50;
        else if (option == 2) return 2.50;
        else if (option == 3) return 5.75;
        else if (option == 4) return 16.50;
        else if (option == 5) return 11.99;
        else if (option == 6) return 9.99;
    }
    else if (otherChoice == 2) { // Pho Pho
        if (option == 1) return 1.50;
        else if (option == 2) return 3.50;
        else if (option == 3) return 10.75;
        else if (option == 4) return 19.99;
        else if (option == 5) return 23.50;
        else if (option == 6) return 10.00;
    }
    return 0.0;
}

const char* getNutritionFacts(int otherChoice, int option) {
    if (otherChoice == 1) { // Peppers
        if (option == 1) return "0 Cal | 0g Fat";
        else if (option == 2) return "140 Cal | 0g Fat | 39g Sugar";
        else if (option == 3) return "365 Cal | 17g Fat | 48g Carbs [Vegan, Gluten Free]";
        else if (option == 4) return "570 Cal | 34g Fat | 55g Protein";
        else if (option == 5) return "1140 Cal | 66g Fat | 16g Protein [Vegan, Gluten Free]";
        else if (option == 6) return "1170 Cal | 59g Fat | 104g Sugar [Contains Dairy]";
    }
    else if (otherChoice == 2) { // Pho Pho
        if (option == 1) return "0 Cal | 0g Fat";
        else if (option == 2) return "2 Cal | 0g Fat";
        else if (option == 3) return "120 Cal | 1g Fat | 9g Protein [Gluten Free]";
        else if (option == 4) return "500 Cal | 12g Fat | 35g Protein [Gluten Free]";
        else if (option == 5) return "550 Cal | 20g Fat | 35g Protein [Gluten Free]";
        else if (option == 6) return "222 Cal | 6g Fat | 35g Sugar [Gluten Free]";
    }
    return "Unknown Item";
}

int getItemCalories(int otherChoice, int option) {
    if (otherChoice == 1) { // Peppers
        if (option == 1) return 0;
        else if (option == 2) return 140;
        else if (option == 3) return 365;
        else if (option == 4) return 570;
        else if (option == 5) return 1140;
        else if (option == 6) return 1170;
    }
    else if (otherChoice == 2) { // Pho Pho
        if (option == 1) return 0;
        else if (option == 2) return 2;
        else if (option == 3) return 120;
        else if (option == 4) return 500;
        else if (option == 5) return 550;
        else if (option == 6) return 222;
    }
    return 0;
}

void createNewOrder(Receipt savedReceipts[], int &receiptCount) {
    Receipt newOrder;
    newOrder.orderNumber = 1000 + receiptCount;
    newOrder.itemCount = 0;
    newOrder.subtotal = 0.0;

    cout << "==========================================" << endl;
    cout << "        HUNGRYTUMMY FOOD DELIVERY         " << endl;
    cout << "==========================================" << endl;
    cout << "Enter Customer Name: ";
    cin >> ws;
    getline(cin, newOrder.customerName);

    cout << "Enter Delivery Address: ";
    getline(cin, newOrder.address);
    
    cout << "Enter Maximum Calories for this meal: ";
    cin >> newOrder.targetCalories;

    for (char &c : newOrder.customerName) if (c == ' ') c = '_';
    for (char &c : newOrder.address) if (c == ' ') c = '_';
    
    int otherChoice = 0;
    while (otherChoice != 1 && otherChoice != 2) {
        cout << "==========================================" << endl;
        cout << "            SELECT RESTAURANT             " << endl;
        cout << "==========================================" << endl;
        cout << "  1. Peppers  (American Tex-Mex Restaurant)" << endl;
        cout << "  2. Pho Pho     (Vietnamese Noodle House)" << endl;
        cout << "==========================================" << endl;
        cout << "Enter Choice (1 or 2): ";
        cin >> otherChoice;
    }

    int choice = -1;
    int maxItems = 6;
    int currentTotalCalories = 0;

    while (choice != 0) {
       if (otherChoice == 1) {
           cout << "=========== MENU (PEPPERS) ===========" << endl;
    } 
    
        else if (otherChoice == 2) {
            cout << "=========== MENU (PHO PHO) ===========" << endl;
    }

       cout << "Target Calorie Limit: " << newOrder.targetCalories << " Cal | Current Order Total: " << currentTotalCalories << " Cal" << endl;

        for (int i = 1; i <= maxItems; i++) {
            cout << left << setw(3) << i << ". " 
                 << setw(24) << getItemName(otherChoice, i) 
                 << "$" << fixed << setprecision(2) << getItemPrice(otherChoice, i) << endl;
            cout << "[Nutrition: " << getNutritionFacts(otherChoice, i) << "]" << endl;
        }
        
        cout << "0.  Proceed to Checkout" << endl;
        cout << "=========================" << endl;
        cout << "Select Item Number: ";
        cin >> choice;
        
        if (choice >= 1 && choice <= maxItems) {
            int qty;
            cout << "Enter quantity: ";
            cin >> qty;

        if (qty > 0) {
                int itemCalories = getItemCalories(otherChoice, choice);
                int addedCalories = itemCalories * qty;

                if (currentTotalCalories + addedCalories > newOrder.targetCalories) {
                    cout << "--------------------------------------------------------" << endl;
                    cout << "WARNING: Adding " << qty << "x " << getItemName(otherChoice, choice) 
                         << " (" << addedCalories << " Cal) will put your total at " 
                         << (currentTotalCalories + addedCalories) << " Cal," << endl;
                    cout << "which EXCEEDS your target limit of " << newOrder.targetCalories << " Cal!" << endl;
                    cout << "Are you sure you want to add this item anyway? (1 = Yes, 0 = No): ";
                    int confirm;
                    cin >> confirm;
                    
                    if (confirm != 1) {
                        cout << ">> Item addition canceled." << endl;
                        continue;
                    }
                }

                int index = newOrder.itemCount;
                newOrder.items[index].name = getItemName(otherChoice, choice);
                newOrder.items[index].price = getItemPrice(otherChoice, choice);
                newOrder.items[index].quantity = qty;
                newOrder.items[index].calories = itemCalories;

                newOrder.subtotal += (getItemPrice(otherChoice, choice) * qty);
                currentTotalCalories += addedCalories;
                newOrder.itemCount++;
                cout << ">> Added " << qty << "x " << getItemName(otherChoice, choice) << " to cart!" << endl;
            }
        }
    }

    if (newOrder.itemCount == 0) {
        cout << "Cart is empty. Order canceled." << endl;
        return;
    }

    newOrder.tax = newOrder.subtotal * 0.1025;
    newOrder.total = newOrder.subtotal + newOrder.tax;

    cout << "=======================================" << endl;
    cout << "           DELIVERY RECEIPT #" << newOrder.orderNumber << endl;
    cout << "=======================================" << endl;
    cout << "Customer Name:  " << newOrder.customerName << endl;
    cout << "Deliver To:     " << newOrder.address << endl;
    cout << "Restaurant:     " << (otherChoice == 1 ? "Peppers" : "Pho Pho") << endl;
    cout << "Target Limit:   " << newOrder.targetCalories << " Cal" << endl;
    cout << "Total Calories: " << currentTotalCalories << " Cal" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < newOrder.itemCount; i++) {
        cout << newOrder.items[i].quantity << "x " 
             << setw(22) << left << newOrder.items[i].name 
             << " $" << fixed << setprecision(2) << (newOrder.items[i].price * newOrder.items[i].quantity);
        cout << " (" << (newOrder.items[i].calories * newOrder.items[i].quantity) << " Cal)" << endl;
    }

    cout << "----------------------------------" << endl;
    cout << "Subtotal:        $" << fixed << setprecision(2) << newOrder.subtotal << endl;
    cout << "Taxes & Fees:    $" << fixed << setprecision(2) << newOrder.tax << endl;
    cout << "Total:           $" << fixed << setprecision(2) << newOrder.total << endl;

    savedReceipts[receiptCount] = newOrder;
    receiptCount++;
    saveToFile(savedReceipts, receiptCount);
    cout << " Order placed & saved to receipts!" << endl;
}

void updateOrder(Receipt savedReceipts[], int receiptCount) {
    if (receiptCount == 0) {
        cout << "No saved receipts found." << endl;
        return;
    }

    int targetOrder;
    cout << "Enter Order Number to Update: ";
    cin >> targetOrder;

    for (int i = 0; i < receiptCount; i++) {
        if (savedReceipts[i].orderNumber == targetOrder) {
            cout << "Updating Order #" << targetOrder << endl;
            cout << "1. Add an Item" << endl;
            cout << "2. Remove an Item" << endl;
            cout << "Select Option: ";
            int option;
            cin >> option;
            
            if (option == 1){
                int restaurantChoice, itemChoice, quantity;
                cout << "Which Restaurant (1 = Peppers, 2 = Pho Pho): ";
                cin >> restaurantChoice;
                
                if (restaurantChoice != 1 && restaurantChoice != 2) {
                 cout << ">> Invalid choice. Action canceled." << endl;
                return;
             }
             
             if (restaurantChoice == 1) {
             cout << "=========== MENU (PEPPERS) ===========" << endl;
             cout << "1. Bottled_Water - $1.50" << endl;
             cout << "   [Nutrition: 0 Cal | 0g Fat]" << endl;
             cout << "2. Coca_Cola - $2.50" << endl;
             cout << "   [Nutrition: 140 Cal | 0g Fat | 39g Sugar]" << endl;
             cout << "3. French_Fries - $5.75" << endl;
             cout << "   [Nutrition: 365 Cal | 17g Fat | 48g Carbs [Vegan, Gluten Free]]" << endl;
             cout << "4. Steak_Fajitas - $16.50" << endl;
             cout << "   [Nutrition: 570 Cal | 34g Fat | 55g Protein]" << endl;
             cout << "5. Chips_and_Guacamole - $11.99" << endl;
             cout << "   [Nutrition: 1140 Cal | 66g Fat | 16g Protein [Vegan, Gluten Free]]" << endl;
             cout << "6. Molten_Chocolate_Cake - $9.99" << endl;
             cout << "   [Nutrition: 1170 Cal | 59g Fat | 104g Sugar [Contains Dairy]]" << endl;
             cout << "=======================================" << endl;
            }
    
            else if (restaurantChoice == 2) {
            cout << "========== MENU (PHO PHO) ==========" << endl;
            cout << "1. Bottled_Water - $1.50" << endl;
            cout << "   [Nutrition: 0 Cal | 0g Fat]" << endl;
            cout << "2. Hot_Tea - $3.50" << endl;
            cout << "   [Nutrition: 2 Cal | 0g Fat]" << endl;
            cout << "3. Spring_Rolls - $10.75" << endl;
            cout << "   [Nutrition: 120 Cal | 1g Fat | 9g Protein [Gluten Free]]" << endl;
            cout << "4. Combination_Pho - $19.99" << endl;
            cout << "   [Nutrition: 500 Cal | 12g Fat | 35g Protein [Gluten Free]]" << endl;
            cout << "5. Oxtail_Pho - $23.50" << endl;
            cout << "   [Nutrition: 550 Cal | 20g Fat | 35g Protein [Gluten Free]]" << endl;
            cout << "6. Banh_Flan - $10.00" << endl;
            cout << "   [Nutrition: 222 Cal | 6g Fat | 35g Sugar [Gluten Free]]" << endl;
            cout << "=====================================" << endl;
            }

            cout << "Select Item Number: ";
            cin >> itemChoice;

            if (itemChoice < 1 || itemChoice > 6) {
            cout << ">> Invalid item choice. Action canceled." << endl;
            return;
            }

            cout << "Enter quantity (or 0 to cancel): ";
            cin >> quantity;

            if (quantity <= 0) {
            cout << ">> Addition canceled." << endl;
            return;
            }
             
            int currentTotalCalories = 0;
            for (int j = 0; j < savedReceipts[i].itemCount; j++) {
            currentTotalCalories += (savedReceipts[i].items[j].calories * savedReceipts[i].items[j].quantity);
            }

            int itemCalories = getItemCalories(restaurantChoice, itemChoice);
            int addedCalories = itemCalories * quantity;

            if (currentTotalCalories + addedCalories > savedReceipts[i].targetCalories) {
            cout << endl << "WARNING: Total (" << (currentTotalCalories + addedCalories) 
            << " Cal) exceeds target limit (" << savedReceipts[i].targetCalories << " Cal)!" << endl;
            cout << "Add anyway? (1 = Yes, 0 = No): ";
    
            int confirm;
            cin >> confirm;
            
            if (confirm != 1) {
            cout << ">> Addition canceled." << endl;
            return;
            }
        }
                
                int index = savedReceipts[i].itemCount;
                savedReceipts[i].items[index].name = getItemName(restaurantChoice, itemChoice);
                savedReceipts[i].items[index].price = getItemPrice(restaurantChoice, itemChoice);
                savedReceipts[i].items[index].quantity = quantity;
                savedReceipts[i].items[index].calories = getItemCalories(restaurantChoice, itemChoice);
                
                savedReceipts[i].itemCount++;
                cout << ">> Item added!" << endl;
            }
            
            else if (option == 2){
                cout << "Current Items in Order:" << endl;
                for (int j = 0; j < savedReceipts[i].itemCount; j++) {
                    if (savedReceipts[i].items[j].quantity > 0) {
                        cout << (j + 1) << ". " << savedReceipts[i].items[j].name << endl;
                        cout << " (Quantity: " << savedReceipts[i].items[j].quantity << ")" << endl;
                    }
                }
                
                int itemNum;
                cout << "Enter item number to remove: ";
                cin >> itemNum;

                if (itemNum >= 1 && itemNum <= savedReceipts[i].itemCount) {
                    int delIndex = itemNum - 1;

                for (int k = delIndex; k < savedReceipts[i].itemCount - 1; k++) {
                savedReceipts[i].items[k] = savedReceipts[i].items[k + 1];
                }
                
                savedReceipts[i].itemCount--;

                    saveToFile(savedReceipts, receiptCount);
                    cout << ">> Item removed!" << endl;
                }
            }
            
            savedReceipts[i].subtotal = 0.0;
            for (int j = 0; j < savedReceipts[i].itemCount; j++) {
                savedReceipts[i].subtotal += (savedReceipts[i].items[j].price * savedReceipts[i].items[j].quantity);
            }

            savedReceipts[i].tax = savedReceipts[i].subtotal * 0.1025;
            savedReceipts[i].total = savedReceipts[i].subtotal + savedReceipts[i].tax;

            saveToFile(savedReceipts, receiptCount);
            return;
        }
    }
    cout << "Order #" << targetOrder << " not found." << endl;
}

void changeAddress(Receipt savedReceipts[], int receiptCount) {
    if (receiptCount == 0) {
        cout << "No saved receipts found to update." << endl;
        return;
    }

    int targetOrder;
    cout << "Enter Order Number to change address: ";
    cin >> targetOrder;

    for (int i = 0; i < receiptCount; i++) {
        if (savedReceipts[i].orderNumber == targetOrder) {
            cout << "Current Address: " << savedReceipts[i].address << endl;
            cout << "Enter New Address: ";
            cin >> ws; 

            getline(cin, savedReceipts[i].address); 

            for (char &c : savedReceipts[i].address) {
             if (c == ' ') {
                 c = '_';
             }
        }
        
            saveToFile(savedReceipts, receiptCount);
            cout << ">> Address updated successfully!" << endl;
            return;
        }
    }
    
    cout << "Order #" << targetOrder << " not found." << endl;
}

void viewAllReceipts(Receipt savedReceipts[], int receiptCount) {
    if (receiptCount == 0) {
        cout << "No saved receipts found." << endl;
        return;
    }

    cout << "==========================================" << endl;
    cout << "               ALL RECEIPTS             " << endl;
    cout << "==========================================" << endl;

    for (int i = 0; i < receiptCount; i++) {
        cout << "Order #" << savedReceipts[i].orderNumber << endl;
        cout << "Name:    " << savedReceipts[i].customerName << endl;
        cout << "Address: " << savedReceipts[i].address << endl;
        cout << "Calories:   " << savedReceipts[i].targetCalories << " Cal" << endl;
        cout << "Total:   $" << fixed << setprecision(2) << savedReceipts[i].total << endl;
        cout << "------------------------------------------" << endl;
    }
}

void saveToFile(Receipt savedReceipts[], int receiptCount) {
    ofstream outFile("receipts.txt");
    if (!outFile) {
        cout << "Error opening receipts.txt for writing." << endl;
        return;
    }

    outFile << receiptCount << endl;
    for (int i = 0; i < receiptCount; i++) {
        outFile << savedReceipts[i].orderNumber << " "
                << savedReceipts[i].customerName << " "
                << savedReceipts[i].address << " "
                << savedReceipts[i].targetCalories << " "
                << savedReceipts[i].subtotal << " "
                << savedReceipts[i].tax << " "
                << savedReceipts[i].total << " "
                << savedReceipts[i].itemCount << endl;

        for (int j = 0; j < savedReceipts[i].itemCount; j++) {
            outFile << savedReceipts[i].items[j].name << " "
                    << savedReceipts[i].items[j].price << " "
                    << savedReceipts[i].items[j].quantity << " "
                    << savedReceipts[i].items[j].calories << endl;
        }
    }
    outFile.close();
}

void loadFromFile(Receipt savedReceipts[], int &receiptCount) {
    ifstream inFile("receipts.txt");
    if (!inFile) {
        receiptCount = 0;
        return;
    }

    if (!(inFile >> receiptCount)) {
        receiptCount = 0;
        return;
    }

    for (int i = 0; i < receiptCount; i++) {
        inFile >> savedReceipts[i].orderNumber
               >> savedReceipts[i].customerName
               >> savedReceipts[i].address
               >> savedReceipts[i].targetCalories
               >> savedReceipts[i].subtotal
               >> savedReceipts[i].tax
               >> savedReceipts[i].total
               >> savedReceipts[i].itemCount;

        for (int j = 0; j < savedReceipts[i].itemCount; j++) {
            inFile >> savedReceipts[i].items[j].name
                   >> savedReceipts[i].items[j].price
                   >> savedReceipts[i].items[j].quantity
                   >> savedReceipts[i].items[j].calories;
        }
    }
    inFile.close();
}
