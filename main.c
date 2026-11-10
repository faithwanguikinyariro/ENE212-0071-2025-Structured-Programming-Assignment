
#include <stdio.h>

// Global variable for balance so all functions can access it easily
float balance = 2500.0;
int stored_pin = 6789;

// Function Prototypes
int login();
void checkBalance();
void deposit();
void withdraw();
void showMenu();

int main() {
    // 1. PIN Check
    if (login() == 0) {
        printf("\nToo many wrong attempts. Program ending.\n");
        return 0; // Stop the program
    }

    int choice = 0;

    // 2. Main Loop: Repeatedly show menu until option 4 is selected
    while (choice != 4) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            checkBalance();
        } else if (choice == 2) {
            deposit();
        } else if (choice == 3) {
            withdraw();
        } else if (choice == 4) {
            printf("\nThank you for using the ATM. Goodbye!\n");
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}

// Requirement 1: Login Function (Returns 1 for success, 0 for failure)
int login() {
    int entered_pin;
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == stored_pin) {
            printf("Login Successful!\n");
            return 1; // Success
        } else {
            attempts++;
            printf("Wrong PIN. Attempts left: %d\n", 3 - attempts);
        }
    }

    return 0; // Failed 3 attempts
}

// Requirement 2: Display Menu
void showMenu() {
    printf("\n--- ATM MENU ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}

// Requirement 3 & 5: Check Balance
void checkBalance() {
    printf("\nYour balance is: $%.2f\n", balance);
}

// Requirement 3 & 5: Deposit Function
void deposit() {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance = balance + amount;
        printf("Deposited $%.2f successfully.\n", amount);
    } else {
        printf("Amount must be greater than 0.\n");
    }
}

// Requirement 3 & 5: Withdraw Function
void withdraw() {
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be greater than 0.\n");
    } else if (amount > balance) {
        printf("Insufficient balance! You only have $%.2f.\n", balance);
    } else {
        balance = balance - amount;
        printf("Withdrew $%.2f successfully.\n", amount);
    }
}
