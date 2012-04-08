#include "mapeditor.h"

void mapEditor::OnInit()
{

    texture.LoadFromFile("metallipala.png");

    sprite.SetTexture(texture);
    sprite.SetPosition(10,10);

}


void mapEditor::OnUpdate()
{
    Clear(sf::Color(0, 0, 0));
    Draw(sprite);
}
