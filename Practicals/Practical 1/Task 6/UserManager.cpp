#include "UserManager.h"

UserManager::UserManager(User *User) : User_(User)
{
    this->User_ = User;
}

void UserManager::Backup()
{
    std::cout << "\nUserManager: Saving User's state...\n";
    this->Memento_.emplace_back(this->User_->Save());
}

void UserManager::Undo()
{
    if(this->Memento_.empty()){
        std::cout << "No previously saved password" << std::endl;
    }

    AuditableSnapshot* memento = this->Memento_.back();
    this->Memento_.pop_back();

    try {
        this->User_->Restore(memento);
    }
    catch (...){
        this->Undo();
    }
}

void UserManager::ShowHistory() const
{
    std::cout << "UserManager: Here's the list of historical changes:\n";
    for(AuditableSnapshot* memento: this->Memento_)
    {
        std::cout << memento->GetUsername() << std::endl;
    }
}
