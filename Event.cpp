#include "Event.h"
#include "Spaceship.h"
#include "Manager.h"

class Spaceship;
class FastShip;
class PowerfulShip;
class BalancedShip;


void events::AstreoidBelt(std::shared_ptr<Spaceship> selectedShip) {
    int possibility = RandomNumberGenerator(1, 2);
    std::cout << "You're now entering an Asteroid Belt.\n\n";
    float normalDmg = 30;  

    if (possibility == 1) {
        std::cout << "Our ship has taken damage while passing the Asteroid belt.\n\n";
        float newHp = selectedShip->getHp() - normalDmg;
        if (newHp < 0) {
            newHp = 0; 
        }
        selectedShip->setHp(newHp);
    }
    else {
        std::cout << "We've successfully passed the Asteroid belt without taking any damage.\n\n";
    }
};


void events::AbondenedPlanet(std::shared_ptr<Spaceship> selectedShip) {
    int posibility, i;
    int startOfRange = 0;
    int endOfRange = 2;
    posibility = RandomNumberGenerator(startOfRange, endOfRange);
    std::cout << "We've found a abondened planet\n\n";

    if (posibility == 0) {
        std::cout << "We've found a treausure\n\n";
        selectedShip->setCash(selectedShip->getCash() + 10);
    }
    if (posibility == 1) {
        std::cout << "Planet is completely abandoned.\n\n";
    }
    if (posibility == 2) {
        std::cout << "Good lord, we've encountered space pirates!\n\n";
    }
};

void events::SpacePirates(std::shared_ptr<Spaceship> selectedShip) {
    int possibility, dialogueOption;
    std::cout << "\nWe've encountered space pirates.\n Pirate: Fool voyager in the search for meaning, emboldened by the sin of ambition. Thee shall not pass.\n";
    std::cout << "1-I believe we can settle this.(Pay tribute)\n2-...(Attack)\n3-...(Flee)\n";
    std::cin >> dialogueOption;

    if (dialogueOption == 1) {
        int tributePossibility = RandomNumberGenerator(0, 2);
        std::cout << tributePossibility;
        int tributeAmount = (tributePossibility + 1) * 10; 
        selectedShip->setCash(selectedShip->getCash() - tributeAmount);
        std::cout << "Pirates have taken " << tributeAmount << " credits.\nPirates: We better not see you around here any time soon.\n\n";
    }
    else if (dialogueOption == 2) {
        possibility = RandomNumberGenerator(0, 1);
        if (possibility == 0) {
            const float normalDmg = 30;
            float newHp = selectedShip->getHp() - normalDmg;
            if (newHp < 0) {
                newHp = 0; 
            }
            selectedShip->setHp(newHp);
            std::cout << "We've lost the battle.\n\n";
        }
        else {
            selectedShip->setCash(selectedShip->getCash() + 10);
            std::cout << "We've defeated those pirates.\n\n";
        }
    }
    else if (dialogueOption == 3) {
        if (selectedShip->getFuel() >= 33) {
            int fledChance = RandomNumberGenerator(0, 100);
            if (fledChance < selectedShip->getEscapePossibility()) {
                std::cout << "We've escaped successfully.\n\n";
                selectedShip->setFuel(selectedShip->getFuel() - 33);
            }
            else {
                std::cout << "We've failed to flee.\n\n";
                selectedShip->setFuel(selectedShip->getFuel() - 33);
                SpacePirates(selectedShip); 
            }
        }
    }
};
