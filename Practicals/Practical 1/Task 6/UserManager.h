class UserManager {
public:
    UserManager(User *User) : User_(User) {;

    }

    void Backup() {
        std::cout << "\nUserManager: Saving User's state...\n";

    }

    void Undo() {

    }

    void ShowHistory() const {
        std::cout << "UserManager: Here's the list of historical changes:\n";

    }
};