#pragma once

#include <string>
#include <iostream>
#include "AuditableSnapshot.h"
#include "Snapshot.h"

class User
{
private:
    std::string _username;
    std::string _password;
    static std::string GenerateRandomString(int length = 10);

public:
    User(std::string username, std::string password);
    void SetPassword(const std::string& newPassword);
    AuditableSnapshot *Save();
    void Restore(AuditableSnapshot *memento);
};
