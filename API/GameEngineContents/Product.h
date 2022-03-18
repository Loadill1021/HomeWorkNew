#pragma once
#include <GameEngine/GameEngineActor.h>
// Ό³Έν :
class Product:public GameEngineActor
{
public:
	// constrcuter destructer
	Product();
	~Product();

	// delete Function
	Product(const Product& _Other) = delete;
	Product(Product&& _Other) noexcept = delete;
	Product& operator=(const Product& _Other) = delete;
	Product& operator=(Product&& _Other) noexcept = delete;

protected:
	void Start()override;
	void Update()override;
	void Render()override;
private:

};

