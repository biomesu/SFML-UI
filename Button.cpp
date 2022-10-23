//
// Created by realj on 11/24/2021.
//

#include "Button.h"

Button::Button(sf::RectangleShape GUI_PID, sf::RectangleShape GUI_COLOR, sf::Color TEXT_COLOR,
               std::string BUTTON_TEXT) {
    buttonFont.loadFromFile("Fonts/arial.ttf");
    buttonText.setCharacterSize(13);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setFont(buttonFont);
    buttonText.setString(BUTTON_TEXT);
    buttonText.setOrigin(buttonText.getGlobalBounds().width / 2, buttonText.getGlobalBounds().height / 4);


    button.setSize(sf::Vector2f(140.0f, 17.0f));
    themeColor = sf::Color(sf::Color::White);
    buttonSize = button.getSize();
}

void Button::updateButton(sf::RectangleShape GUI_PID, int slot, sf::RenderWindow &window) {
    BUTTON_POSITION = sf::Vector2f(670,280);
    button.setPosition(BUTTON_POSITION);

    BUTTON_TEXTPOSITION = sf::Vector2f(button.getPosition().x + button.getSize().x / 2, button.getPosition().y + 2.0f);
    buttonText.setPosition(BUTTON_TEXTPOSITION);

    rightText.setPosition(button.getPosition().x + button.getSize().x + 10.0f, button.getPosition().y);

    if (sf::Mouse::getPosition(window).x >= button.getPosition().x &&
        sf::Mouse::getPosition(window).x <= button.getPosition().x + button.getSize().x &&
        sf::Mouse::getPosition(window).y >= button.getPosition().y &&
        sf::Mouse::getPosition(window).y <= button.getPosition().y + button.getSize().y)
    {
        button.setFillColor(sf::Color(sf::Color::Blue));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            button.setPosition(BUTTON_POSITION.x + 2.0f, BUTTON_POSITION.y + 2.0f);
            buttonText.setPosition(BUTTON_TEXTPOSITION.x + 2.0f, BUTTON_TEXTPOSITION.y + 2.0f);
        }
    }
    else {
        button.setFillColor(themeColor);
        button.setSize(buttonSize);
    }
}

bool Button::isButtonClicked(sf::RenderWindow &window) {
    if (sf::Mouse::getPosition(window).x >= button.getPosition().x &&
        sf::Mouse::getPosition(window).x <= button.getPosition().x + button.getSize().x &&
        sf::Mouse::getPosition(window).y >= button.getPosition().y &&
        sf::Mouse::getPosition(window).y <= button.getPosition().y + button.getSize().y)
    {
        button.setFillColor(sf::Color(themeColor.r + 30.0f, themeColor.g + 30.0f, themeColor.b + 30.0f));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonClock.getElapsedTime().asSeconds() >= 0.3f)
        {
            buttonClock.restart();
            return true;
        }
        else {
            return false;
        }
    }
}

void Button::Draw(sf::RenderWindow &window, sf::RectangleShape GUI_PID, sf::RectangleShape GUI_COLOR, int slot) {
    window.draw(button);
    window.draw(buttonText);
    window.draw(rightText);
    updateButton(GUI_PID, slot, window);
}
