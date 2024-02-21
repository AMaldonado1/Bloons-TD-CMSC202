/***********************************************************
 ** File:    Basic.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Email:   amaldon1@umbc.edu
 ** Date     4/9/2023
 ** Section: 11
 ** This file contains the definition cpp file of the Basic class and extra test
 **********************************************************/
#include "Basic.h"

// Name: Basic() - Default Constructor
// Description: Creates a new Basic Bloon
// Preconditions: None
// Postconditions: Can create a Basic Bloon
Basic::Basic() : Bloon()
{
    m_color = "none";
}

// Name: Basic(int health, int location)
// Description: Creates a new basic bloon with health at a specific location
// if health = 1, red, 2=blue, 3=green, 4=yellow, 5=pink, >=6=black
// Preconditions: None
// Postconditions: Can create a basic bloon
Basic::Basic(int health, int location) : Bloon(health, location)
{
    // Set the color of the bloon based on the health
    switch (health - 1)
    {
    case red:
        m_color = "red";
        break;
    case blue:
        m_color = "blue";
        break;
    case green:
        m_color = "green";
        break;
    case yellow:
        m_color = "yellow";
        break;
    case pink:
        m_color = "pink";
        break;
    case black:
        m_color = "black";
        break;
    default:
        m_color = "black";
        break;
    }
}

// Name: ~Basic - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Basic::~Basic()
{
}

// Name: Pop
// Description: Changes the color of the bloon based on how many health it has left
// red = 1, blue = 2, green = 3, yellow = 4, pink = 5, black >=6
// Preconditions: None
// Postconditions: Returns 1 if still alive, returns 0 if health <= 0
int Basic::Pop(int damage)
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
    // If the bloon has health left, changes the color of the bloon, and returns 1
    else
    {
        switch (bloonHealthAfter - 1)
        {
        case red:
            cout << "The bloon is now red." << endl;
            m_color = "red";
            break;
        case blue:
            cout << "The bloon is now blue." << endl;
            m_color = "blue";
            break;
        case green:
            cout << "The bloon is now green." << endl;
            m_color = "green";
            break;
        case yellow:
            cout << "The bloon is now yellow." << endl;
            m_color = "yellow";
            break;
        case pink:
            cout << "The bloon is now pink." << endl;
            m_color = "pink";
            break;
        case black:
            cout << "The bloon is now black." << endl;
            m_color = "black";
            break;
        default:
            cout << "The bloon is now black." << endl;
            m_color = "black";
            break;
        }
        return 1;
    }
}

// Name: GetColor()
// Description: Returns the current color of a bloon
// Preconditions: None
// Postconditions: None
string Basic::GetColor()
{
    return m_color;
}

/*
string m_color;
*/