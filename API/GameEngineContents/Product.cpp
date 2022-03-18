#include "Product.h"
#include "GameEngineBase/GameEngineWindow.h"
Product::Product() 
{
}

Product::~Product()
{
}
void Product::Start()
{
	SetPosition(GameEngineWindow::GetInst().GetScale().Half());
	SetScale(GameEngineWindow::GetScale().Half().Half());
}
void Product::Update()
{

}
void Product::Render()
{
	DebugRectRender();
}
