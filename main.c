#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "room.h"
#include "main.h"
#include "game.h"

Room* currentRoom;

int main(void) {
    Player player;
    Room room1, room2;
    char command[100];

    // Oyuncu ve odaları oluştur
    createPlayer(&player);

    // İlk oda
    createRoom(&room1, "Taş duvarlarla çevrili karanlık bir oda.");
    addRoomItem(&room1, "Altın Anahtar");
    addCreature(&room1, "Kurt", 30);

    // İkinci oda
    createRoom(&room2, "Ateş ışığıyla aydınlanan büyük bir oda.");
    addRoomItem(&room2, "Eski Harita");
    addCreature(&room2, "Trol", 50);

    // Odaları bağla
    linkRooms(&room1, &room2, 'n');

    // Oyuncunun başlangıç odasını ayarla
    currentRoom = &room1;

    // Oyun başlangıcı
    printf("Macera oyununa hoş geldiniz!\n");
    printf("Komutlar: 'look', 'inventory', 'pickup <item>', 'attack', 'move <direction>', 'save <file>', 'load <file>', 'exit'\n");

    // Oyun döngüsü
    while (1) {
        printf("\nKomutunuzu girin: ");
        fgets(command, sizeof(command), stdin);

        // Komuttaki yeni satır karakterini kaldır
        command[strcspn(command, "\n")] = '\0';

        // Komutları işleyin
        processCommand(command, &player, &currentRoom);
    }

    return 0;
}

// Fonksiyon tanımları
void attack(Room* room, Player* player) {
    if (room->creature == NULL) {
        printf("Bu odada saldıracak bir canavar yok.\n");
        return;
    }

    printf("'%s' canavarına saldırıyorsunuz!\n", room->creature);
    room->creatureHealth -= player->strength; // Oyuncunun gücü kadar hasar ver
    printf("Canavar %d hasar aldı. Kalan can: %d\n", player->strength, room->creatureHealth);

    if (room->creatureHealth <= 0) {
        printf("Canavarı öldürdünüz!\n");
        free(room->creature); // Belleği serbest bırak
        room->creature = NULL;
        room->creatureHealth = 0;
    } else {
        printf("Canavar hâlâ hayatta. Dikkatli olun!\n");
    }
}

void processCommand(const char* command, Player* player, Room** currentRoom) {
    if (strcmp(command, "look") == 0) {
        describeRoom(*currentRoom);
    } else if (strcmp(command, "inventory") == 0) {
        listInventory(player);
    } else if (strncmp(command, "pickup ", 7) == 0) {
        char itemName[50];
        sscanf(command + 7, "%49[^\n]", itemName);
        pickupItem(itemName, player, *currentRoom); // 'pickup' komutunu işle
    } else if (strcmp(command, "attack") == 0) {
        attack(*currentRoom, player); // 'attack' komutunu işle
    } else if (strncmp(command, "move ", 5) == 0) {
        movePlayer(command + 5, currentRoom); // 'move' komutunu işle
    } else if (strncmp(command, "save ", 5) == 0) {
        saveGame(command + 5, player, *currentRoom); // 'save' komutunu işle
    } else if (strncmp(command, "load ", 5) == 0) {
        loadGame(command + 5, player, *currentRoom); // 'load' komutunu işle
    } else if (strcmp(command, "exit") == 0) {
        printf("Oyun sonlandırılıyor...\n");
        exit(0);
    } else {
        printf("Bilinmeyen komut: %s\n", command);
    }
}

void movePlayer(const char* direction, Room** currentRoom) {
    Room* nextRoom = NULL;

    if (strcmp(direction, "north") == 0) nextRoom = (*currentRoom)->north;
    else if (strcmp(direction, "south") == 0) nextRoom = (*currentRoom)->south;
    else if (strcmp(direction, "east") == 0) nextRoom = (*currentRoom)->east;
    else if (strcmp(direction, "west") == 0) nextRoom = (*currentRoom)->west;

    if (nextRoom == NULL) {
        printf("Bu yönde bir oda yok!\n");
    } else {
        *currentRoom = nextRoom;
        printf("Yeni bir odaya geçtiniz: %s\n", nextRoom->description);
        describeRoom(*currentRoom);
    }
}

void pickupItem(const char* itemName, Player* player, Room* room) {
    int found = 0;
    for (int i = 0; i < room->itemCount; i++) {
        if (strcmp(room->items[i], itemName) == 0) {
            addItem(player, room->items[i]);
            free(room->items[i]); // Belleği serbest bırak
            room->items[i] = room->items[room->itemCount - 1]; // Son öğeyi bu konuma taşı
            room->items[room->itemCount - 1] = NULL;
            room->itemCount--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Odada '%s' bulunamadı.\n", itemName);
    }
}


