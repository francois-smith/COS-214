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
class File: public Node
{
public:
    File(std::string name, std::string content) : Node(std::move(name)), content(std::move(content)) {};
    ~File() override = default;
    std::string getContent() const;
    void setContent(std::string newContent);
    void printName() override;
    void addNode(Node* newNode) override { delete newNode; };
    bool removeNode(Node* node) override{ return false; };
    Node* clone() override;

private:
    std::string content;
};

