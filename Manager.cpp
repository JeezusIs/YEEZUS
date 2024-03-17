#include <iostream>
#include <random>
#include <memory>
#include "Manager.h"
#include "Spaceship.h"
#include "Event.h"

class Spaceship;
class PowerfulShip;
class BalancedShip;
class FastShip;

int RandomNumberGenerator(int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(start, end);

    int random_number = distribution(gen);
    return random_number;
}

std::shared_ptr<Spaceship>getSelectedShip() {
    int shipSelector{ 0 };
    std::cout << "Please select your ship type. \n\n";
    std::cout << "1-Balanced ship\n";
    std::cout << "2-Fast ship\n";
    std::cout << "3-Powerful ship\n\n";
    std::cin >> shipSelector;

    if (shipSelector == 1) {
        std::cout << "You've selected Balanced Ship\n";
        return std::make_shared<BalancedShip>(50, 1);
    }
    else if (shipSelector == 2) {
        std::cout << "You've selected Fast Ship\n";
        return std::make_shared<FastShip>(75, 1.5);
    }
    else if (shipSelector == 3) {
        std::cout << "You've selected Powerful Ship\n";
        return std::make_shared<PowerfulShip>(25, 0.5);
    }
    else {
        std::cout << "Please select a valid number.\n";
        return nullptr;
    }

}

void RandomEventGenerator(std::shared_ptr<Spaceship> getSelectedShip) {
    getSelectedShip->status();
    int eventCounter{ 0 }, eventFirst{ 1 }, eventLast{ 3 }, totalEvent{ 5 };
    while ((eventCounter < totalEvent) && (getSelectedShip->getFuel() >= 1)) {
        int eventNumber = RandomNumberGenerator(eventFirst, eventLast);
        if (eventNumber == 1) {
            ++eventCounter;
            events MyEvent;
            MyEvent.AstreoidBelt(getSelectedShip);
            getSelectedShip->status();
            std::cout << "Event counter: " << eventCounter << "\n";
        }
        else if (eventNumber == 2) {
            ++eventCounter;
            events my_event;
            my_event.AbondenedPlanet(getSelectedShip);
            getSelectedShip->status();
            std::cout << "Event counter: " << eventCounter << "\n";
        }
        else if (eventNumber == 3) {
            ++eventCounter;
            events myEvent;
            myEvent.SpacePirates(getSelectedShip);
            getSelectedShip->status();
            std::cout << "Event counter: " << eventCounter << "\n";
        }

    }
}


void ScoreCalculator(std::shared_ptr<Spaceship> selectedShip) {
    int healthMultiplier{ 10 }, fuelMultiplier{ 5 }, cashMultiplier{ 10 };
    float endGameScore;
    endGameScore = (selectedShip->getHp() * healthMultiplier) + (selectedShip->getFuel() * fuelMultiplier) + (selectedShip->getCash() * cashMultiplier);
    std::cout << "Your endgame score is " << endGameScore << "\n";

}
