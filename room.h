#ifndef ROOM_H
#define ROOM_H

#define MAX_ITEMS 10

typedef struct Room {
    char* description;             // Odanın açıklaması
    char* items[MAX_ITEMS];        // Odada bulunan eşyalar
    int itemCount;                 // Odadaki eşya sayısı
    char* creature;                // Odadaki yaratık
    int creatureHealth;            // Canavarın canı
    struct Room* north;            // Kuzeye bağlantı
    struct Room* south;            // Güneye bağlantı
    struct Room* east;             // Doğuya bağlantı
    struct Room* west;             // Batıya bağlantı
} Room;

// Fonksiyon prototipleri
void createRoom(Room* room, const char* description);
void addRoomItem(Room* room, const char* item);

void describeRoom(Room* room);
void addCreature(Room* room, const char* creature, int health);
void linkRooms(Room* room1, Room* room2, char direction);
void freeRoom(Room* room);
void printRoomConnections(Room* room);

#endif



