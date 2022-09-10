/*
 * Directory.cpp
 *
 *  Created on: 02 Sep 2022
 *      Author: Francois Smith
 */

#include "Directory.h"

Directory::Directory(std::string name) : Node(std::move(name))
{
    this->nodes = std::vector<Node*>();
}

Directory::~Directory() {
    for(auto node : this->nodes)
    {
        delete node;
    }
}

void Directory::printName()
{
    std::cout << this->getName() << "/" << std::endl;
    for (Node* node : nodes) {
        std::cout << "   ";
        node->printName();
    }
}

void Directory::addNode(Node* newNode)
{
    this->nodes.push_back(newNode);
}

bool Directory::removeNode(Node* node)
{
    return false;
}

Node* Directory::clone()
{
    Directory* newDirectory = new Directory(this->getName());
    for (Node* node : this->nodes)
    {
        newDirectory->addNode(node->clone());
    }
    return newDirectory;
}