#include "mapeditor.h"

void mapEditor::OnInit()
{
    margin = 1;

    texture.LoadFromFile("metallipala.png");

    sprite.SetTexture(texture);
    sprite.SetPosition(0,0);

    border.SetPosition(sf::Vector2f(margin,margin));
    border.SetSize(sf::Vector2f(canvasSize.width()-margin*2,canvasSize.height()-margin*2));
    border.SetOutlineColor(sf::Color(15,20,25));
    border.SetOutlineThickness(1);
    border.SetFillColor(sf::Color::Transparent);

    currentTile.SetSize(sf::Vector2f(32,32));
    currentTile.SetOutlineColor(sf::Color(191, 215, 255));
    currentTile.SetOutlineThickness(1);
    currentTile.SetFillColor(sf::Color(150, 185, 255, 50));

    mainCamera.SetSize(sf::Vector2f(canvasSize.width(),canvasSize.height()));
    mainCamera.SetCenter(canvasSize.width()/2,canvasSize.height()/2);
    SetView(mainCamera);
}


void mapEditor::OnUpdate()
{
    Clear(sf::Color(0, 0, 0));

    cursorPos = mapFromGlobal(QCursor::pos());

    Draw(sprite);

    if (cursorPos.x() > 0 && cursorPos.x() < canvasSize.width() && cursorPos.y() > 0 && cursorPos.y() < canvasSize.height())
    {
        qDebug() << mapFromGlobal(QCursor::pos());
        currentTile.SetPosition(sf::Vector2f(floor(cursorPos.x()/32)*32, floor(cursorPos.y()/32)*32));
        Draw(currentTile);
    }



    //Draw border
   // Draw(border);


}
