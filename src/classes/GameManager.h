#pragma once

#include "Dungeon.h"
#include "Monster.h"
#include "Player.h"
#include "Spell.h"

enum GameState {
   D20,
   D10_ENEMY,
   D10_PLAYER,
   D8,
   DEAD,
   WIN,
};

class GameManager {
  private:
   static const int DUNGEON_COUNT = 20;

   static Player player;
   static Dungeon* activeDungeon;
   static LinkedList<Dungeon> dungeonList;
   static LinkedList<Monster> monsterList;
   static LinkedList<Spell> spellList;

   static GameState gameState;

  public:
   static void startNewGame(string name, string race);

   static Dungeon getDungeonAtIndex(int index);
   static void generateMap();

   static int moveToRandomDungeon();
   static int playerAttack();
   static int enemyAttack();
   static int recoverPlayerLP();
   static Spell useItem(int itemIndex);

   static Dungeon* getActiveDungeon();

   static void setGameState(GameState state);

   static GameState getGameState();

   static Player getPlayer();
   static int getPlayerHp();
   static int getPlayerLp();

   static LinkedList<Monster> getMonsterList();
   static void addMonsterToList(Monster monster);

   static LinkedList<Spell> getItemList();
   static void addItemToList(Spell spell);
};
