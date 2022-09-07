/*
 * Directory.h
 *
 *  Created on: 02 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Node.h"

/**
 * @brief Directory class is a leaf node in the file system. \n
 * Implements the composite  design pattern.
 */
class Directory: public Node
{
public:

    std::string getContent() const;
    void setContent(std::string newContent);
    ~Directory() override = default;

protected:
    Directory(std::string name, std::string content) : Node(std::move(name)), content(std::move(content)) {};

private:
    std::string content;

    friend class FileFactory;
};

