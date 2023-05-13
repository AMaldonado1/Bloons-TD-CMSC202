/***********************************************************
 ** File:    Bloon.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Email:   amaldon1@umbc.edu
 ** Date     4/9/2023
 ** Section: 11
 ** This file contains the definition cpp file of the Bloon class
 **********************************************************/
#include "Bloon.h"

// Name: Bloon() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (may not be specifically used)
Bloon::Bloon()
{
  m_health = 0;
  m_location = 0;
}

// Name: Bloon(int health, int location) - Overloaded Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes
Bloon::Bloon(int health, int location)
{
  m_health = health;
  m_location = location;
}

// Name: virtual ~Bloon - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Bloon::~Bloon()
{
}

// Name: GetHealth()
// Description: Returns health of bloon
// Preconditions: Bloon has health
// Postconditions: None
int Bloon::GetHealth()
{
  return m_health;
}

// Name: SetHealth()
// Description: Sets health of bloon
// Preconditions: None
// Postconditions: Health is set
void Bloon::SetHealth(int health)
{
  m_health = health;
}

// Name: GetLocation()
// Description: Returns location of bloon
// Preconditions: Bloon has location
// Postconditions: None
int Bloon::GetLocation()
{
  return m_location;
}

// Name: SetLocation()
// Description: Sets location of bloon
// Preconditions: None
// Postconditions: Location is set
void Bloon::SetLocation(int location)
{
  m_location += location;
}

// Name: Overloaded <<
// Description: Prints the details of an bloon
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of bloon
ostream &operator<<(ostream &output, Bloon &bloon)
{
  // Outputs type and health of the bloon
  output << "Bloon: " << bloon.GetColor() << " Health: " << bloon.GetHealth();
  return output;
}

/*
  int m_health; //Health of bloon
  int m_location; //Location of bloon on track
*/
