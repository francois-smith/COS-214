/*
 * Directory.h
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Node.h"
#include "File.h"
#include "DirectoryIterator.h"
#include "FileIterator.h"
#include <string>
#include <vector>

class Directory: public Node
{
public:
    explicit Directory(std::string name);
    ~Directory() override;
    void printName() override;
    void addDirectory(Directory* newDirectory);
    void removeDirectory(Directory* directory);
    bool listDirectories();
    bool isEmpty();
    void addFile(File* newFile);
    void removeFile(File* file);
    bool listFiles();
    DirectoryIterator* createDirectoryIterator();
    FileIterator* createFileIterator();

private:
    std::vector<File*> files;
    std::vector<Directory*> directories;
};

