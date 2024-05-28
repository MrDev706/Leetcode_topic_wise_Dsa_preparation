





#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include"payment.h"

const std::string ALL = "all";

class Bank
{
private:
    std ::unordered_map<std ::string, std ::unordered_set<std ::string>> bank_list;

public:
    void addBank(std ::string bankName, std::vector<std::string> mode_vector = {}, std::string mode = ALL)
    {
        if (checkIfAlreadyExists(bankName))
        {
            std ::cout << "Bank already exists cannot be added again" << std::endl;
        }
        else if (mode_vector.size() != 0)
        {
            addData(bank_list, bankName, mode_vector);
        }
        else if (mode == ALL)
        {
            addAllModeData(bankName);
        }
    }
    void addData(std ::unordered_map<std ::string, std ::unordered_set<std ::string>> &bank_list, std::string bankName, std::vector<std::string> &mode_vector)
    {
        for (auto m : mode_vector)
        {
            bank_list[bankName].insert(m);
        }
        std ::cout << " All modes added to bank " << bankName << std::endl;
    }
    void addAllModeData(std::string bankName)
    {
        Payment pay;
        std ::unordered_set<std::string> allModes = pay.getSupportedPaymodes();

        for (auto m : allModes)
        {
            bank_list[bankName].insert(m);
        }
    }
    bool checkIfAlreadyExists(std::string bankName)
    {
        if (bankName == "")
        {
            std ::cout << "Bank name cannot be empty" << std::endl;
            return false;
        }
        else
        {
            if (bank_list.find(bankName) == bank_list.end())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
};```


////////////----------------------------------//





//client.h

 #include<iostream>
#include<unordered_set>
#include<string>
#include"payment.h"
#include"router.h"

class Client
{
private:
    std ::unordered_set<std ::string> client_list;
    Payment payment;
    Router router;
    const std ::int64_t CARD_NUMBER = 1234567890123;
    const std ::int32_t CVV = 123;
    const std ::string EXPIRY_DATE = "2023-01-01";
    const std ::string UPI_ID = "abcd@okaxis";

public:
    void addClient(std ::string val)
    {
        if (client_list.find(val) == client_list.end())
        {
            client_list.insert(val);
            std::cout << "client " << val << " added to client list" << std::endl;
        }
        else
        {
            std::cout << "client " << val << " already added to client list" << std::endl;
        }
    }
    void removeClient(std ::string val)
    {
        if (client_list.find(val) != client_list.end())
        {
            client_list.erase(val);
            std::cout << "client " << val << " removed !!! " << std::endl;
        }
        else
        {
            std::cout << "client " << val << " does not exist" << std::endl;
        }
    }
    void hasClient(std ::string val)
    {
        if (client_list.find(val) != client_list.end())
        {
            std::cout << "client " << val << " exists" << std::endl;
        }
        else
        {
            std::cout << "client " << val << " does not exist" << std::endl;
        }
    }
    void choosePayments(std::string name, std::string mode)
    {
        if (checkForValidity(name, mode))
        {
            if (payment.checkIfPaymentModeExistedForTheClient(name, mode))
            {
                dependingUponModeSelectPaymentGateway(mode, name);
            }
        }
    }
    bool checkForValidity(std::string name, std::string mode)
    {
        if (name.empty() || mode.empty())
            return false;

        else
            return true;
    }
    void dependingUponModeSelectPaymentGateway(std ::string mode, std::string name)
    {

        std ::cout << "Processing !!!!" << std ::endl;
        if (mode == "NET_BANKING")
        {
            router.routeForNetBanking(name, name);
        }
        if (mode == "CARD")
        {
            router.routeForCreditCard(CARD_NUMBER, EXPIRY_DATE, name, CVV);
        }
        if (mode == "UPI")
        {
            router.routeForUPI(UPI_ID);
        }
    }
};
//hdfc.h

 #include<iostream>
#include<string>
#include<chrono>
#include<ctime>
#include<sstream>
#include"centralBankingSystem.h"
class HDFC
{
private:
    CentralSystem cs;
    std::int32_t cardNumber;
    std::int32_t cvv;
    std ::string expiryDate;
    std ::string cardHolderName;

public:
    void makePaymentViaUPI(std ::string upiId)
    {
        if (upiId.length() == 0)
        {
            std ::cout << "upiId is empty" << std::endl;
        }
        else
        {
            std ::cout << "Payment via HDFC bank" << std::endl;
            cs.makePaymentViaUPI(upiId);
        }
    }
    void makePaymentViaCreditCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (checkForValidity(cardNumber, expiryDate, cardHolderName, cvv))
        {
            std ::cout << "Payment via HDFC bank" << std::endl;
            cs.makePaymentViaCreditCard();
        }
    }

    void makePaymentViaDebitCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (checkForValidity(cardNumber, expiryDate, cardHolderName, cvv))
        {
            std ::cout << "Payment via HDFC bank" << std::endl;
            cs.makePaymentViaDebitCard();
        }
    }
    void makePaymentViaNetBanking(std::string userName, std::string password)
    {
        if (checkForUsernameAndPassword(userName, password))
        {
            std ::cout << "Payment via ICICI bank" << std::endl;
            cs.makePaymentViaNetBanking();
        }
    }

    bool checkForUsernameAndPassword(std ::string userName, std::string password)
    {
        if (userName.length() == 0 || password.length() == 0)
            return false;
        else
            return true;
    }

    bool checkForValidity(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (cardHolderName.length() == 0 || std::to_string(cvv).size() < 3 || std::to_string(cardNumber).length() != 12 || expiryDate >= returnCurrentDate())

        {
            std ::cout << "Invalid card Details" << std::endl;
            return false;
        }

        else
            return true;
    }

    std::string returnCurrentDate()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::ctime(&currentTime);
        return ss.str();
    }
};
//icici.h

 #include<iostream>
#include<string>
#include<chrono>
#include<ctime>
#include<sstream>
#include"centralBankingSystem.h"
class ICICI
{
private:
    CentralSystem cs;
    std::int32_t cardNumber;
    std::int32_t cvv;
    std ::string expiryDate;
    std ::string cardHolderName;

public:
    void makePaymentViaUPI(std ::string upiId)
    {
        if (upiId.length() == 0)
        {
            std ::cout << "upiId is empty" << std::endl;
        }
        else
        {
            std ::cout << "Payment via ICICI bank" << std::endl;
            cs.makePaymentViaUPI(upiId);
        }
    }
    void makePaymentViaCreditCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (checkForValidity(cardNumber, expiryDate, cardHolderName, cvv))
        {
            std ::cout << "Payment via ICICI bank" << std::endl;
            cs.makePaymentViaCreditCard();
        }
    }

    void makePaymentViaDebitCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (checkForValidity(cardNumber, expiryDate, cardHolderName, cvv))
        {
            std ::cout << "Payment via ICICI bank" << std::endl;
            cs.makePaymentViaDebitCard();
        }
    }
    void makePaymentViaNetBanking(std::string userName, std::string password)
    {
        if (checkForUsernameAndPassword(userName, password))
        {
            std ::cout << "Payment via ICICI bank" << std::endl;
            cs.makePaymentViaNetBanking();
        }
    }

    bool checkForUsernameAndPassword(std ::string userName, std::string password)
    {
        if (userName.length() == 0 || password.length() == 0)
            return false;
        else
            return true;
    }

    bool checkForValidity(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (cardHolderName.length() == 0 || std::to_string(cvv).size() < 3 || std::to_string(cardNumber).length() != 12 || expiryDate >= returnCurrentDate())
        {
            std ::cout << "Invalid card Details" << std::endl;
            return false;
        }

        else
            return true;
    }

    std ::string returnCurrentDate()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::ctime(&currentTime);
        return ss.str();
    }
};
//main.cpp

 #include<iostream>
#include"client.h"
#include"payment.h"
#include"common.h"
#include"bank.h"
#include<string>

int main()
{
    Client client;
    client.addClient("shubham");
    client.hasClient("bam");
    client.removeClient("bam");

    Payment pay;
    pay.listSupportedPaymodes();
    pay.addSupportForPaymode("CARD");
    pay.addSupportForPaymode("UPI");
    pay.addSupportForPaymode("NET_BANKING");
    pay.listSupportedPaymodes();
    pay.listSupportedPaymodes("shubham");
    pay.addSupportForPaymode("CARD", "shubham");
    pay.addSupportForPaymode("UPI", "shubham");
    pay.listSupportedPaymodes("shubham");
    pay.removePaymode("NET_BANKING", "shubham");
    pay.removePaymode("CARD", "shubham");
    pay.listSupportedPaymodes("shubham");

    Bank bank;
    bank.addBank("HDFC");
    bank.addBank("SBI");
    // bank.addBank("ICICI");
    bank.addBank("ICICI", {"UPI", "NET_BANKING"});

    client.choosePayments("shubham", "UPI");
    client.choosePayments("shubham", "CcARD");
    client.choosePayments("shubham", "NET_BANKING");

    return 0;
}
//payment.h

#pragma once
#include<iostream>
#include<unordered_set>
#include<string>
#include<unordered_map>
#include<iterator>

const std ::string RANDOM_VAL = "RANDOM";

class Payment
{
private:
    std ::unordered_set<std::string> payment_modes_list;
    std::unordered_map<std::string, std::unordered_set<std::string>> client_payment_list;

public:
    void listSupportedPaymodes(std ::string name = RANDOM_VAL)
    {
        if (payment_modes_list.size() == 0)
        {
            std ::cout << "No payment modes available" << std ::endl;
            return;
        }
        else if (name == RANDOM_VAL)
        {
            std::cout << "list of payment modes availbale are :  " << std::endl;
            for (auto p : payment_modes_list)
            {
                std ::cout << p << " " << std::endl;
            }
        }
        else
        {
            if (client_payment_list.size() == 0)
            {
                std ::cout << "No payment modes available for the client " << name << std ::endl;
                return;
            }
            std::cout << "payment mode availbale for the client = " << name << std::endl;
            for (auto p : client_payment_list[name])
            {
                std ::cout << p << " " << std::endl;
            }
        }
    }
    std ::unordered_set<std::string> getSupportedPaymodes()
    {
        return payment_modes_list;
    }

    // std::vector<std ::string> getSupportedPaymentModesForClient(std ::string clientName)
    // {
    //     std ::vector<std::string> supportedMode;

    //     for (auto p : client_payment_list[clientName])
    //     {
    //         supportedMode.push_back(p);
    //     }
    //     return supportedMode;
    // }

    void addSupportForPaymode(std::string mode, std::string name = RANDOM_VAL)
    {
        if (name != RANDOM_VAL)
        {
            if (!checkIfPaymentModeExistedForTheClient(name, mode))
            {
                client_payment_list[name].insert(mode);
                std::cout << "payment mode " << mode << " for the client " << name << " added !!" << std::endl;
            }
            else
            {
                std::cout << "payment mode " << mode << " for the client " << name << " already exists !!" << std::endl;
            }
        }
        else
        {
            if (payment_modes_list.find(mode) == payment_modes_list.end())
            {
                payment_modes_list.insert(mode);
                std ::cout << "payment mode " << mode << "added !!!" << std::endl;
            }
        }
    }
    bool checkIfPaymentModeExistedForTheClient(std::string name, std::string mode)
    {
        for (auto t : client_payment_list[name])
        {
            if (mode == t)
                return true;
        }
        return false;
    }
    void removePaymode(std::string mode, std::string name = RANDOM_VAL)
    {

        if (name != RANDOM_VAL)
        {
            if (checkIfPaymentModeExistedForTheClient(name, mode))
            {
                client_payment_list[name].erase(mode);
                std ::cout << "payment mode " << mode << " removed from the client " << name << std::endl;
            }
            else
            {
                std::cout << "payment mode " << mode << " for the client " << name << " doesn't exist !!" << std::endl;
            }
        }
        else
        {
            if (payment_modes_list.find(mode) != payment_modes_list.end())
            {
                payment_modes_list.erase(mode);
                std ::cout << "payment mode " << mode << " removed !!!" << std::endl;
            }
            else
            {
                std ::cout << "cannot find payment mode " << mode << std::endl;
            }
        }
    }
};
//router.h

#include<iostream>
#include"hdfc.h"
#include"icici.h"
#include"sbi.h"
#pragma once

class Router
{
private:
    HDFC h;
    ICICI ic;
    SBI sbi;

public:
    void routeForCreditCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        std::cout << "route for credit card to HDFC bank" << std::endl;
        h.makePaymentViaCreditCard(cardNumber, expiryDate, cardHolderName, cvv);
    }
    void routeForDebitCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        std::cout << "route for Debit card to HDFC bank" << std::endl;
        h.makePaymentViaDebitCard(cardNumber, expiryDate, cardHolderName, cvv);
    }
    void routeForNetBanking(std::string userName, std::string password)
    {
        std::cout << "route for NET banking to ICICI bank" << std::endl;
        ic.makePaymentViaNetBanking(userName, password);
    }
    void routeForUPI(std ::string upiID)
    {
        std::cout << "route for UPI to SBI bank" << std::endl;
        sbi.makePaymentViaUPI(upiID);
    }
};
//sbi.h

#include<iostream>
#include<string>
#include<chrono>
#include<ctime>
#include<sstream>
#include"centralBankingSystem.h"
class SBI
{
private:
    CentralSystem cs;
    std::int32_t cardNumber;
    std::int32_t cvv;
    std ::string expiryDate;
    std ::string cardHolderName;

public:
    void makePaymentViaUPI(std ::string upiId)
    {
        if (upiId.length() == 0)
        {
            std ::cout << "upiId is empty" << std::endl;
        }
        else
        {
            std ::cout << "Payment via SBI bank" << std::endl;
            cs.makePaymentViaUPI(upiId);
        }
    }
    void makePaymentViaCreditCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (checkForValidity(cardNumber, expiryDate, cardHolderName, cvv))
        {
            std ::cout << "Payment via SBI bank" << std::endl;
            cs.makePaymentViaCreditCard();
        }
    }

    void makePaymentViaDebitCard(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (checkForValidity(cardNumber, expiryDate, cardHolderName, cvv))
        {
            std ::cout << "Payment via SBI bank" << std::endl;
            cs.makePaymentViaDebitCard();
        }
    }
    void makePaymentViaNetBanking(std::string userName, std::string password)
    {
        if (checkForUsernameAndPassword(userName, password))
        {
            std ::cout << "Payment via ICICI bank" << std::endl;
            cs.makePaymentViaNetBanking();
        }
    }

    bool checkForUsernameAndPassword(std ::string userName, std::string password)
    {
        if (userName.length() == 0 || password.length() == 0)
            return false;
        else
            return true;
    }

    bool checkForValidity(std::int32_t cardNumber, std::string expiryDate, std::string cardHolderName, std::int32_t cvv)
    {
        if (cardHolderName.length() == 0 || std::to_string(cvv).size() < 3 || std::to_string(cardNumber).length() != 12 || expiryDate >= returnCurrentDate())
        {
            std ::cout << "Invalid card Details" << std::endl;
            return false;
        }

        else
            return true;
    }

    std ::string returnCurrentDate()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::ctime(&currentTime);
        return ss.str();
    }
};
//upi.h

#include"centralBankingSystem.h"
class UPI
{
private:
    CentralSystem centeralBankingSystem;

public:
    void makePayment(std ::string upiId)
    {
        std ::cout << "payment Processing Via UPI" << std::endl;
        if (centeralBankingSystem.makePaymentViaUPI(upiId))
        {
            std ::cout << "Payment Successful" << std::endl;
        }
        else
        {
            std ::cout << "Payment Failed" << std::endl;
        }
    }
};