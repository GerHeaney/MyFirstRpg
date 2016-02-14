#include "environment.h"


Environment::Environment(SDL_setup * setup,int screenWidth, int screenHeight)
{

    //grass = new CSprite(setup->getRenderer(),"resources/map.png",0,0);

    //tree = new Tree(setup,800,800,cameraX,cameraY);
    trees.push_back(new Tree(setup,800,800));
}

Environment::~Environment()
{
    delete grass;
    for(std::vector<Tree*>::iterator i = trees.begin();i!=trees.end();++i)
    {
       delete (*i);
    }
    trees.clear();
}
void Environment::DrawBack(SDL_Rect * passedCamera)
{
     grass->DrawBackground(passedCamera);

}
void Environment::DrawFront(SDL_Rect * passedCamera)
{
     for(std::vector<Tree*>::iterator i = trees.begin();i!=trees.end();++i)
     {
         (*i)->Draw(passedCamera);
     }
}
void Environment::Update()
{

}
int Environment:: getLevelWidth()
{
   return grass->getWidth();
}
int Environment::getLevelHeight()
{
    return grass->getHeight();
}
