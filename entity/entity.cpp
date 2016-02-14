#include "Entity/entity.h"


Entity::Entity(SDL_setup * gameSetup, int width, int height, std::string name,std::string path)
{
    name = name;
    isMoving = false;
//     std::cout << name <<" width is " << width << std::endl;
//     std::cout << name <<" height is " << height << std::endl;

   setup = gameSetup;

   //player = new CSprite(setup->getRenderer(),path.c_str(),0,0);
//    std::cout << name <<" sprite created" << std::endl;
   //player->setupAnimation(4,4);
}

CSprite *Entity::getSprite()
{
    return player;
}

void Entity::setPlayer(CSprite *value)
{
    player = value;
}
void Entity::Draw()
{
    player->Draw();

}

void Entity::DrawBackground(SDL_Rect *camera)
{
    player->DrawBackground(camera);
}
void Entity::setInitFrame(int startFrame,int row)
{
  player->setInitFrame(startFrame,row);
}
void Entity::setCamera(){
    player->setCamera();

}
void Entity::setOrigin(int X, int Y)
{

   player->setOrigin(X,Y);
}
SDL_Rect Entity::getCamera()
{
    return player->getCamera();
}
bool Entity::GetMoving()
{
    if (isMoving == true)
    {
        return true;
    }
    return false;
}
void Entity::setIsMoving(bool value)
{
    isMoving = value;
}
