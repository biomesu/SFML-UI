//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_SLIDER_H
#define SFML_PROJECT_SLIDER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>


using namespace std;

class Slider : public sf::Drawable {
private:
    sf::RectangleShape line;
    sf::CircleShape dial;

    bool dragging = false;
public:
    Slider();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void move(sf::RenderWindow& window);


};


#endif //SFML_PROJECT_SLIDER_H
