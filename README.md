# DnD-Virtual-CardGame
### GOALS
A program that simulates spell cards for a DnD 5e game with the use of the D&D 5e API

### Essential knowledge
-The application can be called like this:
```
Usage:   SpellCards.exe spell-card-files [-s count-list] [-l level] [-h history-file]
Options:
    -s count-list        Spell slots available, the list is a sequential number of spells slots of each level that is available to the player
    -l level             Level of character
    -h history-file      Optional history file for all used spells during play
```
```
Example: SpellCards.exe -s 4 3 2 -l 5 fireball.json locate-object.json counterspell.json shatter.json invisibility.json blur.json identify.json vicious-mockery.json -h history.log
```
-After loading in the spell cards, a player can circulate through his list of cards, with every card showing its own statistics. \
-Information can be requested through queries \
```
~/SpellCards$ The following queries are available:
              View spell list: Returns a list of all the available spells
              spell-name  [-at attack_type] [-ct casting_time] [-cl classes] [-co components] 
                          [-de description] [-du duration] [-r range] ...
```
-A player can choose to cast a spell card, depending on the players level. \
-If a player spell slot has been used or is no longe accesible by the player. Give the player a list of cards he can choose from, and add a suggestion for the spell slot. \
-If no level is provided the highest level spell is used.
```
~/SpellCards$ cast spell-name [-l spell-slot-level]
```
-If spell slot history is provided through the cli then all the available spell slots aswell as the used ones should be logged.(the format is free of choice) \
###example
```
~/SpellCards$ cast fireball -l 5
              A 5th level spell slot is not available. Do you want to use a 4th spell slot?
              The list of available spell slots is:
              * 1st level: 2
              * 2nd level: 1
              * 3th level: 0
              * 4th level: 1
              * 5th level: 0﻿﻿
```
- [ ] Gebruiken van juiste structuren
- [ ] De gegevens worden juist bewaard in de juiste members van de structuren
- [ ] Gebruik van pointers is steeds van het juiste type
- [ ] Pointers worden juist gebruikt bij parameters van functies (o.a. call-by-reference)
- [ ] Geheugen wordt juist en efficiënt gealloceerd
- [ ] Geen memory leaks, geheugen wordt steeds juist opgeruimd
- [ ] Er wordt correct gebruikgemaakt van de arguments to main (input en output files via flags)
- [ ] De structuur voor een linked list is juist en efficiënt voorzien
- [ ] Functies zijn voorzien om push, pop and cycle te doen op de circulaire linked list
- [ ] Bewaren van gemaakte keuzes in geschiedenisbestand m.b.v. file handling 
- [ ] Parse de json data van het bestand naar de voorziene gegevensstructuur
- [ ] Het geheel maakt gebruik van het ingeladen bestand en speelbaar deel te maken die spell slots bijhoudt
- [ ] Het geheel werk volledig zonder crashen
- [ ] Wekelijkse nuttige commit op GitHub (min. 5)
- [ ] Een mooie extra eens de rest werkt (zie de lijst hieronder) :
- [ ] correcte documentatie a.d.h.v. flowchart (zie miro)
- [ ] getopt() gebruiken
- [ ] url meegeven en inladen via netwerk-code
