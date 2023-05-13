/***********************************************************
 ** File:    Zebra.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Email:   amaldon1@umbc.edu
 ** Date     4/17/2023
 ** Section: 11
 ** This file contains the definition cpp file of the Zebra class
 **********************************************************/
#include "Zebra.h"

// Name: Zebra() - Default Constructor
// Description: Creates a new Zebra Bloon
// Preconditions: None
// Postconditions: Can create a Zebra Bloon
Zebra::Zebra() : Bloon()
{
    m_color = "zebra";
}

// Name: Zebra(int health, int location)
// Description: Creates a new Zebra bloon with health at a specific location
// Preconditions: None
// Postconditions: Can create a Zebra bloon
Zebra::Zebra(int health, int location) : Bloon(health, location)
{
    m_color = "zebra";
}

// Name: ~Basic - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Zebra::~Zebra()
{
}

// Name: Pop
// Description: Once a zebra bloon has been damaged, it splits into two basic bloons each with 10 health
// Preconditions: None
// Postconditions: Returns 1 if still alive, returns 0 if health <= 0
int Zebra::Pop(int damage)
{
    // Gets the current health of the bloon, removes health from the bloon based on the damage and sets the new health
    int bloonHealthBefore = GetHealth();
    bloonHealthBefore -= damage;
    SetHealth(bloonHealthBefore);
    // Gets the new health of the bloon, and tests if it is still alive
    cout << "The " << GetColor() << " bloon pops!" << endl;
    int bloonHealthAfter = GetHealth();
    // If the bloon has no health left, return 0
    if (bloonHealthAfter <= 0)
    {
        return 0;
    }
    // If it does have health left, return 1
    else
    {
        return 1;
    }
}

// Name: GetColor()
// Description: Returns the current color of a bloon
// Preconditions: None
// Postconditions: None
string Zebra::GetColor()
{
    return m_color;
}