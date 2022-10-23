//
// Created by realj on 11/28/2021.
//

#ifndef SFML_PROJECT_LABEL_H
#define SFML_PROJECT_LABEL_H
#include <SFML/Graphics.hpp>

class Label : public sf::Drawable {
private:
    sf::Text label;
    sf::Font font;

public:
    Label();
    Label(const sf::Text &label);


    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;


    void setString(const std::string& string);
};


#endif //SFML_PROJECT_LABEL_H
