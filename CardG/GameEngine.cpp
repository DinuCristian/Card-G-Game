#include "GameEngine.h"

void GameEngine::initCardDeck()
{
	this->cardDeck->clearCards();

	// Loop through all allowed power values
	for (int power = 1; power <= 5; power++)
	{
		// Add Minus cards of current power value
		for (int i = 0; i < this->getMinusCardCount(power); i++)
		{
			this->cardDeck->addCard(gcnew MinusCard(power));
		}

		// Add Plus cards of current power value
		for (int i = 0; i < this->getPlusCardCount(power); i++)
		{
			this->cardDeck->addCard(gcnew PlusCard(power));
		}
	}

	// Add Steal cards
	for (int i = 0; i < this->getCardStealCount(); i++)
	{
		this->cardDeck->addCard(gcnew StealCard());
	}

	// Add Double cards
	for (int i = 0; i < this->getCardDoubleCount(); i++)
	{
		this->cardDeck->addCard(gcnew DoubleCard());
	}

	// Add Change cards
	for (int i = 0; i < this->getCardChangeCount(); i++)
	{
		this->cardDeck->addCard(gcnew ChangeCard());
	}
}

void GameEngine::virtualPlayerThinks()
{
	RandomNumberGenerator^ randomNumberGenerator = RandomNumberGenerator::getInstance();
	GameSettings^ gameSettings = GameSettings::getInstance();

	int lowerBound, upperBound;
	gameSettings->getVirtualPlayerSpeedBounds(&lowerBound, &upperBound);

	int millisecondsTimeout = randomNumberGenerator->getRandomInt(lowerBound, upperBound);
	System::Threading::Thread::Sleep(millisecondsTimeout);
}

void GameEngine::sendNotification()
{
	// Build the notification message. This includes turn, score of both players (player and virtual player), played card, and the card set of both players (player and virtual player).
	String^ message = "  Turn: " + this->gameState->getStateDescription() + "\n";
	message += "  " + this->getVirtualPlayerName() + " Score: " + this->getVirtualPlayerScore() + "\n";
	message += "  " + this->getPlayerName() + " Score: " + this->getPlayerScore() + "\n";
	if (this->gameState->isPlayerTurn())
	{
		message += "  " + this->getPlayerName() + " Played Card: " + this->player->getLastPlayedCardDescription() + "\n";
	}
	if (this->gameState->isVirtualPlayerTurn())
	{
		message += "  " + this->getVirtualPlayerName() + " Played Card: " + this->virtualPlayer->getLastPlayedCardDescription() + "\n";
	}
	message += "  " + this->getVirtualPlayerName() + " Card Set: " + this->virtualPlayer->getCardsDescription() + "\n";
	message += "  " + this->getPlayerName() + " Card Set: " + this->player->getCardsDescription() + "\n";

	this->notify(message);
}

GameEngine::GameEngine(String^ playerName)
{
	this->maxPlayerCardsCount = 5;
	this->maxVirtualPlayerCardsCount = 5;

	// Set the initial state of the game.
	this->gameState = gcnew NoGameState(this);

	this->cardDeck = gcnew CardDeck();

	this->player = gcnew Player(playerName, this->maxPlayerCardsCount);
	this->virtualPlayer = gcnew VirtualPlayer("Neo", this->maxVirtualPlayerCardsCount);

	this->player->setOpponent(this->virtualPlayer);
	this->virtualPlayer->setOpponent(this->player);

	GameSettings::getInstance();

	// Attach the file logger to the game engine.
	this->attach(gcnew FileLogger());
}

void GameEngine::setState(GameState^ gameState)
{
	// Send a notification if the game is not finished.
	if (!this->gameState->isGameFinished())
	{
		this->sendNotification();
	}

	this->gameState = gameState;
	onGameStateChanged(gameState->getStateDescription());

	// Send a notification if the game is finished.
	if (this->gameState->isGameFinished())
	{
		this->sendNotification();
	}
}

void GameEngine::newGame(bool canceled)
{
	if (!canceled)
	{
		// If the new game is not canceled, init and shuffle the card deck, then init the player and virtual player cards.
		this->initCardDeck();
		this->cardDeck->shuffle();

		this->player->clearCards();
		this->virtualPlayer->clearCards();

		// Set the state to the deal player state.
		this->setState(gcnew DealPlayerState(this));
	}
	else
	{
		// The new game is canceled.
		this->setState(gcnew NoGameState(this));
	}
	onNewGame();
}

int GameEngine::getCardDeckMaxCardsCount()
{
	return this->cardDeck->getMaxCardsCount();
}

String^ GameEngine::getPlayerName()
{
	return this->player->getName();
}

int GameEngine::getMaxPlayerCardsCount()
{
	return this->maxPlayerCardsCount;
}

int GameEngine::getPlayerScore()
{
	return this->player->getScore();
}

String^ GameEngine::addPlayerCard(int cardIndex)
{
	// Remove the card from the card deck.
	Card^ card = this->cardDeck->removeCardAt(cardIndex);
	// Add card to the player card set.
	this->player->addCard(card);
	String^ cardName = card->getName();
	onPlayerSelectedCard(cardIndex, cardName);
	// Advance the game state.
	this->gameState->nextState();
	return cardName;
}

bool GameEngine::playerSelectedAllCards()
{
	return this->player->selectedAllCards();
}

bool GameEngine::isPlayerTurn()
{
	return this->gameState->isPlayerTurn();
}

void GameEngine::playerPlaysCard(int cardIndex)
{
	// Get the card to play.
	Card^ card = this->player->getCardAt(cardIndex);

	// If the card is not played or stolen.
	if (card != nullptr)
	{
		// Play the card.
		this->player->playCard(cardIndex);
		String^ cardName = card->getName();
		onPlayerPlayedCard(cardIndex, cardName);
		onScoreChanged(this->virtualPlayer->getScore(), this->player->getScore());
	}

	// Advance the game state.
	this->gameState->nextState();
}

bool GameEngine::playerHasCards()
{
	return this->player->hasCards();
}

bool GameEngine::isLastPlayerPlayedCardSteal()
{
	return this->player->isLastPlayedCardSteal();
}

bool GameEngine::isPlayerSteal()
{
	return this->gameState->isPlayerSteal();
}

void GameEngine::playerStealsCard(int cardIndex)
{
	// Get the card to steal from the virtual player.
	Card^ card = this->virtualPlayer->getCardAt(cardIndex);

	// If the card is not played or stolen.
	if (card != nullptr)
	{
		// Remove card from the virtual player card set.
		this->virtualPlayer->removeCardAt(cardIndex);
		// Add card to the player card set.
		int newCardIndex = this->player->insertCard(card);
		onPlayerStoleCard(cardIndex, newCardIndex, card->getName());
	}

	// Advance the game state.
	this->gameState->nextState();
}

String^ GameEngine::getVirtualPlayerName()
{
	return this->virtualPlayer->getName();
}

int GameEngine::getMaxVirtualPlayerCardsCount()
{
	return this->maxVirtualPlayerCardsCount;
}

int GameEngine::getVirtualPlayerScore()
{
	return this->virtualPlayer->getScore();
}

void GameEngine::selectVirtualPlayerCards()
{
	// Return if the virtual player selected all cards.
	if (!this->player->selectedAllCards())
	{
		return;
	}

	int cardsSelected = 0;
	while (cardsSelected < 5)
	{
		// Get a random card index from the card deck.
		int cardIndex = this->virtualPlayer->selectCardIndex(0, this->cardDeck->getMaxCardsCount());
		// Remove the card at the random card index from the card deck.
		Card^ card = this->cardDeck->removeCardAt(cardIndex);

		// If the card is not selected.
		if (card != nullptr)
		{
			// Add card to the virtual player card set.
			this->virtualPlayer->addCard(card);
			cardsSelected += 1;
			String^ cardName = card->getName();
			onVirtualPlayerSelectedCard(cardIndex, cardName);
		}
	}
	// Advance the game state.
	this->gameState->nextState();
}

bool GameEngine::virtualPlayerSelectedAllCards()
{
	return this->virtualPlayer->selectedAllCards();
}

void GameEngine::virtualPlayerPlayCard()
{
	// Simulate the virtual player thinking process.
	virtualPlayerThinks();

	// If the virtual player played all cards.
	if (!this->virtualPlayer->hasCards())
	{
		// Advance the game state.
		this->gameState->nextState();
		// Return.
		return;
	}

	// Infinite loop. Exit when virtual player selected a card to play.
	while (true)
	{
		// Get a random card index from the virtual player card set.
		int cardIndex = this->virtualPlayer->selectCardIndex(0, this->virtualPlayer->getMaxCardsCount());
		// Get the card to play.
		Card^ card = this->virtualPlayer->getCardAt(cardIndex);

		// If the card is not played or stolen.
		if (card != nullptr)
		{
			// Play the card.
			this->virtualPlayer->playCard(cardIndex);
			String^ cardName = card->getName();
			onVirtualPlayerPlayedCard(cardIndex, cardName);
			onScoreChanged(this->virtualPlayer->getScore(), this->player->getScore());
			// Exit the infinite loop.
			break;
		}
	}

	// Advance the game state.
	this->gameState->nextState();
}

bool GameEngine::virtualPlayerHasCards()
{
	return this->virtualPlayer->hasCards();
}

bool GameEngine::isLastVirtualPlayerPlayedCardSteal()
{
	return this->virtualPlayer->isLastPlayedCardSteal();
}

void GameEngine::virtualPlayerStealCard()
{
	// Simulate the virtual player thinking process.
	virtualPlayerThinks();

	// Infinite loop. Exit when virtual player steals a card from the player.
	while (true)
	{
		// Get a random card index from the player card set.
		int cardIndex = this->virtualPlayer->selectCardIndex(0, this->player->getMaxCardsCount());
		// Get the card to steal from the player.
		Card^ card = this->player->getCardAt(cardIndex);

		// If the card is not played or stolen.
		if (card != nullptr)
		{
			// Remove card from the player card set.
			this->player->removeCardAt(cardIndex);
			// Add card to the virtual player card set.
			int newCardIndex = this->virtualPlayer->insertCard(card);
			// Shuffle the virtual player card set to prevent the player from knowing where the stolen card is.
			array<bool>^ virtualPlayerCards = this->virtualPlayer->shuffleCards();
			onVirtualPlayerStoleCard(cardIndex, virtualPlayerCards, card->getName());

			// Advance the game state.
			this->gameState->nextState();

			// Exit the infinite loop.
			break;
		}
	}
}

void GameEngine::raiseGameFinished()
{
	this->onGameFinished();
}

bool GameEngine::areAllCardsPlayed()
{
	return !(this->player->hasCards() || this->virtualPlayer->hasCards());
}

bool GameEngine::isGameUnderway()
{
	return this->gameState->isGameUnderway();
}

int GameEngine::getVirtualPlayerSpeed()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	return gameSettings->getVirtualPlayerSpeed();
}

void GameEngine::setVirtualPlayerSpeed(int virtualPlayerSpeed)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setVirtualPlayerSpeed(virtualPlayerSpeed);
}

String^ GameEngine::getThemeColour()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	return gameSettings->getThemeColour();
}

void GameEngine::setThemeColour(String^ themeColour)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setThemeColour(themeColour);
}

int GameEngine::getMinusCardCount(int power)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	return gameSettings->getMinusCardCount(power);
}

void GameEngine::setMinusCardCount(int power, int cardCount)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setMinusCardCount(power, cardCount);
}

int GameEngine::getPlusCardCount(int power)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	return gameSettings->getPlusCardCount(power);
}

void GameEngine::setPlusCardCount(int power, int cardCount)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setPlusCardCount(power, cardCount);
}

int GameEngine::getCardStealCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	return gameSettings->getCardStealCount();
}

void GameEngine::setCardStealCount(int cardCount)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setCardStealCount(cardCount);
}

int GameEngine::getCardDoubleCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	return gameSettings->getCardDoubleCount();
}

void GameEngine::setCardDoubleCount(int cardCount)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setCardDoubleCount(cardCount);
}

int GameEngine::getCardChangeCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	return gameSettings->getCardChangeCount();
}

void GameEngine::setCardChangeCount(int cardCount)
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setCardChangeCount(cardCount);
}

void GameEngine::resetGameSettings()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
}

void GameEngine::saveGameSettings()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->saveGameSettings();
}
