#include "Directory.h"
#include "File.h"
#include "NodeIterator.h"
#include "Root.h"
#include "SnapshotStore.h"
#include "FileObserver.h"
#include "DirectoryObserver.h"
#include <stack>

std::stack<Directory*> directoryTree;
Root* root;
SnapshotStore* snapshotStore;
NodeIterator* directoryIterator;
NodeIterator* fileIterator;

/**
 * @brief This function is called when the user uses the ./ terminal input. \n
 * @brief Opens the file with the corresponding name and shows contents.
 * @param fileName - File to open.
 */
void OpenFile(std::string& fileName)
{
    bool found = false;
    fileIterator->first();

    while(fileIterator->hasNext())
    {
        if (fileIterator->current()->getName() == fileName)
        {
            std::cout << "\t" "Running " << fileName  << ":" << std::endl << std::endl;
            std::cout << "\t" << dynamic_cast<File*>(fileIterator->current())->getContent() << std::endl;
            found = true;
            break;
        }

        fileIterator->next();
    }

    if (!found) std::cout << "\u001b[38;5;1m" << "\t" << "File not found" << "\u001b[38;5;255m" << std::endl;
}

/**
 * @brief This function is called when the user uses the rm terminal input. \n
 * @brief Removes the file with the corresponding name.
 * @param fileName - File to be removed.
 */
void DeleteFile(std::string& fileName)
{
    bool found = false;
    fileIterator->first();

    while(fileIterator->hasNext())
    {
        if (fileIterator->current()->getName() == fileName)
        {
            std::cout << "\t" << "Removed " << fileIterator->current()->getName() << std::endl;
            directoryTree.top()->removeFile(dynamic_cast<File *>(fileIterator->current()));
            found = true;
            delete fileIterator;
            fileIterator = directoryTree.top()->createFileIterator();
            break;
        }
        fileIterator->next();
    }
    if (!found) std::cout << "\u001b[38;5;1m" << "\t" << "File not found" << "\u001b[38;5;255m" << std::endl;
}

/**
 * @brief This function is called when the user uses the mkdir terminal input. \n
 * @brief Creates a new directory with corresponding input name.
 */
void CreateDirectory(std::string& directoryName, bool observer)
{
    //Create a new directory with the given name.
    Directory* newDirectory = new Directory(directoryName);
    directoryTree.top()->addDirectory(newDirectory);

    if (observer)
    {
        std::cout << "\t" << "DirectoryObserver: for " << newDirectory->getName() << " created" << std::endl;
        new DirectoryObserver(newDirectory);
    }

    //Re-Instantiating iterator
    delete directoryIterator;
    directoryIterator = directoryTree.top()->createDirectoryIterator();
}

/**
 * @brief This function is called when the user uses the rmdir terminal input. \n
 * @brief Removes the directory with the corresponding name.
 * @param directoryName - Directory to be removed.
 */
void DeleteDirectory(std::string& directoryName)
{
    bool found = false;
    directoryIterator->first();

    while(directoryIterator->hasNext())
    {
        if (directoryIterator->current()->getName() == directoryName)
        {
            directoryTree.top()->removeDirectory(dynamic_cast<Directory *>(directoryIterator->current()));
            found = true;
            delete directoryIterator;
            directoryIterator = directoryTree.top()->createDirectoryIterator();
            break;
        }

        directoryIterator->next();
    }

    if (!found) std::cout << "\u001b[38;5;1m" << "\t" << "Directory not found" << "\u001b[38;5;255m" << std::endl;
}

/**
 * @brief This function is called when the user uses the touch terminal input. \n
 * @brief Creates a new file with corresponding input name. Also ask user input as a string to be written to the file.
 * @param fileName
 */
void CreateFile(std::string& fileName, bool observer)
{
    //Asks for more input to be written to the file.
    std::string input;
    std::cout << "\t" << "Enter file content: ";
    getline(std::cin, input);

    //Creates a new file with the input name and content.
    File* file = new File(fileName, input);
    directoryTree.top()->addFile(file);

    //If observer is true, attach a new observer to the file.
    if (observer)
    {
        std::cout << "\t" << "FileObserver: for " << file->getName() << " created" << std::endl;
        new FileObserver(file);
    }

    //Update the file iterator.
    delete fileIterator;
    fileIterator = directoryTree.top()->createFileIterator();
}

/**
 * @brief This function is called when the user uses the ls terminal input. \n
 * @brief Lists all files and directories in the current directory.
 * @return If Any Files or Directories are found.
 */
bool ListContents()
{
    bool found = false;

    directoryIterator->first();
    while(directoryIterator->hasNext())
    {
        found = true;
        std::cout << "\t"; directoryIterator->current()->printName();
        directoryIterator->next();
    }

    fileIterator->first();
    while(fileIterator->hasNext())
    {
        found = true;
        std::cout << "\t"; fileIterator->current()->printName();
        fileIterator->next();
    }

    return found;
}

/**
 * @brief This function is called wh
            std::string file = input.substr(input.find(' '));en the user uses the mv terminal input. \n
 * @brief Renames the object with the corresponding name.
 * @param oldName - Old name of the item.
 * @param newName - New name of the item.
 */
void Rename(std::string& oldName, std::string& newName)
{
    if(oldName.find('.') != std::string::npos && newName.find('.') != std::string::npos)
    {
        fileIterator->first();
        while(fileIterator->hasNext())
        {
            std::cout << oldName << std::endl;
            if (fileIterator->current()->getName() == oldName)
            {
                if(root->activeAntivirus() && newName.find("virus") != std::string::npos)
                {
                    std::cout << "\t" << "\u001b[38;5;1m" << "Virus detected, removed file" << "\u001b[38;5;255m" << std::endl;
                    directoryTree.top()->removeFile(dynamic_cast<File*>(fileIterator->current()));
                    delete fileIterator;
                    fileIterator = directoryTree.top()->createFileIterator();
                    return;
                }

                std::cout << "\t" << "Renamed " << fileIterator->current()->getName() << " to " << newName << std::endl;
                fileIterator->current()->rename(newName);
                fileIterator->current()->notify();

                //clone the stack
                std::stack<Directory*> tempStack = directoryTree;
                while(!tempStack.empty())
                {
                    tempStack.top()->notify();
                    tempStack.pop();
                }
                return;
            }
            fileIterator->next();
        }

        std::cout << "\t" << "\u001b[38;5;1m" << "File not found" << "\u001b[38;5;255m" << std::endl;
    }
    else if (oldName.find('.') == std::string::npos && newName.find('.') == std::string::npos)
    {
        directoryIterator->first();
        while(directoryIterator->hasNext())
        {
            if (directoryIterator->current()->getName() == oldName)
            {
                std::cout << "\t" << "Renamed " << directoryIterator->current()->getName() << " to " << newName << std::endl;
                directoryIterator->current()->rename(newName);
                directoryIterator->current()->notify();

                //clone the stack
                std::stack<Directory*> tempStack = directoryTree;
                while(!tempStack.empty())
                {
                    tempStack.top()->notify();
                    tempStack.pop();
                }

                return;
            }
            directoryIterator->next();
        }

        std::cout << "\t" << "\u001b[38;5;1m" << "Directory not found" << "\u001b[38;5;255m" << std::endl;
    }
    else{
        std::cout << "\t" << "\u001b[38;5;1m" << "Both inputs must be files or directories" << "\u001b[38;5;255m" << std::endl;
    }
}

/**
 * @brief This function is called when the user uses the ob terminal input. \n
 * @brief Attaches an observer to the object with the corresponding name.
 * @param fileName - Name of the file to attach the observer to.
 */
void AddFileObserver(std::string& fileName)
{
    fileIterator->first();
    while(fileIterator->hasNext())
    {
        if (fileIterator->current()->getName() == fileName)
        {
            std::cout << "\t" << "FileObserver: for " << fileIterator->current()->getName() << " created" << std::endl;
            new FileObserver(dynamic_cast<File*>(fileIterator->current()));
            return;
        }
        fileIterator->next();
    }
    std::cout << "\t" << "\u001b[38;5;1m" << "No file with given name" << "\u001b[38;5;255m" << std::endl;
}

/**
 * @brief This function is called when the user uses the ob terminal input. \n
 * @brief Attaches an observer to the object with the corresponding name.
 * @param directoryName - Name of the directory to attach the observer to.
 */
void AddDirectoryObserver(std::string& directoryName)
{
    directoryIterator->first();
    while(directoryIterator->hasNext())
    {
        if (directoryIterator->current()->getName() == directoryName)
        {
            std::cout << "\t" << "DirectoryObserver: for " << directoryIterator->current()->getName() << " created" << std::endl;
            new DirectoryObserver(dynamic_cast<Directory*>(directoryIterator->current()));
            return;
        }
        directoryIterator->next();
    }
    std::cout << "\t" << "\u001b[38;5;1m" << "No directory with given name" << "\u001b[38;5;255m" << std::endl;
}

/**
 * @brief This function is called when the user uses the set terminal input. \n
 * @param fileName - File to be edited.
 * @param newContent - New content to be written to the file.
 */
void UpdateContent(std::string& fileName)
{
    bool found = false;
    fileIterator->first();

    while(fileIterator->hasNext())
    {
        if (fileIterator->current()->getName() == fileName)
        {
            //ask for new content
            std::cout << "\t" << "Enter new file content: ";
            std::string content;
            getline(std::cin, content);

            if(root->activeAntivirus() && content.find("virus") != std::string::npos)
            {
                std::cout << "\t" << "\u001b[38;5;1m" << "Virus detected, removed file" << "\u001b[38;5;255m" << std::endl;
                directoryTree.top()->removeFile(dynamic_cast<File*>(fileIterator->current()));
                delete fileIterator;
                fileIterator = directoryTree.top()->createFileIterator();
                return;
            }

            File* file = dynamic_cast<File*>(fileIterator->current());
            file->setContent(content);
            file->notify();

            //clone the stack
            std::stack<Directory*> tempStack = directoryTree;
            while(!tempStack.empty())
            {
                tempStack.top()->notify();
                tempStack.pop();
            }

            found = true;
            break;
        }

        fileIterator->next();
    }

    if (!found) std::cout << "\u001b[38;5;1m" << "\t" << "File not found" << "\u001b[38;5;255m" << std::endl;
}

/**
 * @brief This function is called when the user uses the cd / terminal input. \n
 * @brief Moves back to the root directory and resets iterators.
 */
void MoveToRoot()
{
    delete directoryIterator;
    delete fileIterator;
    //clear stack
    while(!directoryTree.empty())
    {
        directoryTree.pop();
    }
    directoryTree.push(root->getRoot());
    directoryIterator = root->getRoot()->createDirectoryIterator();
    fileIterator = root->getRoot()->createFileIterator();
}

/**
 * @brief This function is called when the user uses the cd .. terminal input. \n
 * @brief Moves back to the parent directory and resets iterators.
 */
void MoveUpOne()
{
    delete directoryIterator;
    delete fileIterator;
    directoryTree.pop();
    Directory* temp = directoryTree.top();
    directoryIterator = temp->createDirectoryIterator();
    fileIterator = temp->createFileIterator();
}

/**
 * @brief This function is called when the user uses the cd terminal input. \n
 * @brief Moves to the directory with the corresponding name.
 * @param newDir - Directory to move to.
 * @return - If the directory was found.
 */
bool MoveToDirectory(std::string& newDir)
{
    bool found = false;
    directoryIterator->first();

    while(directoryIterator->hasNext())
    {
        if (directoryIterator->current()->getName() == newDir)
        {
            //Update current path

            directoryTree.push(dynamic_cast<Directory*>(directoryIterator->current()));

            //Update directory iterator
            NodeIterator* temp = directoryIterator;
            directoryIterator = dynamic_cast<Directory*>(directoryIterator->current())->createDirectoryIterator();

            //Update file iterator
            delete fileIterator;
            fileIterator = dynamic_cast<Directory*>(temp->current())->createFileIterator();

            delete temp;
            found = true;
            break;
        }

        directoryIterator->next();
    }

    return found;
}

int main()
{
    //Helper variables
    bool exit = false;
    std::string input;
    std::string path = "francois@pop-os:~/";
    std::string currentPath = "root";

    //Initialize Default Variables
    snapshotStore = new SnapshotStore();
    Directory* rootDir = new Directory("root");
    new DirectoryObserver(rootDir);
    root = new Root(rootDir);
    directoryTree.push(rootDir);

    //Create First Directory with Subdirectory
    Directory* users = new Directory("users");
    users->addDirectory(new Directory("francois"));
    new DirectoryObserver(users);
    root->getRoot()->addDirectory(users);

    //Create First File and Empty Directory
    root->getRoot()->addDirectory(new Directory("desktop"));
    File* baseFile = new File("test.txt", "hello world");
    new FileObserver(baseFile);
    root->getRoot()->addFile(baseFile);

    directoryIterator = root->getRoot()->createDirectoryIterator();
    fileIterator = root->getRoot()->createFileIterator();

    //Main Loop - Continues until user exits
    while(!exit)
    {
        //Ask for user terminal input
        std::cout << "\u001b[38;5;106m" << path << "\u001b[38;5;32m" << currentPath << "\u001b[38;5;255m" << "$ ";
        getline(std::cin, input);

        if (input.substr(0, input.find(' ')) == "cd")
        {
            std::string dir = input.substr(input.find(' ') + 1);

            if (dir == "/")
            {
                if (currentPath != "root")
                {
                    currentPath = "root";
                    MoveToRoot();
                }
            }
            else if(dir == "..")
            {
                currentPath = currentPath.substr(0, currentPath.find_last_of('/'));
                if(currentPath != "root")
                {
                    MoveUpOne();
                }
                else{
                    MoveToRoot();
                }
            }
            else
            {
                if (MoveToDirectory(dir))
                {
                    currentPath += "/" + dir;
                }
                else{
                    std::cout  << "\u001b[38;5;1m" << "\t" << "Directory not found" << "\u001b[38;5;255m" << std::endl;
                }
            }
        }
        else if (input.substr(0, input.find('/')+1) == "./")
        {
            std::string file = input.substr(input.find('/') + 1);
            OpenFile(file);
        }
        else if (input.substr(0, input.find(' ')) == "rm")
        {
            std::string file = input.substr(input.find(' ') + 1);
            DeleteFile(file);
        }
        //sudo apt install antivirus
        else if(input.substr(0, input.find(' ')) == "sudo")
        {
            std::string command = input.substr(input.find(' ') + 1);
            if(command.substr(0, command.find(' ')) == "apt")
            {
                std::string aptCommand = command.substr(command.find(' ') + 1);
                if(aptCommand.substr(0, aptCommand.find(' ')) == "install")
                {
                    std::string antivirus = aptCommand.substr(aptCommand.find(' ') + 1);
                    if(antivirus == "antivirus")
                    {
                        std::cout << "\u001b[38;5;4m" << "\t" << "Antivirus installed" << "\u001b[38;5;255m" << std::endl;
                        root->installAntivirus(new Antivirus());
                    }
                    else{
                        std::cout << "\u001b[38;5;1m" << "\t" << "Program not found" << "\u001b[38;5;255m" << std::endl;
                    }
                }
            }
        }
        else if (input.substr(0, input.find(' ')) == "mkdir")
        {
            std::string dir = input.substr(input.find(' ') + 1);
            if (dir.substr(0, dir.find(' ')) == "-o")
            {
                dir = dir.substr(dir.find(' ') + 1);
                CreateDirectory(dir, true);
            }
            else{
                CreateDirectory(dir, false);
            }
        }
        else if (input.substr(0, input.find(' ')) == "rmdir")
        {
            std::string dir = input.substr(input.find(' ') + 1);
            DeleteDirectory(dir);
        }
        else if (input.substr(0, input.find(' ')) == "mk")
        {
            std::string file = input.substr(input.find(' ') + 1);

            if (file.find('.') != std::string::npos)
            {
                if (input.find("-o") != std::string::npos)
                {
                    file = file.substr(file.find(' ') + 1);
                    CreateFile(file, true);
                }
                else{
                    CreateFile(file, false);
                }
            }
            else{
                std::cout << "\u001b[38;5;1m" << "\t" << "File must have a valid extension" << "\u001b[38;5;255m" << std::endl;
            }
        }
        else if (input == "ls")
        {
            if(!ListContents()) std::cout << "\t" << "Directory is empty" << std::endl;
        }
        else if (input.substr(0, input.find(' ')) == "ob")
        {
            std::string file = input.substr(input.find(' ') + 1);
            if (file.find('.') != std::string::npos)
            {
                AddFileObserver(file);
            }
            else
            {
                AddDirectoryObserver(file);
            }
        }
        //check that both inputs are files or folders
        else if (input.substr(0, input.find(' ')) == "mv")
        {
            //first input
            std::string file = input.substr(input.find(' ') + 1, input.find(' ', input.find(' ') + 1) - input.find(' ') - 1);
            std::string newFile = input.substr(input.find_last_of(' ') + 1);
            Rename(file, newFile);
        }
        else if (input.substr(0, input.find(' ')) == "update")
        {
            std::string file = input.substr(input.find(' ') + 1, input.find(' ', input.find(' ') + 1) - input.find(' ') - 1);
            UpdateContent(file);
        }
        else if (input.substr(0, input.find(' ')) == "ss")
        {
            std::string ss = input.substr(input.find(' ') + 1);
            bool found = false;

            if (ss == "store")
            {
                found = true;
                snapshotStore->storeSnapshot(root->createSnapshot());
            }
            else if (ss == "restore")
            {
                found = true;
                root->restoreSnapshot(snapshotStore->getSnapshot());
                MoveToRoot();
                currentPath = "root";
            }
            else if(ss == "clear")
            {
                found = true;
                Root::clearSnapshots(snapshotStore);
            }

            if (!found) std::cout << "\u001b[38;5;1m" << "\t" << "Invalid Snapshot Command" << "\u001b[38;5;255m" << std::endl;
        }
        else if (input == "exit")
        {
            exit = true;
        }
        else
        {
            std::cout << "\u001b[38;5;1m" << "\t" << "Invalid command" << "\u001b[38;5;255m" << std::endl;
        }
    }

    delete snapshotStore;
    delete directoryIterator;
    delete fileIterator;
    delete root;
    return 0;
}
