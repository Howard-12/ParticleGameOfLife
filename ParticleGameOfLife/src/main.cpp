#include <iostream>
#include <vector>
#include <math.h>

#include "Dot.h"
#include "Game.h"

std::vector<Dot> green;
std::vector<Dot> red;
std::vector<Dot> yellow;

float random(const int min, const unsigned int &max) { return std::rand() % (max - min) + min; }

void interact(std::vector<Dot>& group1, std::vector<Dot>& group2, float g, float deltaTime, const unsigned int winWidth, const unsigned int winHeight)
{
    for (auto &g1 : group1)
    {
        float fx = 0;
        float fy = 0;
        for (const auto &g2 : group2)
        {
            const float dx = g1.x - g2.x;
            const float dy = g1.y - g2.y;
            const float ds = dx * dx + dy * dy;
            const float d = std::sqrt(ds);
            if (d > 0 && d < 90)
            {
                float F = g / d;
                fx += F * dx;
                fy += F * dy;
            }
        }
        g1.vx = (g1.vx + fx) * 0.1f;
        g1.vy = (g1.vy + fy) * 0.1f;
        g1.x += g1.vx * deltaTime;
        g1.y += g1.vy * deltaTime;

        //if (g1.x <= 0 || g1.x >= sf::VideoMode::getDesktopMode().width)
        //    g1.vx *= -1;
        //if (g1.y <= 0 || g1.y >= sf::VideoMode::getDesktopMode().height)
        //    g1.vy *= -1;
        if (g1.x < -6)
            g1.x += ((float)winWidth + 6.f);
        if (g1.x > winWidth)
            g1.x -= ((float)winWidth + 6.f);
        if (g1.y < -6)
            g1.y += ((float)winHeight + 6.f);
        if (g1.y > winHeight)
            g1.y -= ((float)winHeight + 6.f);
    }
}

int main()
{
    auto game = std::make_unique< Game::Game>();

    // Create dots
    for (int i = 0; i < 1200; ++i)
    {
        green.push_back(Dot(random(50, game->winWidth), random(50, game->winHeight), sf::Color::Green));
        red.push_back(Dot(random(50, game->winWidth), random(50, game->winHeight), sf::Color::Red));
        yellow.push_back(Dot(random(50, game->winWidth), random(50, game->winHeight), sf::Color::Yellow));

    }

    // Main loop
    while (game->window.isOpen())
    {     
        game->start();
        game->events();

        game->drawGUI();

        // Clear window
        game->clear();

        // Updates     
        interact(green, green, -0.32, game->getDeltaTime(), game->winWidth, game->winHeight);
        interact(green, red, -0.18, game->getDeltaTime(), game->winWidth, game->winHeight);
        interact(green, yellow, 0.34, game->getDeltaTime(), game->winWidth, game->winHeight);
        interact(red, red, -0.10, game->getDeltaTime(), game->winWidth, game->winHeight);
        interact(red, green, -0.34, game->getDeltaTime(), game->winWidth, game->winHeight);
        interact(yellow, yellow, 0.15, game->getDeltaTime(), game->winWidth, game->winHeight);
        interact(yellow, green, -0.20, game->getDeltaTime(), game->winWidth, game->winHeight);

        for (auto &g : green)
        {
            g.draw(game->window);
        }

        for (auto &r : red)
        {
            r.draw(game->window);
        }

        for (auto& y : yellow)
        {
            y.draw(game->window);
        }

        // Display
        game->display();
    }

    return 0;
}