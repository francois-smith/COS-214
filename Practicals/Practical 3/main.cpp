//Section A Imports
#include "Section A/Confectionery.h"
#include "Section A/ConfectioneryFactory.h"
#include "Section A/NestleFactory.h"
#include "Section A/CadburyFactory.h"
#include "Section A/LindtFactory.h"

//Section B Imports
#include "Section B/Pokemon.h"
#include "Section B/PlayStyle.h"
#include "Section B/PhysicalAttackPlayStyle.h"
#include "Section B/AttackPlayStyle.h"
#include "Section B/RunPlayStyle.h"

/**
 * @brief Generates a random number between min and max.
 * @param min - Min Value
 * @param max - Max Value
 * @return Random Number
 */
int generateRandomNumber(int min, int max)
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed1);
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

/**
 * @brief Generates a random new style for a pokemon
 * @return Random Style
 */
PlayStyle* generateRandomStyle()
{
    int randomNumber = generateRandomNumber(1, 3);
    switch(randomNumber)
    {
        default: case 1:
            return new PhysicalAttackPlayStyle();
        case 2:
            return new AttackPlayStyle();
        case 3:
            return new RunPlayStyle();
    }
}

/**
 * @brief Ask user for input and create a Confectionery object
 * @return - User input
 */
int userPrompt()
{
    while (true)
    {
        std::string userChoice;
        std::cout << "What would you like us to produce?" << std::endl;
        std::cout << "Cadbury:" << std::endl;
        std::cout << "  [1] DiaryMilk" << std::endl;
        std::cout << "  [2] DiaryMilk Bubbly" << std::endl;
        std::cout << "Nestle:" << std::endl;
        std::cout << "  [3] MilkyBar" << std::endl;
        std::cout << "  [4] Areo" << std::endl;
        std::cout << "Lindt:" << std::endl;
        std::cout << "  [5] Lindor" << std::endl;
        std::cout << "  [6] Aerated Lindor" << std::endl;
        std::cin >> userChoice;
        std::cout << std::endl;
        if (userChoice == "1" || userChoice == "2" || userChoice == "3" || userChoice == "4" || userChoice == "5")
        {
            return std::stoi(userChoice);
        }
        else if(userChoice == "6")
        {
            std::cout << "Sorry we do not produce those!" << std::endl;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

/**
 * @brief Ask user for input for density of aerated object
 * @return - Desired density
 */
int getDensity()
{
    while (true)
    {
        int userChoice;
        std::cout << std::endl;
        std::cout << "How bubbly should it be? (per cubic centimeter)" << std::endl;
        std::cin >> userChoice;
        std::cout << std::endl;
        if(!std::cin.fail())
        {
            return userChoice;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

/**
 * @brief Ask user if they want a slab or not
 * @return - If they want a slab
 */
bool isSlab()
{
    while (true)
    {
        std::string userChoice;
        std::cout << std::endl;
        std::cout << "Would you like the slab variant?" << std::endl;
        std::cout << "[1] Yes" << std::endl;
        std::cout << "[2] No" << std::endl;
        std::cin >> userChoice;
        std::cout << std::endl;
        if (userChoice == "1")
        {
            return true;
        }
        else if(userChoice == "2")
        {
            return false;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void sectionA()
{
    std::cout << "================ Task 2 ================" << std::endl;
    //Creating factories for different confectioneries and array to store them
    Confectionery** chocolates = new Confectionery*[5];
    ConfectioneryFactory* factories[3]{
            new NestleFactory(),
            new CadburyFactory(),
            new LindtFactory()
    };

    std::cout << "Welcome to the shop. ";
    //Asks user for 5 confectionaries to create
    for(int i = 0; i < 5; i++) {
        //Get Confectionary to create
        int choice = userPrompt();

        //Check if it should be aerated
        if(choice%2 == 0)
        {
            //Get desired density
            int density = getDensity();
            chocolates[i] = factories[choice%3-1]->createAeratedChocolate(density);
        }
        else
        {
            //Check if it should be a slab
            bool slab = isSlab();
            chocolates[i] = factories[choice%3]->createChocolate(slab);
        }

        //Print out the confectionary
        std::cout << "You have ordered " << std::endl << chocolates[i]->getDescription() << std::endl << std::endl;
    }

    //Print all confectionaries added in order
    std::cout << std::endl << "Your cart consists of:" << std::endl;
    for(int i = 0; i < 5; i++) {
        std::cout << chocolates[i]->getDescription() << std::endl;
    }
    std::cout << std::endl << "Tank you for shopping with us!" << std::endl;

    //Deallocate memory
    for(ConfectioneryFactory* factory : factories){
        delete factory;
    }
    for(int i = 0; i < 5; i++) {
        delete chocolates[i];
    }
    delete[] chocolates;
}

bool isAlive(Pokemon** array)
{
    return array[0]->isAlive() || array[1]->isAlive() || array[2]->isAlive();
}

void printStatus(Pokemon** array)
{
    for(int i = 0; i < 3; i++)
    {
        array[i]->print();
    }
}

int findNextAlive(Pokemon** array)
{
    for(int i = 0; i < 3; i++)
    {
        if(array[i]->isAlive())
        {
            return i;
        }
    }
    return -1;
}

int main() {
    //sectionA();
    std::cout << "=================== Task 7 ================" << std::endl;
    std::cout << "Generating Pokemon Stats" << std::endl;
    Pokemon** playerPokemon = new Pokemon*[3];
    playerPokemon[0] = new Pokemon("Mewtwo", generateRandomNumber(202, 350), generateRandomNumber(322, 416), generateRandomStyle());
    playerPokemon[1] = new Pokemon("Giratina", generateRandomNumber(184, 328), generateRandomNumber(410, 504), generateRandomStyle());
    playerPokemon[2] = new Pokemon("Raichu", generateRandomNumber(166, 306), generateRandomNumber(230, 324), generateRandomStyle());

    Pokemon** enemyPokemon = new Pokemon*[3];
    enemyPokemon[0] = new Pokemon("Nidoqueen", generateRandomNumber(284, 384), generateRandomNumber(290, 446), generateRandomStyle());
    enemyPokemon[1] = new Pokemon("Sandslash", generateRandomNumber(184, 350), generateRandomNumber(386, 452), generateRandomStyle());
    enemyPokemon[2] = new Pokemon("Arbok", generateRandomNumber(175, 317), generateRandomNumber(230, 324) , generateRandomStyle());

    std::cout << "Pokemon Generated" << std::endl;
    std::cout << "=================== Your Team ================" << std::endl;
    printStatus(playerPokemon);

    std::cout << std::endl;

    std::cout << "=================== Enemy Team ================" << std::endl;
    printStatus(enemyPokemon);

    std::cout << std::endl;
    std::cout << "=================== Battle ================" << std::endl;
    int index = 0;
    while(isAlive(playerPokemon) && isAlive(enemyPokemon))
    {
        std::cout << "Your Turn:" << std::endl;
        std::cout << "    ";enemyPokemon[findNextAlive(enemyPokemon)]->takeDamage(playerPokemon[index%3]->attack());
        enemyPokemon[index%3]->setPlayStyle(generateRandomStyle());
        std::cout << "Enemy Turn:" << std::endl;
        std::cout << "    ";playerPokemon[findNextAlive(playerPokemon)]->takeDamage(enemyPokemon[index%3]->attack());
        playerPokemon[index%3]->setPlayStyle(generateRandomStyle());
        std::cout << std::endl;

        std::cout << "Your Team Status:" << std::endl;
        printStatus(playerPokemon);

        std::cout << std::endl;

        std::cout << "Enemy Team Status:" << std::endl;
        printStatus(enemyPokemon);

        std::cout << "============== Next Round ============" << std::endl;
        index++;
    }

    if(isAlive(playerPokemon))
    {
        std::cout << "You win!" << std::endl;
    }
    else
    {
        std::cout << "You lose!" << std::endl;
    }

    for(int i = 0; i < 3; i++) {
        delete playerPokemon[i];
        delete enemyPokemon[i];
    }
    delete[] playerPokemon;
    delete[] enemyPokemon;

    return 0;
}
