#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

// Oyuncuyu başlat
void createPlayer(Player* player) {
    player->health = 100;
    player->strength = 10;
    player->inventoryCount = 0;

    // Envanteri boş başlat
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        player->inventory[i] = NULL;
    }
}

// Envantere eşya ekle
void addItem(Player* player, const char* item) {
    if (player->inventoryCount >= INVENTORY_SIZE) {
        printf("Envanter dolu! '%s' eklenemedi.\n", item);
        return;
    }

    // Eşya ekleme
    player->inventory[player->inventoryCount] = malloc(strlen(item) + 1);
    if (player->inventory[player->inventoryCount] == NULL) {
        printf("Bellek tahsisi hatası!\n");
        return;
    }
    strcpy(player->inventory[player->inventoryCount], item);
    player->inventoryCount++;
    printf("'%s' envantere eklendi.\n", item);
}

// Envanteri listele
void listInventory(Player* player) {
    printf("Envanter:\n");
    if (player->inventoryCount == 0) {
        printf("  - Envanter boş.\n");
    } else {
        for (int i = 0; i < player->inventoryCount; i++) {
            printf("  - %s\n", player->inventory[i]);
        }
    }
}

// Bellek temizleme: Envanterdeki tüm eşyaların belleklerini serbest bırak
void freePlayer(Player* player) {
    for (int i = 0; i < player->inventoryCount; i++) {
        free(player->inventory[i]);  // Her bir eşyayı serbest bırak
    }
    player->inventoryCount = 0;  // Envanteri sıfırla
    printf("Envanter temizlendi.\n");
}

