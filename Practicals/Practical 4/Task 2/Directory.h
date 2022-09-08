/*
 * Directory.h
 *
 *  Created on: 02 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Node.h"
#include <string>
#include <vector>

class Directory: public Node
{
public:
    explicit Directory(std::string name);
    ~Directory() override;
    void printName() override;
    void addNode(Node* newNode) override;
    bool removeNode(Node* node) override;

private:
    std::vector<Node*> nodes;
};

