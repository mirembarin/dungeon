#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"

// Odayı oluştur
void createRoom(Room* room, const char* description) {
    room->description = malloc(strlen(description) + 1);
    if (room->description == NULL) {
        printf("Bellek tahsisi hatası!\n");
        exit(1);  // Hata durumunda çıkmak için
    }
    strcpy(room->description, description);
    room->itemCount = 0;

    // Eşyaları boş başlat
    for (int i = 0; i < MAX_ITEMS; i++) {
        room->items[i] = NULL;
    }
    
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    room->creature = NULL; // Yaratık başlangıçta yok
    room->creatureHealth = 0; // Yaratık sağlığı
}

// Odaya eşya ekle
void addRoomItem(Room* room, const char* item) {
    if (room->itemCount >= MAX_ITEMS) {
        printf("Odada daha fazla eşya bulunamaz! '%s' eklenemedi.\n", item);
        return;
    }

    // Eşya ekleme
    room->items[room->itemCount] = malloc(strlen(item) + 1);
    if (room->items[room->itemCount] == NULL) {
        printf("Bellek tahsisi hatası!\n");
        return;
    }
    strcpy(room->items[room->itemCount], item);
    room->itemCount++;
    printf("Odada '%s' eklendi.\n", item);
}

// Odayı tanımla
void describeRoom(Room* room) {
    printf("Oda: %s\n", room->description);

    if (room->itemCount == 0) {
        printf("Odada eşya yok.\n");
    } else {
        printf("Odada bulunan eşyalar:\n");
        for (int i = 0; i < room->itemCount; i++) {
            printf("  - %s\n", room->items[i]);
        }
    }

    if (room->creature != NULL) {
        printf("Odada bir yaratık var: %s\n", room->creature);
    }
}

// Odanın eşyalarını serbest bırak
void freeRoomItems(Room* room) {
    for (int i = 0; i < room->itemCount; i++) {
        free(room->items[i]);  // Belleği serbest bırak
    }
    room->itemCount = 0;  // Odanın eşya sayısını sıfırla
}

// Yaratığı ekle
void addCreature(Room* room, const char* creature, int health) {
    room->creature = malloc(strlen(creature) + 1); // Bellek tahsisi
    if (room->creature == NULL) {
        printf("Bellek tahsisi hatası!\n");
        return;
    }
    strcpy(room->creature, creature);              // Yaratık ismini ata
    room->creatureHealth = health;                // Yaratığın canını ata
    printf("Odada '%s' belirdi (%d can).\n", creature, health);
}

// Odaları birbirine bağla
void linkRooms(Room* room1, Room* room2, char direction) {
    if (direction == 'n') {
        room1->north = room2;
        room2->south = room1;
    } else if (direction == 's') {
        room1->south = room2;
        room2->north = room1;
    } else if (direction == 'e') {
        room1->east = room2;
        room2->west = room1;
    } else if (direction == 'w') {
        room1->west = room2;
        room2->east = room1;
    }
}

// Odanın belleğini temizle
void freeRoom(Room* room) {
    free(room->description); // Oda açıklaması
    freeRoomItems(room);     // Eşyaları serbest bırak

    // Yaratık ve yaratık adı için bellek serbest bırakma
    if (room->creature != NULL) {
        free(room->creature);
        room->creature = NULL;
    }

    // Bağlantıları sıfırlama
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
}

