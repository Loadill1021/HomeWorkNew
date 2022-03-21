#include "PlayLevel.h"
#include "Player.h"
#include "BotUI.h"
enum class ORDER
{
	BACKGROUND,
	MONSTER,
	PLAYER,
	UI
};
PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading()
{
	CreateActor<Player>("Player",(int)ORDER::PLAYER);
	CreateActor<BotUI>("BotUI", (int)ORDER::UI);
}
void PlayLevel::Update()
{

}
void PlayLevel::LevelChangeStart()
{
	int a = 0;
}