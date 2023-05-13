/***********************************************************
 ** File:    Lead.h
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Date     4/17/2023
 ** Section: 11
 ** This file contains the header file of the Lead class
 **********************************************************/
#ifndef LEAD_H_
#define LEAD_H_

#include "Bloon.h"

// Lead bloons can only be hurt by bomb and split to a basic bloon (black with health of 10) once damaged

class Lead : public Bloon
{
public:
    // Name: Lead() - Default Constructor
    // Description: Creates a new Lead Bloon
    // Preconditions: None
    // Postconditions: Can create a Lead Bloon
    Lead();
    // Name: Lead(int health, int location)
    // Description: Creates a new Lead bloon with health at a specific location
    // Preconditions: None
    // Postconditions: Can create a Lead bloon
    Lead(int, int);
    // Name: ~Basic - Virtual Destructor
    // Description: Makes sure everything in child class is deallocated
    // Preconditions: None
    // Postconditions: Everything dynamically allocated is deallocated
    ~Lead();
    // Name: Pop
    // Description: Once a Lead bloon has been damaged, it splits into one basic bloon with 10 health
    // Preconditions: None
    // Postconditions: Returns 1 if still alive, returns 0 if health <= 0
    int Pop(int damage);
    // Name: GetColor()
    // Description: Returns the current color of a bloon
    // Preconditions: None
    // Postconditions: None
    string GetColor();

private:
    string m_color;
};
#endif
