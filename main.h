#ifndef MAIN_H
#define MAIN_H
#include "player.h"
#include "room.h"


void createPlayer(Player* player);
void addItem(Player* player, const char* item);
void listInventory(Player* player);
void createRoom(Room* room, const char* description);
void addRoomItem(Room* room, const char* item);
void describeRoom(Room* room);
void freeRoomItems(Room* room);
void movePlayer(const char* direction, Room** currentRoom);
void saveGame(const char* fileName, Player* player, Room* currentRoom);
void loadGame(const char* fileName, Player* player, Room* currentRoom);
extern Room* currentRoom;
void attack(Room* room, Player* player);
void processCommand(const char* command, Player* player, Room** currentRoom);
void pickupItem(const char* itemName, Player* player, Room* room); 


#endif



