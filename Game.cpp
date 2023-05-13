/***********************************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Adrian Maldonado
 ** Email:   amaldon1@umbc.edu
 ** Date     4/9/2023
 ** Section: 11
 ** This file contains the definition cpp file of the Game class
 **********************************************************/
#include "Game.h"

// Name: Game() - Default Constructor
// Description: Creates a new Game and populates money, round, and health
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
// including rounds played
Game::Game()
{
    m_curRound = START_ROUND;
    m_curLife = START_LIFE;
    m_curMoney = START_MONEY;
}

// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game()
{
    // Sets the size of the monkey and bloon vector to their variable counters
    int monkeyCounter = m_monkeys.size();
    int bloonCounter = m_bloons.size();
    // Loops through all the monkeys in the vector and deallocates them
    for (int monkey = 0; monkey < monkeyCounter; monkey++)
    {
        delete m_monkeys.at(monkey);
    }
    // Loops through all the bloons in the vector and deallocates them
    for (int bloon = 0; bloon < bloonCounter; bloon++)
    {
        delete m_bloons.at(bloon);
    }
}

// Name: PrintMap()
// Description: For each location on the path, outputs the bloons and the monkeys (or none)
// Precondition: None
// Postcondition: None
void Game::PrintMap()
{
    // Sets the size of the monkey and bloon vector to their variable counters
    int monkeyCounter = m_monkeys.size();
    int bloonCounter = m_bloons.size();
    // Loops through everything on the path
    for (int path = 1; path < PATH_LENGTH + 1; path++)
    {
        // Initalize the count of monkeys and bloons for each location in order to check if any exist
        int monkeyPathCount = 0;
        int bloonPathCount = 0;
        // Prints out the location and monkeys
        cout << "\n**Location " << path << "**\n--Monkeys--" << endl;
        // If the monkey counter (vector) has nothing then it will print none
        if (monkeyCounter <= 0)
        {
            cout << "None" << endl;
        }
        else
        {
            // Goes through all the monkeys in the vector and if their path matches it prints them
            for (int monkeys = 1; monkeys < monkeyCounter + 1; monkeys++)
            {
                if (m_monkeys.at(monkeys - 1)->GetLocation() == path)
                {
                    monkeyPathCount++;
                    cout << monkeys << ". " << *m_monkeys.at(monkeys - 1) << endl;
                }
            }
            // Checks if there were any monkeys in that location, if not then prints none
            if (monkeyPathCount == 0)
            {
                cout << "None" << endl;
            }
        }
        // Prints out the location and bloons
        cout << "<<Bloons>>" << endl;
        // If the bloon counter (vector) has nothing then it will print none
        if (bloonCounter <= 0)
        {
            cout << "None" << endl;
        }
        else
        {
            // Goes through all the bloons in the vector and if their path matches it prints them
            for (int bloons = 1; bloons < bloonCounter + 1; bloons++)
            {
                if (m_bloons.at(bloons - 1)->GetLocation() == path)
                {
                    bloonPathCount++;
                    cout << *m_bloons.at(bloons - 1) << endl;
                }
            }
            // Checks if there were any bloons in that location, if not then prints none
            if (bloonPathCount == 0)
            {
                cout << "None" << endl;
            }
        }
    }
    cout << endl;
}

// Name: ImproveMonkey
// Description: Asks the user which monkey they would like to improve
//              Increases chosen monkey's damage by IMPROVE_VALUE above
// Precondition: Must have monkeys in m_monkeys and have enough money to pay (COST_IMPROVE)
// Postcondition: Monkey's damage is permanently improved
void Game::ImproveMonkey()
{
    // Sets the size of the monkey vector to monkey counter and initalize choice
    int monkeyCounter = m_monkeys.size();
    int choice = 0;
    // If there are no monkeys in m_monkeys, nothing happens
    if (monkeyCounter <= 0)
    {
        cout << "No monkeys to improve." << endl;
        return;
    }
    // If there is not enough money to pay for improvements
    if (m_curMoney < COST_IMPROVE)
    {
        cout << "You have insufficient funds!" << endl;
        return;
    }
    // Constantly asks the user for their choice until it is valid
    do
    {
        // Asks the user for their choice of all the monkeys to improve in the vector
        cout << "Which monkey would you like to improve (1-" << monkeyCounter << ")" << endl;
        // Goes through all the monkeys in the vector and if their path matches it prints them
        for (int monkeys = 1; monkeys < monkeyCounter + 1; monkeys++)
        {
            cout << monkeys << ". " << *m_monkeys.at(monkeys - 1) << endl;
        }
        // Takes in choice if it's invalid then it restarts the loop
        cin >> choice;
        if ((choice <= 0) || (choice > monkeyCounter))
        {
            cout << "Invalid input." << endl;
        }
        // If the choice is valid, increase the chosen monkey's damage by IMPROVE_VALUE and decrease the money
        else
        {
            m_curMoney -= COST_IMPROVE;
            m_monkeys.at(choice - 1)->SetDamage(IMPROVE_VALUE);
            cout << m_monkeys.at(choice - 1)->GetType() << " in position " << choice << " improved!" << endl;
            return;
        }
    } while ((choice <= 0) || (choice > monkeyCounter));
}

// Name: BuyMonkey
// Description: Asks the user which monkey they would like to buy
//            Reduces m_curMoney and then calls PlaceMonkey (which creates and places new monkey)
// Precondition: Must have enough money to pay (COST_DART, COST_BOOMERANG, or COST_BOMB)
// Postcondition: Specified monkey is added a chosen location on the path
void Game::BuyMonkey()
{
    // Prompt the user to buy a monkey
    cout << "What type of monkey would you like to buy?\n1. Dart Monkey\n2. Boomerang Monkey\n3. Bomb Monkey\n4. Cancel" << endl;
    // Initialize choice variable and takes input from user
    int choice = 0;
    cin >> choice;
    // Checks the user's choice
    switch (choice)
    {
    // If they chose a dart monkey
    case 1:
        // Checks the user's money to see if they can afford to buy a dart monkey
        if (m_curMoney < COST_DART)
        {
            cout << "You have insufficient funds!" << endl;
            return;
        }
        // Removes cost of dart monkey from total money and sends the choice to PlaceMonkey
        else
        {
            m_curMoney -= COST_DART;
            PlaceMonkey(choice);
        }
        break;
    // If they chose a boomerang monkey
    case 2:
        // Checks the user's money to see if they can afford to buy a boomerang monkey
        if (m_curMoney < COST_BOOMERANG)
        {
            cout << "You have insufficient funds!" << endl;
            return;
        }
        // Removes cost of boomerang monkey from total money and sends the choice to PlaceMonkey
        else
        {
            m_curMoney -= COST_BOOMERANG;
            PlaceMonkey(choice);
        }
        break;
    // If they chose a bomb monkey
    case 3:
        // Checks the user's money to see if they can afford to buy a bomb monkey
        if (m_curMoney < COST_BOMB)
        {
            cout << "You have insufficient funds!" << endl;
            return;
        }
        // Removes cost of bomb monkey from total money and sends the choice to PlaceMonkey
        else
        {
            m_curMoney -= COST_BOMB;
            PlaceMonkey(choice);
        }
        break;
    // If they cancel the purchase
    case 4:
        cout << "You cancelled." << endl;
        break;
    // If they use invalid integers on the menu
    default:
        cout << "Invalid input." << endl;
        break;
    }
}

// Name: PlaceMonkey(int choice)
// Description: Based on monkey purchased in BuyMonkey, asks user where to place new monkey
//              Dynamically allocates new monkey and populates location and adds to m_monkey
// Preconditions: Successfully purchased new monkey
// Postconditions: New monkey is added to m_monkey at chosen location
void Game::PlaceMonkey(int choice)
{
    // Initializes the path choice for the monkey
    int pathChoice = 0;
    // This do while makes sure that the path choice is valid
    do
    {
        cout << "Where would you like to place the new monkey? (1-" << PATH_LENGTH << ")" << endl;
        cin >> pathChoice;
        // If the path choice is not valid, below 1 and above the path's length
        if (pathChoice < 1 || pathChoice > PATH_LENGTH)
        {
            cout << "Invalid input." << endl;
        }
    } while (pathChoice < 1 || pathChoice > PATH_LENGTH);
    // Takes the choice and makes the new monkey
    // If they chose a dart monkey
    if (choice == 1)
    {
        // Makes the new monkey and adds it to m_monkeys vector
        Monkey *newMonkey = new Dart("Dart", DAMAGE_DART, pathChoice);
        m_monkeys.push_back(newMonkey);
        cout << "New dart monkey placed in location " << pathChoice << endl;
    }
    // If they chose a boomerang monkey
    else if (choice == 2)
    {
        // Makes the new monkey and adds it to m_monkeys vector
        Monkey *newMonkey = new Boomerang("Boomerang", DAMAGE_BOOM, pathChoice);
        m_monkeys.push_back(newMonkey);
        cout << "New boomerang monkey placed in location " << pathChoice << endl;
    }
    // If they chose a bomb monkey
    else if (choice == 3)
    {
        // Makes the new monkey and adds it to m_monkeys vector
        Monkey *newMonkey = new Bomb("Bomb", DAMAGE_BOMB, pathChoice);
        m_monkeys.push_back(newMonkey);
        cout << "New bomb monkey placed in location " << pathChoice << endl;
    }
    // If they somehow manage to bypass the first validation check
    return;
}

// Name: StartGame()
// Description: Welcomes the player to the game. Continually calls MainMenu until user quits
// Preconditions: None
// Postconditions: Thanks user when quitting
void Game::StartGame()
{
    // Gets the user's choice and calls MainMenu in a while loop until user quits by typing 6
    int choice;
    cout << "Welcome to UMBC Bloons!" << endl;
    do
    {
        choice = MainMenu();
    } while (choice != 6);
    cout << "Thanks for playing!" << endl;
}

// Name: MainMenu()
// Description: Checks to see if player still has life. If m_curLife <= 0, game ends with loss.
//              Display menu (View Map, Buy New Monkey, Improve Existing Monkey
//              Progress Round, Check Stats, or Quit).
//              Calls function related to user choice.
// Preconditions: None
// Postconditions: Game continues until quit or player runs out of life
int Game::MainMenu()
{
    // Initalizes choice but if the health is 0 or less, it returns 5, meaning game ends with loss
    int choice;
    if (m_curLife <= 0)
    {
        cout << "Sorry, you have lost the game." << endl;
        choice = 6;
        return choice;
    }
    // Gets the user's choice and displays the menu
    cout << "What would you like to do?\n1. View Map\n2. Buy New Monkey\n3. Improve Existing Monkey\n4. Progress Round\n5. Check Stats\n6. Quit" << endl;
    cin >> choice;
    // Goes through switch statement and calls appropriate function based on user choice
    switch (choice)
    {
    case 1:
        PrintMap();
        return choice;
        break;
    case 2:
        BuyMonkey();
        return choice;
        break;
    case 3:
        ImproveMonkey();
        return choice;
        break;
    case 4:
        PlayRound();
        return choice;
        break;
    case 5:
        Stats();
        return choice;
        break;
    // If the user inputs 6, the game ends
    case 6:
        return choice;
        break;
    // If the user inputs invalid choice (not between 1-5), returns -1
    default:
        cout << "Invalid choice." << endl;
        return -1;
        break;
    }
}

// Name: Stats()
// Description: Displays the information about the game
//              (current round, number of monkeys, money, and lives left)
// Preconditions: None
// Postconditions: None
void Game::Stats()
{
    // Prints the statistics of the game
    int monkeys = m_monkeys.size();
    cout << "**CURRENT STATS**\nCurrent Round: " << m_curRound << "\nMonkeys Working: " << monkeys << "\nCurrent Money: " << m_curMoney << "\nCurrent Life: " << m_curLife << endl;
}

// Name: PlayRound()
// Description: Announces beginning and end of round
//              Calls PopulateBloons once then ResolveBattle once.
//              Calls RemovePopped (5 times due to erase function)
//              Calls MoveBloons once then calls CheckPath (5 times due to erase call)
//              Increments curRound
// Preconditions: None
// Postconditions: Round progresses
void Game::PlayRound()
{
    // Starts the round by adding bloons to the path
    cout << "Starting Round " << m_curRound << endl;
    PopulateBloons();
    // Begins monkey attack on bloons
    ResolveBattle();
    // Checks if any bloons have no health and removes them
    for (int i = 0; i < 5; i++)
    {
        RemovePopped();
    }
    // Moves the bloons down the path
    MoveBloons();
    // Checks if any bloons have made it to the end of the path
    for (int i = 0; i < 5; i++)
    {
        CheckPath();
    }
    // End the round by incrementing curRound, and this round is complete
    cout << "Round " << m_curRound << " Completed" << endl;
    m_curRound++;
}

// Name: PopulateBloons
// Description: Each round, dynamically allocated bloons added to path in position START_BLOON
//              Bloons have a minimum of 1 health.
//              For each round, the number of new bloons increases matching the round number
//              For example: Round 1 = 1 red bloon (health 1)
//              Round 2 = 1 red bloon (health 1) and 1 blue bloon (health 2)
//              Round 3 = 1 red (health 1) and 1 blue (health 2) and 1 green (health 3)
//              Round 4 = 1 red, 1 blue, 1 green, and 1 yellow (health 4) and so forth
//              Notifies user that a new bloon (with color) has appeared.
// Preconditions: Round is at least 1
// Postconditions: All new bloons populated
void Game::PopulateBloons()
{
    // Loops through each round and adds bloon to path proportional to the rounds that have passed
    for (int i = 0; i < m_curRound; i++)
    {
        // Makes a dynamic pointer to a bloon and adds it to the vector
        Bloon *newBloon = new Basic(i + 1, START_BLOON);
        cout << "A new " << newBloon->GetColor() << " bloon appears!" << endl;
        m_bloons.push_back(newBloon);
    }
    // If it is round 12 or more it makes zebra bloons
    if (m_curRound >= 12)
    {
        for (int i = 12; i <= m_curRound; i++)
        {
            // Makes a dynamic pointer to a bloon and adds it to the vector
            Bloon *newBloon = new Zebra(ZEBRA_HEALTH, START_BLOON);
            cout << "A new " << newBloon->GetColor() << " bloon appears!" << endl;
            m_bloons.push_back(newBloon);
        }
    }
    // If it is round 10 or more it makes lead bloons
    if (m_curRound >= 10)
    {
        for (int i = 10; i <= m_curRound; i++)
        {
            // Makes a dynamic pointer to a bloon and adds it to the vector
            Bloon *newBloon = new Lead(LEAD_HEALTH, START_BLOON);
            cout << "A new " << newBloon->GetColor() << " bloon appears!" << endl;
            m_bloons.push_back(newBloon);
        }
    }
}

// Name: ResolveBattle()
// Description: Each monkey attacks the whole bloon vector.
//              For each pop, curMoney is increased.
// Preconditions: Monkeys and bloons exist
// Postconditions: Damage is dealt to bloons
void Game::ResolveBattle()
{
    // Sets the size of the monkey vector to monkey counter
    int monkeyCounter = m_monkeys.size();
    // Set the money counter that will be gained from the damage done by the monkey
    int moneyCounter = 0;
    // Loops through all the monkeys in m_monkeys vector
    for (int i = 0; i < monkeyCounter; i++)
    {
        // A monkey attacks bloons from the vector and damage is dealt and added to the money
        moneyCounter += m_monkeys.at(i)->Attack(m_bloons);
        m_curMoney += moneyCounter;
    }
}

// Name: RemovePopped()
// Description: Iterates through m_bloons and if health is <= 0, bloon is deallocated and
//              removed from m_bloons
//         HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed
void Game::RemovePopped()
{
    // Loops through all the bloons in m_bloons vector
    for (int i = 0; i < (int)m_bloons.size(); i++)
    {
        // If the bloon's health is equal or less than 0, deletes bloon from path (vector)
        if (m_bloons.at(i)->GetHealth() <= 0)
        {
            if (m_bloons.at(i)->GetColor() == ZEBRA)
            {
                // When a zebra is killed, it splits into two black bloons
                cout << "The zebra bloon split into two black bloons!" << endl;
                Bloon *newBloon = new Basic(SPLIT_HEALTH, m_bloons.at(i)->GetLocation());
                m_bloons.push_back(newBloon);
                Bloon *newBloon2 = new Basic(SPLIT_HEALTH, m_bloons.at(i)->GetLocation());
                m_bloons.push_back(newBloon2);
            }
            if (m_bloons.at(i)->GetColor() == LEAD)
            {
                // When a lead is killed, it splits into one black bloon
                cout << "The lead bloon split into a black bloon!" << endl;
                Bloon *newBloon = new Basic(SPLIT_HEALTH, m_bloons.at(i)->GetLocation());
                m_bloons.push_back(newBloon);
            }
            cout << "The bloon is now gone!" << endl;
            delete m_bloons.at(i);
            m_bloons.erase(m_bloons.begin() + i);
        }
    }
}

// Name: MoveBloons
// Description: For each bloon that still lives, it moves one location down the path
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons increment their location
void Game::MoveBloons()
{
    // Sets the size of the bloon vector to bloon counter and initializes current bloon location
    int bloonCounter = m_bloons.size();
    // Loops through all the bloons in m_bloons vector
    for (int i = 0; i < bloonCounter; i++)
    {
        // If the bloon's location is at the start move it up currBloonLocation + 2
        if (m_bloons.at(i)->GetLocation() == -1)
        {
            m_bloons.at(i)->SetLocation(2);
        }
        // Sets the location of the bloon to currBloonLocation + 1
        else
        {
            m_bloons.at(i)->SetLocation(1);
        }
    }
    cout << "The bloons move along the path" << endl;
}

// Name: CheckPath
// Description: Iterates over m_bloons to see if location is equal to (or greater than)
//              PATH_LENGTH. If location is equal to PATH_LENGTH, causes damage to player.
//              Damage to player is one per health of bloon.
//              If 10 green bloons (health 3) hit player, player takes 30 damage
//              Bloons that hurt player are deallocated and erased from m_bloons
//              HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed
void Game::CheckPath()
{
    // Loops through all the bloons in m_bloons vector
    for (int i = 0; i < (int)m_bloons.size(); i++)
    {
        // If the bloon's location is equal or greater than PATH_LENGTH, causes damage to player and deletes bloon
        if (m_bloons.at(i)->GetLocation() >= PATH_LENGTH + 1)
        {
            // If a lead bloon makes it to the end of the path and you take damage
            if (m_bloons.at(i)->GetColor() == LEAD)
            {
                cout << "A bloon made it to the end of the path and you took " << LEAD_DAMAGE << " damage." << endl;
                // Damage to the player depends on the health of the bloon
                m_curLife -= LEAD_DAMAGE;
            }
            // If a zebra bloon makes it to the end of the path and you take damage
            else if (m_bloons.at(i)->GetColor() == ZEBRA)
            {
                cout << "A bloon made it to the end of the path and you took " << ZEBRA_DAMAGE << " damage." << endl;
                // Damage to the player depends on the health of the bloon
                m_curLife -= ZEBRA_DAMAGE;
            }
            // If a basic bloon makes it to the end of the path and you take damage
            else
            {
                cout << "A bloon made it to the end of the path and you took " << m_bloons.at(i)->GetHealth() << " damage." << endl;
                // Damage to the player depends on the health of the bloon
                m_curLife -= m_bloons.at(i)->GetHealth();
            }
            // If the bloon does make it to the end, it is deleted
            delete m_bloons.at(i);
            m_bloons.erase(m_bloons.begin() + i);
        }
    }
}

/*
vector<Bloon *> m_bloons;    Vector for holding all bloons in game
vector<Monkey *> m_monkeys;  Vector for holding all monkeys in game
int m_curRound;              Tracks number of rounds played in game
int m_curMoney;              Tracks current money for upgrades
int m_curLife;               Tracks current life. When 0, game over.
*/