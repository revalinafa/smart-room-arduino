<h1 align="center"> Smart Room Berbasis Arduino Uno </h1>

<p align="center">
Sistem ruangan pintar dengan fitur otomatis & manual berbasis mikrokontroler
</p>

<p align="center">
<img width="1536" height="1024" alt="banner" src="https://github.com/user-attachments/assets/5a3afa29-be77-4a7a-9358-78228a6674d7" />

</p>



## Anggota Kelompok 1
- Athaya Raihan Annafi — H1D023001  
- Ratu Naurah Calista — H1D023004  
- Ariza Nola Rufiana — H1D023005  
- Rafif Surya Murtadha — H1D023008  
- Revalina Fidiya Anugrah — H1D023011  



##  Deskripsi Project
Project ini merupakan sistem **Smart Room berbasis Arduino Uno** yang mampu mengontrol lampu, kipas, dan alarm secara otomatis maupun manual.

Sistem bekerja dengan membaca data dari sensor, kemudian diproses oleh Arduino untuk menghasilkan aksi seperti menyalakan lampu, mengaktifkan kipas, serta memberikan peringatan jika terdeteksi gas berbahaya.



## Struktur Repository

```
smart-room-arduino/
│
├── README.md
├── LICENSE (optional)
│
├── /code
│   └── smart_home.ino
│
├── /documentation
│   ├── laporan.pdf
│   ├── flowchart.png
│   ├── diagram_blok.png
│   ├── wiring_diagram.png
│   ├── Schematic View Kelompok 1_Smart Room.pdf
│   ├── Component List.csv
│   ├── banner.png
│
├── /simulation
│   ├── link_tinkercad.txt
│   ├── link_youtube.txt
│
```



##  Fitur Sistem

| Fitur | Deskripsi |
|------|----------|
| 💡 Lampu Otomatis | Menyala saat gelap (LDR) |
| 🌡️ Kipas Otomatis | Aktif saat suhu tinggi (TMP36) |
| 🚨 Alarm Gas | Buzzer aktif saat gas berbahaya |
| 🔄 Mode Manual | Kontrol via push button |
| 🖥️ LCD | Monitoring real-time |
| ⚡ Interrupt | Pergantian mode cepat |



## Konsep yang Digunakan

| Konsep | Implementasi |
|-------|-------------|
| Percabangan | if-else |
| Perulangan | loop() |
| GPIO | Input & Output |
| ADC | Sensor analog |
| PWM | Kontrol motor |
| I2C | LCD |
| Interrupt | Mode switch |


## Komponen
Arduino Uno, LDR, TMP36, Sensor Gas, LCD I2C, Motor DC, Buzzer, LED, Push Button, Transistor, Resistor.


## Cara Kerja
Sensor → Arduino → Output aktif sesuai kondisi → ditampilkan di LCD.



## 🔗 Link Simulasi
🔗Link : https://www.tinkercad.com/things/27LdxauL5ch-smartroom?sharecode=J2Z_Fh3xIrIaM04F8W9tuFMAYUTp43Jx52KVDvwXjVw

## 🎥 Video Demo
🔗Link : https://youtu.be/fzk8j-MujXI



## Mata Kuliah
Pemrograman Sistem Tertanam - Kelas A
