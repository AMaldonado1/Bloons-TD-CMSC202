/***********************************************************
 ** File:    Zebra.h
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Date     4/17/2023
 ** Section: 11
 ** This file contains the header file of the Zebra class
 **********************************************************/
#ifndef ZEBRA_H_
#define ZEBRA_H_

#include "Bloon.h"

// Zebra bloons split into two basic bloons (black with health of 10 each) once damaged

class Zebra : public Bloon
{
public:
    // Name: Zebra() - Default Constructor
    // Description: Creates a new Zebra Bloon
    // Preconditions: None
    // Postconditions: Can create a Zebra Bloon
    Zebra();
    // Name: Zebra(int health, int location)
    // Description: Creates a new Zebra bloon with health at a specific location
    // Preconditions: None
    // Postconditions: Can create a Zebra bloon
    Zebra(int, int);
    // Name: ~Zebra - Virtual Destructor
    // Description: Makes sure everything in child class is deallocated
    // Preconditions: None
    // Postconditions: Everything dynamically allocated is deallocated
    ~Zebra();
    // Name: Pop
    // Description: Once a zebra bloon has been damaged, it splits into two basic bloons each with 10 health
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
