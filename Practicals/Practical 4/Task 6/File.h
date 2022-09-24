/*
 * Directory.h
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Node.h"

/**
 * @brief Directory class is a leaf node in the file system. \n
 * Implements the composite  design pattern.
 */
class File: public Node
{
public:
    File(std::string name, std::string content) : Node(std::move(name)), content(std::move(content)) {};
    ~File() override = default;
    void printName() override;
    Node* clone() override;

    //Getters and Setters
    std::string getContent() const;
    void setContent(std::string newContent);

private:
    std::string content;
};

