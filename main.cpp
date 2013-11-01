#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct ImageData
{
    unsigned int width;
    unsigned int height;
    unsigned char pixel_data[32 * 32 * 4 + 1];
};

extern const ImageData imageData;

float randomFloat()
{
    return 4.0f; // std::rand() / static_cast<float>(RAND_MAX);
}

sf::Vector2f randomVector(sf::Vector2u bounds)
{
    return sf::Vector2f(randomFloat() * bounds.x, randomFloat() * bounds.y);
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(0)));

    sf::RenderWindow screen(sf::VideoMode(800, 600, 32), "SFML Window");

    sf::Image image;
    image.create(imageData.width, imageData.height, imageData.pixel_data);

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2f position = randomVector(screen.getSize() - image.getSize());
    sprite.setPosition(position);

    bool running = true;
    while (running)
    {
        sf::Event event;
        while (screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                running = false;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                running = false;
            }
        }

        screen.draw(sprite);
        screen.display();
    }
}

const ImageData imageData =
{
    32,
    32,
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0"
    "\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0"
    "\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0"
    "\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0"
    "\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0"
    "\0\377\0\224\377\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377"
    "\0\0\0\377\0\224\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0"
    "\0\0\377\0\224\377\377\0\224\377\377\0\224\377\377\0\0\0\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\0\0\0\377\0\224\377\377\0\224\377\377\0\224\377\377\0\0\0\377"
    "\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\0\0\0\377\0\0\0\377\0\224\377\377\0\224\377\377\0\224\377"
    "\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\0\0\0\377\0\224\377\377\0\224\377\377"
    "\0\224\377\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\224\377\377"
    "\0\224\377\377\0\224\377\377\0\0\0\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0"
    "\224\377\377\0\224\377\377\0\224\377\377\0\0\0\377\0\0\0\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\0\0\0\377\0\224\377\377\0\224\377\377\0\224\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\0\224\377\377\0\224\377"
    "\377\0\224\377\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0"
    "\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0"
    "\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377"
    "\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377"
    "\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
    "\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0"
    "\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0"
    "\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0"
    "\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0"
    "\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\377\377\377\377\377"
    "\377\377\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377"
    "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
    "\377\377\0\0\0\377",
};
