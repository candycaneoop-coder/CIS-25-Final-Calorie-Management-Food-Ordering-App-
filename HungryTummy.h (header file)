#pragma once
#include <string>

struct OrderItem{
    std::string name;
    double price;
    int quantity;
    int calories;
};

struct Receipt{
    int orderNumber;
    std::string customerName;
    std::string address;
    int targetCalories;
    OrderItem items[100];
    int itemCount;
    double subtotal;
    double tax;
    double total;
};

const char* getItemName(int otherChoice, int option);
double getItemPrice(int otherChoice, int option);
const char* getNutritionFacts(int otherChoice, int option);
int getItemCalories(int otherChoice, int option);

void loadFromFile(Receipt savedReceipts[], int &receiptCount);
void saveToFile(Receipt savedReceipts[], int receiptCount);
void createNewOrder(Receipt savedReceipts[], int &receiptCount);
void updateOrder(Receipt savedReceipts[], int receiptCount);
void changeAddress(Receipt savedReceipts[], int receiptCount);
void viewAllReceipts(Receipt savedReceipts[], int receiptCount);
