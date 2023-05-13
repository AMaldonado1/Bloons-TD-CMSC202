/***********************************************************
 ** File:    Lead.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Date     4/17/2023
 ** Section: 11
 ** This file contains the definition cpp file of the Lead class
 **********************************************************/
#include "Lead.h"

// Name: Lead() - Default Constructor
// Description: Creates a new Lead Bloon
// Preconditions: None
// Postconditions: Can create a Lead Bloon
Lead::Lead() : Bloon()
{
    m_color = "lead";
}

// Name: Lead(int health, int location)
// Description: Creates a new Lead bloon with health at a specific location
// Preconditions: None
// Postconditions: Can create a Lead bloon
Lead::Lead(int health, int location) : Bloon(health, location)
{
    m_color = "lead";
}

// Name: ~Basic - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Lead::~Lead()
{
}

// Name: Pop
// Description: Once a Lead bloon has been damaged, it splits into one basic bloon with 10 health
// Preconditions: None
// Postconditions: Returns 1 if still alive, returns 0 if health <= 0
int Lead::Pop(int damage)
{
    // Gets the current health of the bloon, removes health from the bloon based on the damage and sets the new health
    int bloonHealthBefore = GetHealth();
    bloonHealthBefore -= damage;
    SetHealth(bloonHealthBefore);
    // Gets the new health of the bloon, and tests if it is still alive
    cout << "The " << GetColor() << " bloon is hit!" << endl;
    int bloonHealthAfter = GetHealth();
    // If the bloon has no health left, return 0
    if (bloonHealthAfter <= 0)
    {
        cout << "It's armour was removed and it is now vulnerable to all damage!" << endl;
        return 0;
    }
    // If it does have health left, return 1
    else
    {
        cout << "It was unaffected by the damage!" << endl;
        return 1;
    }
}

// Name: GetColor()
// Description: Returns the current color of a bloon
// Preconditions: None
// Postconditions: None
string Lead::GetColor()
{
    return m_color;
}