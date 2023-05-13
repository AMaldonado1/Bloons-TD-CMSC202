/***********************************************************
 ** File:    Dart.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Email:   amaldon1@umbc.edu
 ** Date     4/9/2023
 ** Section: 11
 ** This file contains the definition cpp file of the Dart class
 **********************************************************/
#include "Dart.h"

// Name: Dart() - Default Constructor
// Description: Creates a new Dart Monkey
// Preconditions: None
// Postconditions: Can create a Dart Monkey
Dart::Dart() : Monkey()
{
}

// Name: Dart(string type, int damage, int location)
// Description: Creates a new Dart Monkey
// Preconditions: None
// Postconditions: Can create a Dart Monkey
Dart::Dart(string type, int damage, int location) : Monkey(type, damage, location)
{
}

// Name: ~Dart - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Dart::~Dart()
{
}

// Name: Attack
// Description: Iterates through all bloons. Hits first bloon in the same location as dart.
//              Returns total bloon health or damage (whichever is less) for earnings (money)
// Preconditions: Bloon must be in same location as Dart monkey
// Postconditions: Damages one bloon and returns earnings (total pops)
int Dart::Attack(vector<Bloon *> bloonsVector)
{
    // Cash gained will be based on damage dealt
    int cashDamage = 0;
    // Sets the total amount of bloons in the path (vector) to a variable
    int bloonCounter = bloonsVector.size();
    // Loops through all bloons in the path (vector)
    for (int i = 0; i < bloonCounter; i++)
    {
        // Initialize variables of the bloon's and monkey's location
        int bloonLocation = bloonsVector.at(i)->GetLocation();
        int monkeyLocation = GetLocation();
        // Check to see if the bloon is in the same location as the monkey
        if (bloonLocation == monkeyLocation)
        {
            // Gets the i-th bloon's current health
            int bloonHealth = bloonsVector.at(i)->GetHealth();
            // Removes the i-th bloon's health based on how much damage it has taken
            cout << "The dart monkey throws a dart!" << endl;
            // Sets the i-th bloon's health to the new health
            if (bloonsVector.at(i)->GetColor() == "lead")
            {
                // Does no damage to lead bloons
                bloonsVector.at(i)->Pop(0);
                return cashDamage;
            }
            else
            {
                bloonsVector.at(i)->Pop(GetDamage());
                // In order to get money, returning either the health or the damage, it will be which ever is less
                if (bloonHealth < GetDamage())
                {
                    // If the bloon's health is less than the damage, return the health (like overkilling the bloon)
                    return cashDamage += bloonHealth;
                }
                else
                {
                    // If the bloon's health is greater than the damage, return the damage, bloon is still alive
                    return cashDamage += GetDamage();
                }
            }
        }
    }
    return cashDamage;
}
