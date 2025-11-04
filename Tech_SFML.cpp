#include <SFML/Graphics.hpp>

int main()
{
    // SFML 2.x 스타일의 생성자
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML 2.6.1 Test");

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    // SFML 2.x 표준 이벤트 루프
    while (window.isOpen())
    {
        // 1. 이벤트 객체를 루프 밖이나 안에 선언합니다.
        sf::Event event;
        // 2. pollEvent(단수형)로 이벤트를 하나씩 가져옵니다.
        while (window.pollEvent(event))
        {
            // 3. event.type으로 이벤트를 비교합니다.
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}