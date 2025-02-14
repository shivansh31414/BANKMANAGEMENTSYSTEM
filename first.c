#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountnumber;
    char holdername[100];
    double balance;
};

int account_count = 0;
struct Account accounts[100];

void withdraw() {
    int accountNumber;
    double amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    printf("Enter Amount to Withdraw: ");
    scanf("%lf", &amount);
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].accountnumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void createAccount() {
    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountnumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.holdername);
    newAccount.balance = 0.0;
    accounts[account_count++] = newAccount;
    printf("Account created successfully!\n");
}

void viewAccount() {
    for (int i = 0; i < account_count; i++) {
        printf("Account number: %d, Holder Name: %s, Balance: %.2f\n",
            accounts[i].accountnumber, accounts[i].holdername, accounts[i].balance);
    }
}

void deposit() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to be deposited: ");
    scanf("%lf", &amount);
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].accountnumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Amount deposited successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("Please enter a choice: \n1. Create Account\n2. View Account\n3. Deposit\n4. Withdraw\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
