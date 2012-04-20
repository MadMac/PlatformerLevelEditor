#include "mapeditor.h"

void mapEditor::init(std::vector<layer>* layers)
{
    this->layers = layers;
}

void mapEditor::OnInit()
{
    margin = 1;

//    texture.LoadFromFile("metallipala.png");

//    sprite.SetTexture(texture);
//    sprite.SetPosition(0,0);


}


void mapEditor::OnUpdate()
{


//    Draw(sprite);


    for (int i = 0; i < layers->size(); ++i)
    {

        for (int j = 0; j < layers->at(i).tiles.size(); ++j)
        {
//            layers->at(i).draw(this);
        }
    }




}
