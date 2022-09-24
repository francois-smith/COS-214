/*
 * Antivirus.cpp
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#include "Antivirus.h"

void Antivirus::notify(File* file)
{
    std::cout << "Bit-defender: " << file->getName() << " is infected!" << std::endl;
}