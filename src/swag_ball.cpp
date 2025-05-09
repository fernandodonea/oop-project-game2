#include "swag_ball.h"


namespace Game_Entities
{

void SwagBall::_InitShape(const sf::RenderWindow& window )
{
    this->shape.setRadius(static_cast<float>(rand()%10+10));
    sf::Color color;
    switch(this->type)
    {
        case DEFAULT:
            color=sf::Color(rand()%255+1,rand()%255+1,rand()%255+1);
            break;
        case DAMAGING:
            color=sf::Color::Red;
            this->shape.setOutlineColor(sf::Color::White);
            this->shape.setOutlineThickness(2.f);
            break;
        case HEALING:
            color=sf::Color::Green;
            this->shape.setOutlineColor(sf::Color::White);
            this->shape.setOutlineThickness(2.f);
            break; 
    }
    
    this->shape.setFillColor(color);
    this->shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand()%window.getSize().x - this->shape.getGlobalBounds().width),
            static_cast<float>(rand()%window.getSize().y - this->shape.getGlobalBounds().height)
        )
    );
}

SwagBall::SwagBall (const sf::RenderWindow& window, int type) 
    :type(type)
{
    this->_InitShape(window); 

}
 SwagBall::~SwagBall ()
 {
    
 }

const sf::CircleShape SwagBall::GetShape() const
{
    return this->shape;
}
const int& SwagBall::GetType() const
{
    return this->type;
}

void SwagBall::Update()
{

}
void SwagBall::Render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}

} //namespace Game_Entities