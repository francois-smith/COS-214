/*
 * Node.h
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include <exception>
#include <string>
#include <iostream>

class Directory;
class File;

/**
 * @brief Node class is the base class for all nodes in the file system. \n
 * Implements the composite and iterator design patterns.
 */
class Node
{
public:
    explicit Node(std::string aName) : name(std::move(aName)) {};
    virtual ~Node() = default;
    virtual void addDirectory(Directory* newDirectory) = 0;
    virtual bool removeDirectory() = 0;
    virtual bool isEmpty() = 0;
    virtual void addFile(File* newFile) = 0;
    virtual bool removeFile() = 0;
    virtual bool listFiles() = 0;

    //Getters and Setters
    std::string getName() const;
    void setName(std::string aName);

private:
    std::string name;
};