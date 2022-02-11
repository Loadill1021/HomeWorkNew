#pragma once

// Ό³Έν :
class ConsoleScreen
{
public:
	// constrcuter destructer
	ConsoleScreen();
	~ConsoleScreen();

	// delete Function
	ConsoleScreen(const ConsoleScreen& _Other) = delete;
	ConsoleScreen(ConsoleScreen&& _Other) noexcept = delete;
	ConsoleScreen& operator=(const ConsoleScreen& _Other) = delete;
	ConsoleScreen& operator=(ConsoleScreen&& _Other) noexcept = delete;

protected:

private:

};

