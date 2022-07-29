#pragma once

#include <iostream>
#include <list>
#include "User.h"
#include "AuditableSnapshot.h"

class UserManager
{
private:
    User* User_;
    std::list<AuditableSnapshot*> Memento_;

public:
    explicit UserManager(User *User);
    void Backup();
    void Undo();
    void ShowHistory() const;
};