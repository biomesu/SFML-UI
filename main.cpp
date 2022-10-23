#include <SFML/Graphics.hpp>
#include "Gui.h"
#include "ListBox.h"
#include "CheckBox.h"
#include "Button.h"
#include "Slider.h"
#include "Slider2.h"
#include "Slider3.h"
#include "MyObject.h"
#include "menubar.h"
#include "text.h"
#include <string>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SIMPLISTIC GUI BY ME!");

    // Color hue picker
   sf::VertexArray quad(sf::Quads, 4);

    quad[0].position = sf::Vector2f(900, 250);
    quad[1].position = sf::Vector2f(1000, 250);
    quad[2].position = sf::Vector2f(1000, 350);
    quad[3].position = sf::Vector2f(900, 350);



// define the color of the triangle's points
   quad[0].color = sf::Color::Red;
   quad[1].color = sf::Color::Blue;
   quad[2].color = sf::Color::Green;
   quad[3].color = sf::Color::White;

    window.setFramerateLimit(60);

    //actual GUI
    gui GUI("GUI", sf::Vector2f(700, 500), sf::Vector2f(720, 400), sf::Color(sf::Color::White), sf::Color(255, 255, 255), sf::Color(sf::Color::White));

    //Top DropdownMenu
    gui GUI2("GUI", sf::Vector2f(700, 500), sf::Vector2f(0, 400), sf::Color(sf::Color::White), sf::Color(255, 255, 255), sf::Color(sf::Color::White));

    text Text1(GUI.getGUI(), "Background Opacity","", "", "","", sf::Color(sf::Color::White), window);
    text Text2(GUI.getGUI(), "", "Text Opacity", "", "","", sf::Color(sf::Color::White), window);
    text Text3(GUI.getGUI(), "", "", "Shadow Opacity", "","",sf::Color(sf::Color::White), window);
    text Text4(GUI.getGUI(), "", "", "Shadow Opacity", "Logo Text","",sf::Color(sf::Color::White), window);
    text Text5(GUI.getGUI(), "", "", "", "","Color Picker",sf::Color(sf::Color::White), window);


    CheckBox checkBox1(GUI.getGUIColor(), "Checkbox", sf::Color(sf::Color::White));


    //Slider slider;
    Slider2 slider2(GUI.getGUIColor(), sf::Color(sf::Color::White), 200, "Text X-Axis");

    Slider3 sliderInt3(GUI.getGUIColor(), sf::Color(sf::Color::White), 200, "Text Y-Axis");

    Slider3 sliderInt3Color(GUI.getGUIColor(), sf::Color(sf::Color::White), 173, "");


    Button button(GUI.getGUI(), GUI.getGUIColor(), sf::Color(sf::Color::White), "Button");


    Label t;
    MyObject o;


    bool checktest = false;
    float woah = 15;

    int int3Test = 15;
    int int3Test2 = 15;
    int int3Test3 = 15;

    int testColor1 = 0;
    int testColor2 = 0;
    int testColor3 = 0;

    float float3Test = 0;
    float float3Test2 = 0;
    float float3Test3 = 0;

    bool clicked = false;

    float slider2Test = 0;
    float slider2Test2 = 0;


    ListBox listbox(GUI.getGUIColor(), 200);

    int selectedItem = 1;
    std::string items[]{ "Dropdown 1", "Dropdown 2", "Dropdown 3" };

    menubar menubar(GUI2.getGUIColor(), 200);

    std::string items2[]{ "Load", "Save", "Exit" };



    // text input fonts and positioning
    sf::Font arial;
    arial.loadFromFile("fonts/arial.ttf");
    TextInput textInput1(50, sf::Color::White, true);
    textInput1.setFont(arial);
    textInput1.setPosition({450,100});


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type) {

                case sf::Event::Closed:
                    window.close();
                case sf::Event::TextEntered:
                    textInput1.typedOn(event);
                    textInput1.setPosition(sf::Vector2f(300,550));

                 if (event.text.unicode < 128) {
                     std::cout << static_cast<char> (event.text.unicode);
                 }



            }
            o.update();
            window.clear(sf::Color::Black);
            window.draw(o);
            Text1.Draw(window, 1,GUI.getGUI());
            Text2.Draw(window, 2,GUI.getGUI());
            Text3.Draw(window, 3,GUI.getGUI());
            Text4.Draw(window, 4,GUI.getGUI());
            Text5.Draw(window, 4,GUI.getGUI());

            textInput1.drawTo(window);
         //   o.addEventHandler(window,event);



            button.Draw(window, GUI.getGUI(), GUI.getGUIColor(), 9);
            slider2.Draw(window, 3, GUI.getGUI(), woah, 0, 1280);

            sliderInt3.Draw(window, 4, GUI.getGUI(), int3Test, 0, 1280, int3Test2, 0, 720, int3Test3, 60, 400);
            sliderInt3Color.Draw(window, 5, GUI.getGUI(), testColor1, 0, 255, testColor2, 0, 255, testColor3, 0, 255);

            checkBox1.Draw(window, 8, GUI.getGUI(), checktest);

            listbox.Draw(window, GUI.getGUI(), 11, 2, items, selectedItem);
            menubar.Draw(window, GUI2.getGUI(), 10, 2, items2, selectedItem);
            window.draw(quad);


            window.display();
        }

    }

    return 0;
}
