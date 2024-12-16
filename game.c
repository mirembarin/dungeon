#include "game.h"
#include "player.h"
#include "room.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Oyunu kaydet
void saveGame(const char* fileName, Player* player, Room* currentRoom) {
    FILE* file = fopen(fileName, "w");  // Dosyayı yazma modunda aç
    if (file == NULL) {
        printf("Dosya açılamadı: %s\n", fileName);
        return;
    }

    // Oyuncunun sağlık durumu ve envanteri
    fprintf(file, "Player Health: %d\n", player->health);
    fprintf(file, "Player Strength: %d\n", player->strength);
    fprintf(file, "Inventory Count: %d\n", player->inventoryCount);
    for (int i = 0; i < player->inventoryCount; i++) {
        fprintf(file, "Item: %s\n", player->inventory[i]);
    }

    // Mevcut oda bilgileri
    fprintf(file, "Current Room: %s\n", currentRoom->description);
    if (currentRoom->creature != NULL) {
        fprintf(file, "Creature: %s\n", currentRoom->creature);
        fprintf(file, "Creature Health: %d\n", currentRoom->creatureHealth);
    } else {
        fprintf(file, "Creature: None\n");
    }

    fclose(file);  // Dosyayı kapat
    printf("Oyun başarıyla '%s' dosyasına kaydedildi.\n", fileName);
}

// Oyunu yükle
void loadGame(const char* fileName, Player* player, Room* currentRoom) {
    FILE* file = fopen(fileName, "r");  // Dosyayı okuma modunda aç
    if (file == NULL) {
        printf("Dosya açılamadı: %s\n", fileName);
        return;
    }

    // Oyuncunun sağlık durumu ve envanteri
    fscanf(file, "Player Health: %d\n", &player->health);
    fscanf(file, "Player Strength: %d\n", &player->strength);
    fscanf(file, "Inventory Count: %d\n", &player->inventoryCount);

    for (int i = 0; i < player->inventoryCount; i++) {
        player->inventory[i] = malloc(50);  // Bellek tahsisi
        fscanf(file, "Item: %49[^\n]\n", player->inventory[i]);
    }

    // Mevcut oda bilgileri
    char roomDescription[100];
    fscanf(file, "Current Room: %[^\n]\n", roomDescription);
    currentRoom->description = strdup(roomDescription);

    char creatureName[50];
    fscanf(file, "Creature: %[^\n]\n", creatureName);
    if (strcmp(creatureName, "None") != 0) {
        currentRoom->creature = strdup(creatureName);

        int creatureHealth;
        fscanf(file, "Creature Health: %d\n", &creatureHealth);
        currentRoom->creatureHealth = creatureHealth;
    } else {
        currentRoom->creature = NULL;
        currentRoom->creatureHealth = 0;
    }

    fclose(file);  // Dosyayı kapat
    printf("Oyun başarıyla '%s' dosyasından yüklendi.\n", fileName);
}

