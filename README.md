# DnD-Virtual-CardGame
### GOALS
A program that simulates the inventory(list of equipment cards) for a D&D 5e game
### Essential knowledge
-The following text snippet demonstrates how the application can be called using the CLI:
```
Usage:   Inventory.exe equipment-files [number-of-items] [-w max-weight] [-m money] [-c camp-file]
Options:
    number-of-items      Optional per file to define the number in the inventory﻿
    -w max-weight        Maximum weight before becoming encumbered
    -m money             List of coins and types (cp, sp, ep, gp, pp)
    -c camp-file         Optional camp file for all discovered items during play that stay in camp
 
Example: Inventory.exe -w 180.75 -m 4gp 42sp 69cp greatsword.json explorers-pack.json small-knife.json 2 waterskin.json leather-armor.json -c camp.log
```
### Application functionality
Highlights the fundamental functionality imposed by the teacher for a passing grade.
```
 * abbility to load in the cards
 * user-controlled card iteration 
 * the ability to request more information about a given card. 
 * abbility to move said card to the users camp.
 * abbility to calculate and display the coin value
 * abbility to calculate the weight
 * abbility to show the users emcumbered status.
```
### Evaluation criteria
- [ ] Gebruiken van juiste structuren
- [ ] De gegevens worden juist bewaard in de juiste members van de structuren
- [ ] Gebruik van pointers is steeds van het juiste type
- [ ] Pointers worden juist gebruikt bij parameters van functies (o.a. call-by-reference)
- [ ] Geheugen wordt juist en efficiënt gealloceerd
- [ ] Geen memory leaks, geheugen wordt steeds juist opgeruimd
- [ ] Er wordt correct gebruikgemaakt van de arguments to main (input en output files via flags)
- [ ] De structuur voor een linked list is juist en efficiënt voorzien
- [ ] Functies zijn voorzien om push, pop and cycle te doen op de circulaire linked list
- [ ] Bewaren van gemaakte keuzes in bestand m.b.v. file handling 
- [ ] Parse de json data van het bestand naar de voorziene gegevensstructuur
- [ ] Het geheel maakt gebruik van het ingeladen bestand en speelbaar deel te maken die spell slots bijhoudt
- [ ] Het geheel werk volledig zonder crashen
- [ ] Wekelijkse nuttige commit op GitHub (min. 5)

#### Een mooie extra eens de rest werkt (zie de lijst hieronder) :
- [ ] correcte documentatie a.d.h.v. flowchart (zie miro)
- [ ] getopt() gebruiken
- [ ] url meegeven en inladen via netwerk-code
