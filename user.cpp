#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
private:

    string name;
    string email;
    string phone;

public:
    
    User(); 
    User(string name, string email, string phone); // Parameterized

    
    string getName() const;
    void setName(const string &name);

    string getEmail() const;
    void setEmail(const string &email);

    string getPhone() const;
    void setPhone(const string &phone);
};

#endif