#include "User.h"

User::User(std::string username, std::string password) : _username(username), _password(password)
{
    std::cout << "User: I have been initialized with username " << this->_username << " and a password of " << this->_password << "\n";
}

std::string User::GenerateRandomString(int length)
{
    const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;

    std::string random_string;
    for (int i = 0; i < length; i++)
    {
        random_string += alphanum[std::rand() % stringLength];
    }
    return random_string;
}

void User::SetPassword(const std::string& newPassword)
{
    std::cout << "User: Setting a new secure password.\n";
    this->_password = newPassword;
    std::cout << "User: My password has been changed to: " << this->_password << "\n";
}

AuditableSnapshot* User::Save()
{
    return new Snapshot(this->_password);
}

void User::Restore(AuditableSnapshot* memento)
{
    this->_password = memento->state();
    std::cout << "User: My password has changed to: " << this->_password << "\n";
}
