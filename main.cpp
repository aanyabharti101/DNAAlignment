
// Copyright 2026 Aanya Bharti

#include <iostream>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#include "EDistance.hpp"

int main() {
    std::string x;
    std::string y;

    std::getline(std::cin, x);
    std::getline(std::cin, y);

    auto clean = [](std::string& s) {
    s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());
};

clean(x);
clean(y);


    sf::Clock clock;

    EDistance ed(x, y);
    int dist = ed.optDistance();

    std::cout << "Edit distance = " << dist << std::endl;
    std::cout << ed.alignment();

    sf::Time t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds" << std::endl;

    return 0;
}
