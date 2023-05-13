/***********************************************************
 ** File:    Boomerang.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Email:   amaldon1@umbc.edu
 ** Date     4/9/2023
 ** Section: 11
 ** This file contains the definition cpp file of the Boomerang class
 **********************************************************/
#include "Boomerang.h"

// Name: Boomerang() - Default Constructor
// Description: Creates a new Boomerang Monkey
// Preconditions: None
// Postconditions: Can create a Boomerang Monkey
Boomerang::Boomerang() : Monkey()
{
}

// Name: Boomerang(string type, int damage, int location)
// Description: Creates a new Boomerang Monkey
// Preconditions: None
// Postconditions: Can create a Boomerang Monkey
Boomerang::Boomerang(string type, int damage, int location) : Monkey(type, damage, location)
{
}

// Name: ~Boomerang - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Boomerang::~Boomerang()
{
}

// Name: Attack
// Description: Iterates through all bloons. For each bloon in the same location as boomerang,
//              hits each bloon twice (once out and once back)
//              Returns total bloon health or damage (whichever is less) for earnings (money)
// Preconditions: Bloons must be in same location as Boomerang Monkey
// Postconditions: Damages each bloon and returns earnings (total pops)
int Boomerang::Attack(vector<Bloon *> bloonsVector)
{
    // Since the boomerang attacks all bloons in same location, it will add up all the cash from damage and returns total
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
            // Removes the i-th bloon's health based on how much damage it has taken times 2 since boomerang hits twice
            cout << "The boomerang monkey throws a boomerang!" << endl;
            // Sets the i-th bloon's health to the new health
            if (bloonsVector.at(i)->GetColor() == "lead")
            {
                // Does no damage to lead bloons
                bloonsVector.at(i)->Pop(0);
                cashDamage += 0;
            }
            else
            {
                bloonsVector.at(i)->Pop(GetDamage() + GetDamage());
                // In order to get money, returning either the health or the damage, it will be which ever is less
                if (bloonHealth < (GetDamage() + GetDamage()))
                {
                    // If the bloon's health is less than the damage, add the health (like overkilling the bloon)
                    cashDamage += bloonHealth;
                }
                else
                {
                    // If the bloon's health is greater than the damage, add the damage, bloon is still alive
                    cashDamage += (GetDamage() + GetDamage());
                }
            }
        }
    }
    return cashDamage;
}