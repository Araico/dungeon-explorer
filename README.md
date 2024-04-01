<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->

<a name="readme-top"></a>

<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Jose-AE/dungeon-explorer">
    <img src="https://static.thenounproject.com/png/4213462-200.png" alt="Logo" width="80" height="80">
  </a>
<h3 align="center">Dungeon Explorer</h3>

  <p align="center">
    Dungeon Explorer is a data-driven Dungeons and Dragons (D&D) companion application, featuring a dynamic creature codex, spell and skill management, interconnected dungeon mapping, player progression, and a versatile random encounter generator for an immersive gaming experience.
    
  </p>
</div>

<!-- ABOUT THE PROJECT -->

## About The Project

<img src="https://i.imgur.com/jJJ9cUT.png" />


Dungeon Explorer is a comprehensive data structures project designed to enhance the immersive experience of Dungeons and Dragons (D&D) role-playing games. Drawing inspiration from the intricate world of D&D, this project aims to create a versatile and efficient database system that organizes, manages, and retrieves game-related information, ensuring a seamless gaming experience for both players and Dungeon Masters.

**Key Features:**
- **Creature Codex:**
Develop a dynamic repository of creatures and monsters found in the D&D universe. Utilize a linked list to load a monster inventory, facilitating quick access for Dungeon Masters during encounters. Use the file: monsters.csv, where creature data includes:

  - name: name of the creature
  - cr: challenge rating, indicating the difficulty of defeating the creature
  - type: type of creature
  - size: size of creature, indicating the space it occupies
  - ac: armor class, indicating how difficult the creature is to hit
  - hp: hit points, indicating how much damage the creature can take before being defeated
  - align: provides a clue to the default behavior of the creature


**Spell and Skill Tome:**
Create a data structure to manage spells and skills, allowing players to customize and maintain unique spell and skill books for their characters. Implement an efficient search and filtering mechanism for quick spell selection during gameplay. Research 15 spells and skills that can be used, create an abstract data type to represent a spell and/or skill, and load them into a linked list for access.

**Dungeon Map and Location Tracking:**
Use linked list-based data structures to represent the game world, consisting of a series of sequentially interconnected dungeons. The maximum number of interconnected dungeons is 20, with each dungeon having a randomly selected monster from the creature codex.

**Player:**
Implement an abstract data type representing the player. A player has a hit point level that starts at 10 and increases after winning a battle in a dungeon, a race (elf, human, or dwarf), a name, life points (lp) that decrease or increase with a spell, starting at 100 points and reaching up to 999, and a list of defeated monsters.

**Random Encounter Generator:**
Implement a versatile random encounter generator using the following system:

- Load the creature codex.
- Load the dungeon map, assigning a random monster to each dungeon.
- Load your list of at least 15 spells and skills.
- The player has 100 points that can be deducted with a creature's attack and can be increased with a specific spell.
- While the player has life:
  - Roll a 20-sided die to reach a dungeon.
  - If the dungeon's creature is dead (based on its hit points), roll the die again. Otherwise, if the creature is alive, enter into combat.
  - While the player or the creature is alive:
  - The monster attacks, roll a 10-sided die to determine damage.
  - The player attacks, roll a 10-sided die to simulate damage dealt.
  - If the player survives, record the defeated monster.
  - The player can roll an 8-sided die to recover life points (lp).
  - The game ends when the player dies.
  - Upon completion, display a sorted list, by name, of the defeated monsters, including their name, race, and the number of conquered dungeons.


### Built With

<a href="https://cmake.org/" target="_blank" rel="noreferrer"> <img src="https://cmake.org/wp-content/uploads/2023/08/CMake-Mark.svg" alt="Typescript" width="40" height="40"/> </a>
<a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer"> <img src="https://camo.githubusercontent.com/a8917573a65206f0615f2addfef5c9f3a6586c0aa7d71500a732b26e506bbeff/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f312f31382f49534f5f432532422532425f4c6f676f2e737667" alt="c++" width="40" height="40"/> </a>
<a href="https://www.wxwidgets.org/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/bb/WxWidgets.svg/192px-WxWidgets.svg.png" alt="chakra ui" width="55" height="40"/> </a>




<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.


