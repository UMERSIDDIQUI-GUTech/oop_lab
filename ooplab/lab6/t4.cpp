#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class AlertService {
    public:
        virtual void deliverAlert(string recipientId, string content) = 0;
};

class EmailAlert : public AlertService {
    public:
        void deliverAlert(string recipientId, string content) override {
            cout << "Emailing " << recipientId << " with message: " << content << endl;
        }
};

class SMSAlert : public AlertService {
    public:
        void deliverAlert(string recipientId, string content) override {
            cout << "Sending SMS to " << recipientId << " with message: " << content << endl;
        }
};

class InAppAlert : public AlertService {
    public:
        void deliverAlert(string recipientId, string content) override {
            cout << "Sending in-app notification to " << recipientId << ": " << content << endl;
        }
};

class AlertDispatcher {
    public:
        void triggerAlert(string recipientId, string content) {
            int randomOption = rand() % 3; 

            AlertService* service = nullptr;

            if (randomOption == 0) {
                service = new EmailAlert();
            } else if (randomOption == 1) {
                service = new SMSAlert();
            } else {
                service = new InAppAlert();
            }

            service->deliverAlert(recipientId, content);
            delete service;
        }
};

int main() {
    AlertDispatcher notifier;

    srand(time(0)); 

    notifier.triggerAlert("User_101", "You have a new course update.");
    notifier.triggerAlert("User_102", "Check out your quiz results.");
    notifier.triggerAlert("User_103", "Reminder: Project submission due tomorrow.");

    return 0;
}