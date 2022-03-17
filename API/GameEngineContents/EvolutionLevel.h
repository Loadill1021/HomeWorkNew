#pragma once

// Ό³Έν :
class EvolutionLevel
{
public:
	// constrcuter destructer
	EvolutionLevel();
	~EvolutionLevel();

	// delete Function
	EvolutionLevel(const EvolutionLevel& _Other) = delete;
	EvolutionLevel(EvolutionLevel&& _Other) noexcept = delete;
	EvolutionLevel& operator=(const EvolutionLevel& _Other) = delete;
	EvolutionLevel& operator=(EvolutionLevel&& _Other) noexcept = delete;

protected:

private:

};

