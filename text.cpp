//
// Created by realj on 11/24/2021.
//

#include "text.h"

text::text(sf::RectangleShape GUI_BACKGROUND, std::string TEXT,std::string TEXT2, std::string TEXT3, std::string LOGOTEXT, std::string PICKERTEXT, sf::Color TEXT_COLOR, sf::RenderWindow &window) {
    font.loadFromFile("Fonts/arial.ttf");
    Text.setCharacterSize(13);
    Text.setFillColor(TEXT_COLOR);
    Text.setFont(font);
    Text.setString(TEXT);


    font2.loadFromFile("Fonts/arial.ttf");
    Text2.setCharacterSize(13);
    Text2.setFillColor(TEXT_COLOR);
    Text2.setFont(font2);
    Text2.setString(TEXT2);

    font3.loadFromFile("Fonts/arial.ttf");
    Text3.setCharacterSize(13);
    Text3.setFillColor(TEXT_COLOR);
    Text3.setFont(font3);
    Text3.setString(TEXT3);

    Logofont.loadFromFile("Fonts/arial.ttf");
    LogoText.setCharacterSize(13);
    LogoText.setFillColor(TEXT_COLOR);
    LogoText.setFont(Logofont);
    LogoText.setString(LOGOTEXT);

    Pickerfont.loadFromFile("Fonts/arial.ttf");
    PickerText.setCharacterSize(13);
    PickerText.setFillColor(TEXT_COLOR);
    PickerText.setFont(Pickerfont);
    PickerText.setString(PICKERTEXT);



}

void text::updateText(sf::RenderWindow &window, int slot, sf::RectangleShape GUI_BACKGROUND) {
//    sf::Vector2f TEXT_POSITION;

 //   TEXT_POSITION = sf::Vector2f();

    Text.setPosition(sf::Vector2f(250,247));

    Text2.setPosition(sf::Vector2f(290,270));

    Text3.setPosition(sf::Vector2f(275,288));

    LogoText.setPosition(sf::Vector2f(425,80));

    PickerText.setPosition(sf::Vector2f(910,230));


}

void text::Draw(sf::RenderWindow &window, int slot, sf::RectangleShape GUI_PID) {
    window.draw(Text);
    window.draw(Text2);
    window.draw(Text3);
    window.draw(LogoText);
    window.draw(PickerText);
    updateText(window, slot, GUI_PID);
}

sf::Text text::returnText() {
    return Text;

}

sf::Text text::returnText2() {
    return Text2;
}

sf::Text text::returnText3() {
    return Text3;
}

sf::Text text::returnText4() {
    return LogoText;
}

sf::Text text::returnText5() {
    return PickerText;
}
