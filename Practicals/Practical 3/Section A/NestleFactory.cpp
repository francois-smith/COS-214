//
// Created by Francois Smith on 2022/08/24.
//

#include "NestleFactory.h"

Chocolate* NestleFactory::createChocolate(bool bar) {
    return new MilkyBar(bar);
}

AeratedChocolate* NestleFactory::createAeratedChocolate(int density) {
    return new Areo(density);
}
