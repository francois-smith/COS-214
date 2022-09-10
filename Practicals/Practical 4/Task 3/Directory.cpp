/*
 * Directory.cpp
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#include "Directory.h"

Directory::Directory(std::string name) : Node(std::move(name))
{
    this->files = std::vector<File*>();
    this->directories = std::vector<Directory*>();
}

Directory::~Directory() {
    for(auto file : this->files)
    {
        delete file;
    }

    for(auto directory : this->directories)
    {
        delete directory;
    }
}

void Directory::printName()
{
    std::cout << this->getName() << "/" << std::endl;
}

void Directory::addDirectory(Directory *newDirectory)
{
    this->directories.push_back(newDirectory);
}

void Directory::removeDirectory(Directory* directory)
{
    int index = 0;
    for(Directory* myDirectory : this->directories)
    {
        if(myDirectory == directory)
        {
            delete myDirectory;
            this->directories.erase(this->directories.begin() + index);
            break;
        }
        index++;
    }
}

bool Directory::listDirectories()
{
    if(this->directories.empty())
    {
        return false;
    }
    else
    {
        for(auto directory : this->directories)
        {
            directory->printName();
        }
        return true;
    }
}

bool Directory::isEmpty()
{
    if(this->files.empty() && this->directories.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Directory::addFile(File *newFile)
{
    this->files.push_back(newFile);
}

void Directory::removeFile(File* file)
{
    int index = 0;
    for(File* myFile : this->files)
    {
        if(myFile == file)
        {
            delete myFile;
            this->files.erase(this->files.begin() + index);
            break;
        }
        index++;
    }
}

bool Directory::listFiles()
{
    if(this->files.empty())
    {
        return false;
    }
    else
    {
        for(auto file : this->files)
        {
            file->printName();
        }
        return true;
    }
}

DirectoryIterator *Directory::createDirectoryIterator()
{
    return new DirectoryIterator(this->directories);
}

FileIterator *Directory::createFileIterator()
{
    return new FileIterator(this->files);
}
