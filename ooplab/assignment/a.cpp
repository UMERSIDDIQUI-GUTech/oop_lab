#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Account {
protected:
    int accountID;
    string accountType;
    double balance;
    double dailyWithdrawalLimit;
    double dailyWithdrawn;
    string lastTransactionDate;

public:
    Account() {
        accountID = 0;
        accountType = "";
        balance = 0.0;
        dailyWithdrawalLimit = 0.0;
        dailyWithdrawn = 0.0;
        lastTransactionDate = "";
    }
    
    Account(int id, string type, double limit) {
        accountID = id;
        accountType = type;
        balance = 0.0;
        dailyWithdrawalLimit = limit;
        dailyWithdrawn = 0.0;
        lastTransactionDate = "";
    }
    
    virtual ~Account() {}
    

    int getAccountID() const { return accountID; }
    string getAccountType() const { return accountType; }
    double getBalance() const { return balance; }
    double getDailyWithdrawalLimit() const { return dailyWithdrawalLimit; }

    
    virtual bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }
    
    virtual bool withdraw(double amount, string date) {
        if (canWithdraw(amount, date)) {
            balance -= amount;
            dailyWithdrawn += amount;
            lastTransactionDate = date;
            return true;
        }
        return false;
    }
    
    virtual bool transfer(double amount, Account* target, string date) {
        if (target && canWithdraw(amount, date)) {
            if (withdraw(amount, date)) {
                target->deposit(amount);
                return true;
            }
        }
        return false;
    }
    
    virtual void displayInfo() const {
        cout << "Account ID: " << accountID << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: PKR " << balance << endl;
        cout << "Daily Withdrawal Limit: PKR " << dailyWithdrawalLimit << endl;
    }
    

    void resetDailyLimit(string date) {
        if (lastTransactionDate != date) {
            dailyWithdrawn = 0.0;
            lastTransactionDate = date;
        }
    }
    
    bool canWithdraw(double amount, string date) {
        resetDailyLimit(date);
        return (amount > 0 && amount <= balance && 
                (dailyWithdrawn + amount) <= dailyWithdrawalLimit);
    }
};

class UserClient {
private:
    int userID;
    string fullName;
    string cnic;
    string address;
    string phoneNumber;
    string loginID;
    string password;
    Account* account;
    int cardNumber;
    int pinNumber;
    int wrongPinAttempts;
    bool isFraudulent;

public:
    UserClient() {
        userID = 0;
        fullName = "";
        cnic = "";
        address = "";
        phoneNumber = "";
        loginID = "";
        password = "";
        account = nullptr;
        cardNumber = 0;
        pinNumber = 0;
        wrongPinAttempts = 0;
        isFraudulent = false;
    }
    
    UserClient(int id, string name, string cnic, string addr, string phone, 
               string login, string pass, double estimatedLimit) {
        userID = id;
        fullName = name;
        this->cnic = cnic;
        address = addr;
        phoneNumber = phone;
        loginID = login;
        password = pass;
        wrongPinAttempts = 0;
        isFraudulent = false;
      
      
        cardNumber = 1000000000000000 + (id * 12345);
        pinNumber = 1000 + (id % 9000);
        
        
        string accountType;
        double limit;
        if (estimatedLimit <= 100000) {
            accountType = "Bronze";
            limit = 100000;
        } else if (estimatedLimit <= 500000) {
            accountType = "Gold";
            limit = 500000;
        } else {
            accountType = "Gold";
            limit = 500000;
        }
        
        account = new Account(userID, accountType, limit);
    }
    
    ~UserClient() {
        if (account) {
            delete account;
        }
    }
    
    
    int getUserID() const { return userID; }
    string getFullName() const { return fullName; }
    string getCNIC() const { return cnic; }
    string getLoginID() const { return loginID; }
    string getPassword() const { return password; }
    Account* getAccount() { return account; }
    int getCardNumber() const { return cardNumber; }
    int getPinNumber() const { return pinNumber; }

    
    bool login(string loginID, string password) {
        return (this->loginID == loginID && this->password == password);
    }
    
    bool verifyCard(int cardNum, int pin) {
        if (cardNum == cardNumber && pin == pinNumber) {
            wrongPinAttempts = 0;
            return true;
        } else {
            wrongPinAttempts++;
            if (wrongPinAttempts >= 3) {
                isFraudulent = true;
                cout << "Account marked as fraudulent due to multiple wrong PIN attempts!" << endl;
            }
            return false;
        }
    }
    
    void displayInfo() const {
        cout << "User ID: " << userID << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Login ID: " << loginID << endl;
        if (account) {
            account->displayInfo();
        }
    }
    
    void saveToFile() {
        ofstream file("users.txt", ios::app);
        if (file.is_open()) {
            file << userID << ", " << fullName << ", " << cnic << ", " << address << ", "
                 << phoneNumber << ", " << loginID << ", " << password << ", "
                 << account->getAccountType() << ", " << account->getBalance() << endl;
            file.close();
        }
        
    
        ofstream cardFile("cards.txt", ios::app);
        if (cardFile.is_open()) {
            cardFile << userID << ", " << cardNumber << ", " << pinNumber << endl;
            cardFile.close();
        }
    }
    
  
    static bool validateCNIC(string cnic) {
        return cnic.length() == 13 && cnic.find_first_not_of("0123456789") == string::npos;
    }
    
    static bool validatePhone(string phone) {
        return phone.length() == 11 && phone.find_first_not_of("0123456789") == string::npos;
    }
};


class CompanyClient {
private:
    int companyID;
    string companyName;
    string companyAddress;
    string companyTaxNumber;
    string accountID;
    string accountPassword;
    Account* account;

public:
    CompanyClient() {
        companyID = 0;
        companyName = "";
        companyAddress = "";
        companyTaxNumber = "";
        accountID = "";
        accountPassword = "";
        account = nullptr;
    }
    
    CompanyClient(int id, string name, string addr, string taxNum, 
                  string accID, string accPass, double estimatedLimit) {
        companyID = id;
        companyName = name;
        companyAddress = addr;
        companyTaxNumber = taxNum;
        accountID = accID;
        accountPassword = accPass;
        
    
        string accountType;
        double limit;
        if (estimatedLimit <= 100000) {
            accountType = "Bronze";
            limit = 100000;
        } else if (estimatedLimit <= 500000) {
            accountType = "Gold";
            limit = 500000;
        } else {
            accountType = "Business";
            limit = 20000000;
        }
        
        account = new Account(companyID, accountType, limit);
    }
    
    ~CompanyClient() {
        if (account) {
            delete account;
        }
    }
    
    // Getters
    int getCompanyID() const { return companyID; }
    string getCompanyName() const { return companyName; }
    string getAccountID() const { return accountID; }
    string getAccountPassword() const { return accountPassword; }
    Account* getAccount() { return account; }
    

    bool login(string accID, string password) {
        return (this->accountID == accID && this->accountPassword == password);
    }
    
    void displayInfo() const {
        cout << "Company ID: " << companyID << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Company Address: " << companyAddress << endl;
        cout << "Tax Number: " << companyTaxNumber << endl;
        cout << "Account ID: " << accountID << endl;
        if (account) {
            account->displayInfo();
        }
    }
    
    void saveToFile() {
        ofstream file("companies.txt", ios::app);
        if (file.is_open()) {
            file << companyID << ", " << companyName << ", " << companyAddress << ", "
                 << companyTaxNumber << ", " << accountID << ", " << accountPassword << ", "
                 << account->getBalance() << endl;
            file.close();
        }
    }
};

class BankingEmployee {
private:
    int employeeID;
    string employeeName;
    string password;

public:
    BankingEmployee() {
        employeeID = 0;
        employeeName = "";
        password = "";
    }
    
    BankingEmployee(int id, string name, string pass) {
        employeeID = id;
        employeeName = name;
        password = pass;
    }
    

    bool login(int id, string pass) {
        return (employeeID == id && password == pass);
    }
    
    void viewAllAccounts() {
        cout << "Viewing all accounts..." << endl;
    }
    
    void approveAccount(int userID) {
        cout << "Account " << userID << " approved." << endl;
    }
    
    void rejectAccount(int userID) {
        cout << "Account " << userID << " rejected." << endl;
    }
    
    void approveLoan(int companyID) {
        cout << "Loan for company " << companyID << " approved." << endl;
    }
    
    void rejectLoan(int companyID) {
        cout << "Loan for company " << companyID << " rejected." << endl;
    }
    
    void viewTransactionHistory(int accountID) {
        cout << "Viewing transaction history for account " << accountID << endl;
    }
    
    void freezeAccount(int accountID) {
        cout << "Account " << accountID << " frozen." << endl;
    }
    
    void closeAccount(int accountID) {
        cout << "Account " << accountID << " closed." << endl;
    }
};


class Transaction {
private:
    string date;
    int sourceID;
    double amount;
    string type;
    int targetID;

public:
    Transaction() {
        date = "";
        sourceID = 0;
        amount = 0.0;
        type = "";
        targetID = -1;
    }
    
    Transaction(string date, int source, double amt, string type, int target = -1) {
        this->date = date;
        sourceID = source;
        amount = amt;
        this->type = type;
        targetID = target;
    }
    
    void saveToFile() {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << date << ", " << sourceID << ", " << amount << ", " << type;
            if (targetID != -1) {
                file << ", " << targetID;
            }
            file << endl;
            file.close();
        }
    }
    
    static void displayTransactions(int accountID) {
        ifstream file("transactions.txt");
        string line;
        cout << "Transaction History for Account " << accountID << ":" << endl;
        while (getline(file, line)) {
            if (line.find(to_string(accountID)) != string::npos) {
                cout << line << endl;
            }
        }
    }
};

class BankingSystem {
private:
    UserClient** users;
    int userCount;
    int userCapacity;
    
    CompanyClient** companies;
    int companyCount;
    int companyCapacity;
    
    BankingEmployee** employees;
    int employeeCount;
    int employeeCapacity;

public:
    BankingSystem() {
        userCapacity = 10;
        userCount = 0;
        users = new UserClient*[userCapacity];
        
        companyCapacity = 10;
        companyCount = 0;
        companies = new CompanyClient*[companyCapacity];
        
        employeeCapacity = 10;
        employeeCount = 0;
        employees = new BankingEmployee*[employeeCapacity];
    }
    
    ~BankingSystem() {
        for (int i = 0; i < userCount; i++) {
            delete users[i];
        }
        delete[] users;
        
        for (int i = 0; i < companyCount; i++) {
            delete companies[i];
        }
        delete[] companies;
        
        for (int i = 0; i < employeeCount; i++) {
            delete employees[i];
        }
        delete[] employees;
    }
    

    void addUser(UserClient* user) {
        if (userCount >= userCapacity) {
            UserClient** newUsers = new UserClient*[userCapacity * 2];
            for (int i = 0; i < userCount; i++) {
                newUsers[i] = users[i];
            }
            delete[] users;
            users = newUsers;
            userCapacity *= 2;
        }
        users[userCount++] = user;
    }
    
    UserClient* findUser(int userID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getUserID() == userID) {
                return users[i];
            }
        }
        return nullptr;
    }
    
    UserClient* findUserByLogin(string loginID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getLoginID() == loginID) {
                return users[i];
            }
        }
        return nullptr;
    }
    
    int getUserCount() const { return userCount; }
    
    void addCompany(CompanyClient* company) {
        if (companyCount >= companyCapacity) {
            CompanyClient** newCompanies = new CompanyClient*[companyCapacity * 2];
            for (int i = 0; i < companyCount; i++) {
                newCompanies[i] = companies[i];
            }
            delete[] companies;
            companies = newCompanies;
            companyCapacity *= 2;
        }
        companies[companyCount++] = company;
    }
    
    CompanyClient* findCompany(int companyID) {
        for (int i = 0; i < companyCount; i++) {
            if (companies[i]->getCompanyID() == companyID) {
                return companies[i];
            }
        }
        return nullptr;
    }
    
    CompanyClient* findCompanyByAccountID(string accountID) {
        for (int i = 0; i < companyCount; i++) {
            if (companies[i]->getAccountID() == accountID) {
                return companies[i];
            }
        }
        return nullptr;
    }
    
    int getCompanyCount() const { return companyCount; }
    

    void addEmployee(BankingEmployee* employee) {
        if (employeeCount >= employeeCapacity) {
            BankingEmployee** newEmployees = new BankingEmployee*[employeeCapacity * 2];
            for (int i = 0; i < employeeCount; i++) {
                newEmployees[i] = employees[i];
            }
            delete[] employees;
            employees = newEmployees;
            employeeCapacity *= 2;
        }
        employees[employeeCount++] = employee;
    }
    
    BankingEmployee* findEmployee(int employeeID) {
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i]->login(employeeID, "")) {
                return employees[i];
            }
        }
        return nullptr;
    }
    
    void showMainMenu() {
        cout << "\n=== GuTech's  Bank Management System ===" << endl;
        cout << "1. User Client Login" << endl;
        cout << "2. Company Client Login" << endl;
        cout << "3. Banking Employee Login" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
    }
    
    void userClientMenu() {
        cout << "\n=== User Client Menu ===" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. View Balance" << endl;
        cout << "5. View Transaction History" << endl;
        cout << "6. Logout" << endl;
        cout << "Enter your choice: ";
    }
    
    void companyClientMenu() {
        cout << "\n=== Company Client Menu ===" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. View Balance" << endl;
        cout << "5. View Transaction History" << endl;
        cout << "6. Request Loan" << endl;
        cout << "7. Logout" << endl;
        cout << "Enter your choice: ";
    }
    
    void employeeMenu() {
        cout << "\n=== Banking Employee Menu ===" << endl;
        cout << "1. View All Accounts" << endl;
        cout << "2. Approve/Reject Account" << endl;
        cout << "3. Approve/Reject Loan" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. Freeze Account" << endl;
        cout << "6. Close Account" << endl;
        cout << "7. Logout" << endl;
        cout << "Enter your choice: ";
    }
};

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[11];
    sprintf(buffer, "%02d-%02d-%04d", ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    return string(buffer);
}

int getIntInput() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> input;
    }
    return input;
}

double getDoubleInput() {
    double input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> input;
    }
    return input;
}

void handleUserClient(BankingSystem& bank, UserClient* user) {
    int choice;
    string currentDate = getCurrentDate();
    
    do {
        bank.userClientMenu();
        choice = getIntInput();
        
        switch (choice) {
            case 1: {
                cout << "Enter amount to deposit: ";
                double amount = getDoubleInput();
                if (user->getAccount()->deposit(amount)) {
                    cout << "Deposit successful! New balance: PKR " << user->getAccount()->getBalance() << endl;
                    Transaction trans(currentDate, user->getUserID(), amount, "Deposit");
                    trans.saveToFile();
                } else {
                    cout << "Invalid amount for deposit." << endl;
                }
                break;
            }
            case 2: { 
                cout << "Enter card number: ";
                int cardNum = getIntInput();
                cout << "Enter PIN: ";
                int pin = getIntInput();
                
                if (user->verifyCard(cardNum, pin)) {
                    cout << "Enter amount to withdraw: ";
                    double amount = getDoubleInput();
                    if (user->getAccount()->withdraw(amount, currentDate)) {
                        cout << "Withdrawal successful! New balance: PKR " << user->getAccount()->getBalance() << endl;
                        Transaction trans(currentDate, user->getUserID(), amount, "Withdraw");
                        trans.saveToFile();
                    } else {
                        cout << "Withdrawal failed. Check your balance and daily limit." << endl;
                    }
                } else {
                    cout << "Invalid card number or PIN." << endl;
                }
                break;
            }
            case 3: { 
                cout << "Enter card number: ";
                int cardNum = getIntInput();
                cout << "Enter PIN: ";
                int pin = getIntInput();
                
                if (user->verifyCard(cardNum, pin)) {
                    cout << "Enter target user ID: ";
                    int targetID = getIntInput();
                    UserClient* target = bank.findUser(targetID);
                    
                    if (target) {
                        cout << "Enter amount to transfer: ";
                        double amount = getDoubleInput();
                        if (user->getAccount()->transfer(amount, target->getAccount(), currentDate)) {
                            cout << "Transfer successful! New balance: PKR " << user->getAccount()->getBalance() << endl;
                            Transaction trans(currentDate, user->getUserID(), amount, "Transfer", targetID);
                            trans.saveToFile();
                        } else {
                            cout << "Transfer failed. Check your balance and daily limit." << endl;
                        }
                    } else {
                        cout << "Target user not found." << endl;
                    }
                } else {
                    cout << "Invalid card number or PIN." << endl;
                }
                break;
            }
            case 4: { 
                cout << "Current Balance: PKR " << user->getAccount()->getBalance() << endl;
                break;
            }
            case 5: { 
                Transaction::displayTransactions(user->getUserID());
                break;
            }
            case 6: { 
                cout << "Logging out..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}


void handleCompanyClient(BankingSystem& bank, CompanyClient* company) {
    int choice;
    string currentDate = getCurrentDate();
    
    do {
        bank.companyClientMenu();
        choice = getIntInput();
        
        switch (choice) {
            case 1: { 
                cout << "Enter amount to deposit: ";
                double amount = getDoubleInput();
                if (company->getAccount()->deposit(amount)) {
                    cout << "Deposit successful! New balance: PKR " << company->getAccount()->getBalance() << endl;
                    Transaction trans(currentDate, company->getCompanyID(), amount, "Deposit");
                    trans.saveToFile();
                } else {
                    cout << "Invalid amount for deposit." << endl;
                }
                break;
            }
            case 2: { 
                cout << "Enter amount to withdraw: ";
                double amount = getDoubleInput();
                if (company->getAccount()->withdraw(amount, currentDate)) {
                    cout << "Withdrawal successful! New balance: PKR " << company->getAccount()->getBalance() << endl;
                    Transaction trans(currentDate, company->getCompanyID(), amount, "Withdraw");
                    trans.saveToFile();
                } else {
                    cout << "Withdrawal failed. Check your balance and daily limit." << endl;
                }
                break;
            }
            case 3: { 
                cout << "Enter target user ID: ";
                int targetID = getIntInput();
                UserClient* target = bank.findUser(targetID);
                
                if (target) {
                    cout << "Enter amount to transfer: ";
                    double amount = getDoubleInput();
                    if (company->getAccount()->transfer(amount, target->getAccount(), currentDate)) {
                        cout << "Transfer successful! New balance: PKR " << company->getAccount()->getBalance() << endl;
                        Transaction trans(currentDate, company->getCompanyID(), amount, "Transfer", targetID);
                        trans.saveToFile();
                    } else {
                        cout << "Transfer failed. Check your balance and daily limit." << endl;
                    }
                } else {
                    cout << "Target user not found." << endl;
                }
                break;
            }
            case 4: { 
                cout << "Current Balance: PKR " << company->getAccount()->getBalance() << endl;
                break;
            }
            case 5: { 
                Transaction::displayTransactions(company->getCompanyID());
                break;
            }
            case 6: { 
                cout << "Loan request submitted for approval." << endl;
                break;
            }
            case 7: {
                cout << "Logging out..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

void handleEmployee(BankingSystem& bank, BankingEmployee* employee) {
    int choice;
    
    do {
        bank.employeeMenu();
        choice = getIntInput();
        
        switch (choice) {
            case 1: { 
                employee->viewAllAccounts();
                break;
            }
            case 2: { 
                cout << "Enter user ID: ";
                int userID = getIntInput();
                cout << "1. Approve\n2. Reject\nEnter choice: ";
                int approveChoice = getIntInput();
                if (approveChoice == 1) {
                    employee->approveAccount(userID);
                } else if (approveChoice == 2) {
                    employee->rejectAccount(userID);
                }
                break;
            }
            case 3: { 
                cout << "Enter company ID: ";
                int companyID = getIntInput();
                cout << "1. Approve\n2. Reject\nEnter choice: ";
                int approveChoice = getIntInput();
                if (approveChoice == 1) {
                    employee->approveLoan(companyID);
                } else if (approveChoice == 2) {
                    employee->rejectLoan(companyID);
                }
                break;
            }
            case 4: {
                cout << "Enter account ID: ";
                int accountID = getIntInput();
                employee->viewTransactionHistory(accountID);
                break;
            }
            case 5: { 
                cout << "Enter account ID: ";
                int accountID = getIntInput();
                employee->freezeAccount(accountID);
                break;
            }
            case 6: { 
                cout << "Enter account ID: ";
                int accountID = getIntInput();
                employee->closeAccount(accountID);
                break;
            }
            case 7: { 
                cout << "Logging out..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

void createUserAccount(BankingSystem& bank) {
    cout << "\n=== Create New User Account ===" << endl;
    
    string fullName, cnic, address, phoneNumber, loginID, password;
    double estimatedLimit;
    
    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, fullName);
    
    cout << "Enter CNIC (13 digits): ";
    cin >> cnic;
    while (!UserClient::validateCNIC(cnic)) {
        cout << "Invalid CNIC. Please enter 13 digits: ";
        cin >> cnic;
    }
    
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    
    cout << "Enter phone number (11 digits): ";
    cin >> phoneNumber;
    while (!UserClient::validatePhone(phoneNumber)) {
        cout << "Invalid phone number. Please enter 11 digits: ";
        cin >> phoneNumber;
    }
    
    cout << "Enter login ID: ";
    cin >> loginID;
    
    cout << "Enter password: ";
    cin >> password;
    
    cout << "Enter estimated daily withdrawal limit: ";
    estimatedLimit = getDoubleInput();
    

    int userID = 1000 + bank.getUserCount();
    
    UserClient* newUser = new UserClient(userID, fullName, cnic, address, phoneNumber, 
                                        loginID, password, estimatedLimit);
    bank.addUser(newUser);
    newUser->saveToFile();
    
    cout << "Account created successfully! User ID: " << userID << endl;
    cout << "Card Number: " << newUser->getCardNumber() << endl;
    cout << "PIN: " << newUser->getPinNumber() << endl;
}

void createCompanyAccount(BankingSystem& bank) {
    cout << "\n=== Create New Company Account ===" << endl;
    
    string companyName, companyAddress, companyTaxNumber, accountID, accountPassword;
    double estimatedLimit;
    
    cout << "Enter company name: ";
    cin.ignore();
    getline(cin, companyName);
    
    cout << "Enter company address: ";
    getline(cin, companyAddress);
    
    cout << "Enter company tax number: ";
    cin >> companyTaxNumber;
    
    cout << "Enter account ID: ";
    cin >> accountID;
    
    cout << "Enter account password: ";
    cin >> accountPassword;
    
    cout << "Enter estimated daily withdrawal limit: ";
    estimatedLimit = getDoubleInput();
    

    int companyID = 2000 + bank.getCompanyCount();
    
    CompanyClient* newCompany = new CompanyClient(companyID, companyName, companyAddress, 
                                                 companyTaxNumber, accountID, accountPassword, estimatedLimit);
    bank.addCompany(newCompany);
    newCompany->saveToFile();
    
    cout << "Company account created successfully! Company ID: " << companyID << endl;
}

int main() {
    BankingSystem bank;
    

    UserClient* user1 = new UserClient(1001, "Ahmed Ali", "4210112653831", 
                                      "North Nazimabad Karachi Pakistan", "923335829802", 
                                      "Ahmed_Ali", "AhmedAliPassword", 50000);
    bank.addUser(user1);
    
    CompanyClient* company1 = new CompanyClient(2001, "XYZ Company", 
                                               "North Nazimabad Karachi Pakistan", "29373",
                                               "company_xyz", "password204", 1000000);
    bank.addCompany(company1);
    
    BankingEmployee* employee1 = new BankingEmployee(3001, "Bank Manager", "admin123");
    bank.addEmployee(employee1);
    
    int choice;
    do {
        bank.showMainMenu();
        choice = getIntInput();
        
        switch (choice) {
            case 1: { 
                cout << "1. Login\n2. Create New Account\nEnter choice: ";
                int loginChoice = getIntInput();
                
                if (loginChoice == 1) {
                    string loginID, password;
                    cout << "Enter login ID: ";
                    cin >> loginID;
                    cout << "Enter password: ";
                    cin >> password;
                    
                    UserClient* user = bank.findUserByLogin(loginID);
                    if (user && user->login(loginID, password)) {
                        cout << "Login successful!" << endl;
                        handleUserClient(bank, user);
                    } else {
                        cout << "Invalid login credentials." << endl;
                    }
                } else if (loginChoice == 2) {
                    createUserAccount(bank);
                }
                break;
            }
            case 2: { 
                cout << "1. Login\n2. Create New Account\nEnter choice: ";
                int loginChoice = getIntInput();
                
                if (loginChoice == 1) {
                    string accountID, password;
                    cout << "Enter account ID: ";
                    cin >> accountID;
                    cout << "Enter password: ";
                    cin >> password;
                    
                    CompanyClient* company = bank.findCompanyByAccountID(accountID);
                    if (company && company->login(accountID, password)) {
                        cout << "Login successful!" << endl;
                        handleCompanyClient(bank, company);
                    } else {
                        cout << "Invalid login credentials." << endl;
                    }
                } else if (loginChoice == 2) {
                    createCompanyAccount(bank);
                }
                break;
            }
            case 3: { 
                int employeeID;
                string password;
                cout << "Enter employee ID: ";
                employeeID = getIntInput();
                cout << "Enter password: ";
                cin >> password;
                
                BankingEmployee* employee = bank.findEmployee(employeeID);
                if (employee && employee->login(employeeID, password)) {
                    cout << "Login successful!" << endl;
                    handleEmployee(bank, employee);
                } else {
                    cout << "Invalid login credentials." << endl;
                }
                break;
            }
            case 4: { 
                cout << "Thank you for using GuTech's Bank Management System!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
