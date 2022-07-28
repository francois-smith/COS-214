#include "User.h"

User::User(const std::string &username, const std::string &password) : _username(username), _password(password) {
    std::cout << "User: I have been initialized with username " << this->_username << " and a password of " << this->_password << "\n";
}


User::User(std::string username, std::string password) : _username(username), _password(password){

}