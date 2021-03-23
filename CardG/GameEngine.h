#pragma once

#include "BaseGameEngine.h"
#include "Card.h"
#include "MinusCard.h"
#include "PlusCard.h"
#include "StealCard.h"
#include "DoubleCard.h"
#include "ChangeCard.h"
#include "CardDeck.h"
#include "GameState.h"
#include "NoGameState.h"
#include "DealPlayerState.h"
#include "Player.h"
#include "VirtualPlayer.h"
#include "GameSettings.h"
#include "FileLogger.h"

ref class GameEngine :
	public BaseGameEngine
{
private:
	// The game state.
	GameState^ gameState;

	// The card deck.
	CardDeck^ cardDeck;


	// The maximum number of cards in the player card set.
	int maxPlayerCardsCount;

	// The maximum number of cards in the virtual player set.
	int maxVirtualPlayerCardsCount;


	// The player.
	Player^ player;

	// The virtual player.
	VirtualPlayer^ virtualPlayer;


	// Initializes the card deck.
	void initCardDeck();


	// Simulates the thinking process for the virtual player.
	void virtualPlayerThinks();

	// Sends a notification when the game state changes.
	void sendNotification();

public:
	// Represents a game engine.
	//   playerName: The player name.
	GameEngine(String^ playerName);

	// Sets the game state.
	//   gameState: The game state to set.
	void setState(GameState^ gameState);

	// Starts a new game.
	//   canceled: the new game is canceled.
	void newGame(bool canceled);


	// Represents a reference to a method that handles the new game event.
	delegate void newGameEventHandler();

	// Occures when a new game is started.
	event newGameEventHandler^ onNewGame;	


	// Gets the maximum number of cards in the card deck.
	int getCardDeckMaxCardsCount();


	// Gets the player name.
	String^ getPlayerName();

	// Gets the maximum number of cards in the player card set.
	int getMaxPlayerCardsCount();

	// Gets the player score.
	int getPlayerScore();

	// Adds a card from the card deck to the player card set. Returns the card name of the card added to the player card set.
	//   cardIndex: The index of the card to be added from the card deck to the player card set.
	String^ addPlayerCard(int cardIndex);

	// Indicates whether the player selected all cards.
	bool playerSelectedAllCards();

	// Indicates whether there is the player turn.
	bool isPlayerTurn();

	// The player plays a card.
	//   cardIndex: The index of the card to play from the player card set.
	void playerPlaysCard(int cardIndex);

	// Indicates whether the player has cards in their card set.
	bool playerHasCards();

	// Indicates whether the last card played by the player is a Steal card.
	bool isLastPlayerPlayedCardSteal();

	// Indicates whether there is the player can steal a card.
	bool isPlayerSteal();

	// The player steals a card.
	//   cadIndex: The index of the card to steal from the virtual player card set.
	void playerStealsCard(int cardIndex);


	// Represents a reference to a method that handles the player selected card event.
	//   cardIndex: The index of the selected card.
	//   cardName: The name of the selected card.
	delegate void playerSelectedCardEventHandler(int cardIndex, String^ cardName);
	
	// Occures when the player selected a card.
	event playerSelectedCardEventHandler^ onPlayerSelectedCard;


	// Represents a reference to a method that handles the player played card event.
	//   cardIndex: The index of the played card.
	//   cardName: The name of the played card.
	delegate void playerPlayedCardEventHandler(int cardIndex, String^ cardName);
	
	// Occurs when the player played a card.
	event playerPlayedCardEventHandler^ onPlayerPlayedCard;


	// Represents a reference to a method that handles the player stole card event.
	//   virtualPlayerCardIndex: The index of the card stolen from the virtual player card set.
	//   playerCardIndex: The index of the stolen card in the player card set.
	//   cardName: The name of the stolen card.
	delegate void playerStoleCardEventHandler(int virtualPlayerCardIndex, int playerCardIndex, String^ cardName);
	
	// Occurs when the player stole a card.
	event playerStoleCardEventHandler^ onPlayerStoleCard;


	// Gets the virtual player name.
	String^ getVirtualPlayerName();

	// Gets the maximum number of cards in the virtual player card set.
	int getMaxVirtualPlayerCardsCount();

	// Gets the virtual player score.
	int getVirtualPlayerScore();

	// Selects the virtual player cards.
	void selectVirtualPlayerCards();

	// Indicates whether the player selected all cards.
	bool virtualPlayerSelectedAllCards();

	// Indicates whether there is the virtual player turn.
	void virtualPlayerPlayCard();

	// Indicates whether the virtual player has cards in their card set.
	bool virtualPlayerHasCards();

	// Indicates whether the last card played by the virtual player is a Steal card.
	bool isLastVirtualPlayerPlayedCardSteal();

	// The virtual player steals a card.
    //   cadIndex: The index of the card to steal from the player card set.
	void virtualPlayerStealCard();


	// Represents a reference to a method that handles the virtual player selected card event.
	//   cardIndex: The index of the selected card.
	//   cardName: The name of the selected card.
	delegate void virtualPlayerSelectedCardEventHandler(int cardIndex, String^ cardName);

	// Occurs when the virtual player selected a card.
	event virtualPlayerSelectedCardEventHandler^ onVirtualPlayerSelectedCard;


	// Represents a reference to a method that handles the virtual player played card event.
	//   cardIndex: The index of the played card.
	//   cardName: The name of the played card.
	delegate void virtualPlayerPlayedCardEventHandler(int cardIndex, String^ cardName);

	// Occurs when the virtual player played a card.
	event virtualPlayerPlayedCardEventHandler^ onVirtualPlayerPlayedCard;


	// Represents a reference to a method that handles the virtual player stole card event.
	//   virtualPlayerCardIndex: The index of the card stolen from the player card set.
	//   virtualPlayerCards: The indexes of the cards in the virtual player card set.
	//   cardName: The name of the stolen card.
	delegate void virtualPlayerStoleCardEventHandler(int playerCardIndex, array<bool>^ virtualPlayerCards, String^ cardName);
	
	// Occurs when the virtual player stole a card.
	event virtualPlayerStoleCardEventHandler^ onVirtualPlayerStoleCard;


	// Represents a reference to a method that handles the score changed event.
	//   virtualPlayerScore: The virtual player score.
	//   playerScore: The player score.
	delegate void scoreChangedEventHandler(int virtualPlayerScore, int playerScore);

	// Occurs when the game score changed.
	event scoreChangedEventHandler^ onScoreChanged;


	// Represents a reference to a method that handles the game state changed event.
	//   state: The game state.
	delegate void gameStateChangedEventHandler(String^ state);

	// Occurs when the game state changed.
	event gameStateChangedEventHandler^ onGameStateChanged;


	// Represents a reference to a method that handles the game finished event.
	delegate void gameFinishedEventHandler();

	// Occurs when the game finished.
	event gameFinishedEventHandler^ onGameFinished;


	// Raises the game finished event.
	void raiseGameFinished();

	// Indicates whether all cards are played.
	bool areAllCardsPlayed();

	// Indicates whether there is a game underway.
	bool isGameUnderway();


	// Gets the virtual player speed.
	int getVirtualPlayerSpeed();

	// Sets the virtual player speed.
	//   virtualPlayerSpeed: The virtual player speed to set.
	void setVirtualPlayerSpeed(int virtualPlayerSpeed);


	// Gets the theme colour.
	String^ getThemeColour();
	
	// Sets the theme colour.
	//   themeColour: The theme colour to set.
	void setThemeColour(String^ themeColour);


	// Gets the number of Minus cards with the given power in the cards deck.
	//   power: The power of the Minus card.
	int getMinusCardCount(int power);

	// Sets the number of Minus cards with the given power in the card deck.
	//   power: The power of the Minus card.
	//   cardCount: The number of Minus cards with the given power to set.
	void setMinusCardCount(int power, int cardCount);


	// Gets the number of Plus cards with the given power in the card deck.
	//   power: The power of the Plus card. 
	int getPlusCardCount(int power);

	// Sets the number of Plus cards with the given power in the card deck.
	//   power: The power of the Plus card.
	//   cardCount: The number of Plus cards with the given power to set.
	void setPlusCardCount(int power, int cardCount);


	// Gets the number of Steal cards in the card deck.
	int getCardStealCount();
	
	// Sets the number of Steal cards in the card deck.
	//   cardCount: The number of Steal cards.
	void setCardStealCount(int cardCount);


	// Gets the number of Double cards in the card deck.
	int getCardDoubleCount();

	// Sets the number of Double cards in the card deck.
	//   cardCount: The number of Double cards.
	void setCardDoubleCount(int cardCount);


	// Gets the number of Change cards in the card deck.
	int getCardChangeCount();

	// Sets the number of Change cards in the card deck.
	//   cardCount: The number of Change cards.
	void setCardChangeCount(int cardCount);


	// Resets the game settings to the default game settings.
	void resetGameSettings();

	// Saves the game settings.
	void saveGameSettings();
};

