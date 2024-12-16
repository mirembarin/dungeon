# dungeon

# Dungeon Adventure Game

Bu, C dilinde yazılmış komut satırı tabanlı bir macera oyunudur. Oyuncular, zindanlarda dolaşır, eşya toplar, yaratıklarla savaşır ve oyunu kaydedip yükleyebilirler. Oyun, oyunculara çeşitli odalar arasında gezinme, yaratıklarla mücadele etme ve gizemli eşyaları toplama fırsatı sunar.

## Özellikler

- **Odanın Tanımı**: Her odanın benzersiz bir açıklaması vardır.
- **Yaratıklarla Savaş**: Odalardaki yaratıklara karşı savaşabilirsiniz.
- **Envanter Yönetimi**: Oda içindeki eşyaları toplayabilir ve envanterinizi yönetebilirsiniz.
- **Oyun Kaydetme ve Yükleme**: Oyun durumunu kaydedebilir ve ilerlemenizi kaydedilen dosyadan yükleyebilirsiniz.
- **Odalar Arası Hareket**: Farklı odalar arasında yönlendirme yapabilirsiniz.

## Kurulum

### Gerekli Araçlar

- **gcc** derleyicisi.
- **make** komutu (proje derlemek için).

### Adımlar:

1. **Proje klasörüne gidin**:
   ```bash
   cd ~/Desktop/dungeon

2.Projeyi derlemek için:   
make

3. projeyi çalıştırmak için:

./dungeon


Örnek Oyun Senaryosu:

Komutunuzu girin: look
Oda: Taş duvarlarla çevrili karanlık bir oda.
Odada bulunan eşyalar:
  - Altın Anahtar
Odada bir yaratık var: Kurt

Komutunuzu girin: attack
'Kurt' canavarına saldırıyorsunuz!
Canavar 10 hasar aldı. Kalan can: 20

Komutunuzu girin: pickup Altın Anahtar
'Altın Anahtar' envantere eklendi.


Proje Yapısı
dungeon/
├── main.c        # Ana oyun döngüsünün bulunduğu dosya
├── player.c      # Oyuncu özelliklerini yöneten dosya
├── player.h      # Oyuncu yapısı ve fonksiyon prototipleri
├── room.c        # Oda özelliklerini yöneten dosya
├── room.h        # Oda yapısı ve fonksiyon prototipleri
├── game.c        # Oyun kaydetme ve yükleme fonksiyonları
├── game.h        # Kaydetme/yükleme fonksiyon prototipleri
└── Makefile      # Derleme komutlarını içeren dosya












