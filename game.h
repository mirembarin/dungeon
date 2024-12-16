
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"

void saveGame(const char* fileName, Player* player, Room* currentRoom);
void loadGame(const char* fileName, Player* player, Room* currentRoom);
void movePlayer(const char* direction, Room** currentRoom);

#endif

