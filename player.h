#ifndef PLAYER_H
#define PLAYER_H

#define INVENTORY_SIZE 5  // Envanter kapasitesi

// Oyuncu yapısı
typedef struct {
    int health;
    int strength;
    char* inventory[INVENTORY_SIZE];
    int inventoryCount;
} Player;

// Fonksiyon prototipleri
void createPlayer(Player* player);
void addItem(Player* player, const char* item);
void listInventory(Player* player);
void freeInventory(Player* player);
#endif

