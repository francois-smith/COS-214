#include "Directory.h"
#include "File.h"
#include "NodeIterator.h"
#include "Root.h"
#include "SnapshotStore.h"
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
            std::cout << "\t" "Running " << fileName << ".file" << std::endl;
            std::cout << "\t" << dynamic_cast<File*>(fileIterator->current())->getContent() << std::endl;
            found = true;
            break;
        }

        fileIterator->next();
    }

    if (!found) std::cout << "File not found" << std::endl;
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
    if (!found) std::cout << "File not found" << std::endl;
}

/**
 * @brief This function is called when the user uses the mkdir terminal input. \n
 * @brief Creates a new directory with corresponding input name.
 */
void MakeDirectory(std::string& directoryName)
{
    delete directoryIterator;
    directoryTree.top()->addDirectory(new Directory(directoryName));
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

    if (!found) std::cout << "Directory not found" << std::endl;
}

/**
 * @brief This function is called when the user uses the touch terminal input. \n
 * @brief Creates a new file with corresponding input name. Also ask user input as a string to be written to the file.
 * @param fileName
 */
void MakeFile(std::string& fileName)
{
    std::string input;
    std::cout << "Enter file content: ";
    getline(std::cin, input);
    directoryTree.top()->addFile(new File(fileName, input));
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
        std::cout << "\t";fileIterator->current()->printName();
        fileIterator->next();
    }

    return found;
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
        {;
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
    root = new Root(rootDir);
    directoryTree.push(rootDir);

    //Create First Directory with Subdirectory
    Directory* users = new Directory("users");
    users->addDirectory(new Directory("francois"));
    root->getRoot()->addDirectory(users);

    //Create First File and Empty Directory
    root->getRoot()->addDirectory(new Directory("desktop"));
    root->getRoot()->addFile(new File("root", "hello world"));

    directoryIterator = root->getRoot()->createDirectoryIterator();
    fileIterator = root->getRoot()->createFileIterator();

    //Main Loop - Continues until user exits
    while(!exit)
    {
        //Ask for user terminal input
        std::cout << path << currentPath << "$ ";
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
                    std::cout << "Directory not found" << std::endl;
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
        else if (input.substr(0, input.find(' ')) == "mkdir")
        {
            std::string dir = input.substr(input.find(' ') + 1);
            MakeDirectory(dir);
        }
        else if (input.substr(0, input.find(' ')) == "rmdir")
        {
            std::string dir = input.substr(input.find(' ') + 1);
            DeleteDirectory(dir);
        }
        else if (input.substr(0, input.find(' ')) == "touch")
        {
            std::string file = input.substr(input.find(' ') + 1);
            MakeFile(file);
        }
        else if (input == "ls")
        {
            if(!ListContents()) std::cout << "\t" << "Directory is empty" << std::endl;
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

            if (!found) std::cout << "Invalid Snapshot Command" << std::endl;
        }
        else if (input == "exit")
        {
            exit = true;
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }
    }

    delete snapshotStore;
    delete directoryIterator;
    delete fileIterator;
    delete root;
    return 0;
}
