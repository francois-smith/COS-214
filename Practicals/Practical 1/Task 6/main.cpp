#include <ctime>
#include "User.h"
#include "UserManager.h"

void Run() {
    User *user = new User("username", "mysecretpassword");
    UserManager *userManager = new UserManager(user);
    userManager->Backup();
    user->SetPassword("pa$$w0rd");
    userManager->Backup();
    user->SetPassword("5t@rw@r5");
    userManager->Backup();
    user->SetPassword("bigB@ng");
    std::cout << "\n";
    userManager->ShowHistory();
    std::cout << "\nClient: Now, let's rollback!\n\n";
    userManager->Undo();
    std::cout << "\nClient: Once more!\n\n";
    userManager->Undo();

    delete user;
    delete userManager;
}

int main() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    Run();
    return 0;
}

