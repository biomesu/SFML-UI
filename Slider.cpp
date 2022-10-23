//
// Created by realj on 11/24/2021.
//

#include "Slider.h"


Slider::Slider()
{
    line.setSize({500,5});
    dial.setRadius(10);
    line.setPosition(250, dial.getGlobalBounds().height/2 - line.getGlobalBounds().height/2);
    dial.setOrigin({dial.getGlobalBounds().width/2, dial.getGlobalBounds().height/2});


}

void Slider::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && dial.getGlobalBounds().contains(mpos)
&& event.MouseMoved)
    {
    dragging = true;
    }
    else if (dragging && event.type == sf::Event::MouseButtonReleased)
    {
        dragging = false;
    }
    if(dragging)
    {
        move(window);
    }

}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(line);
    window.draw(dial);
}

void Slider::move(sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    dial.setPosition(mpos.x, dial.getPosition().y);

}
