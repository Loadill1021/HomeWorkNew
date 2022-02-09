#pragma once

// Ό³Έν :
class Dest
{
public:
	// constrcuter destructer
	Dest();
	~Dest();

	// delete Function
	Dest(const Dest& _Other) = delete;
	Dest(Dest&& _Other) noexcept = delete;
	Dest& operator=(const Dest& _Other) = delete;
	Dest& operator=(Dest&& _Other) noexcept = delete;

protected:

private:

};

