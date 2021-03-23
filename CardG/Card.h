#pragma once

using namespace System;

// Specifies card type.
enum class CardType : int {
	// Plus card type.
	Plus, 
	// Minus card type.
	Minus, 
	// Steal card type.
	Steal,
	// Double card type.
	Double, 
	// Change card type.
	Change};

ref class Card
{
protected:
	// The type of the card.
	CardType type;
	
	// The power of the card.
	int power;
	
	// The name of the card.
	String^ name;

	// Represents a card.
	//   cardType: The type of the card.
	//   power: The power of the card.
	Card(CardType cardType, int power);

public:
	// Gets the type of the card.
	CardType getType();
	
	// Gets the power of the card.
	int getPower();
	
	// Gets the name of the card.
	String^ getName();
};

