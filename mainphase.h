#include <stdio.h>
#include "ride.h"
#include "customer.h"
#include "prioqueue.h"
#include "mesinkata.h"
#include "listlinier.h"
#include "peta.h"

#ifndef MAINPHASE_H
#define MAINPHASE_H


extern Queue Antrean;
extern boolean quitmain;
extern int timer;

void mainphase();
/* Fungsi utama di main phase */
/* I.S. Preparation phase sudah dilewati, elemen2 wahana sudah terdefinisi/teralokasi */
/* F.S. Mainphase dijalankan sekali */

void Serve(Queue *Q, Ride *R);
/* I.S. Q dan R terdefinisi
   F.S. Customer dari Q dipindahkan ke RideSeat(*R), uang bertambah */
   
void UpdatePrio(Customer *C);
   
void CekAntrean(Queue *Q, long time);
   
void UpdateSeat(Ride *R, long time);
/* Setiap durasi customer di wahana R dikurangi agar sinkron dengan waktu game */
/* I.S. R terdefinisi
   F.S. Setiap customer di wahana R (jika ada) dikurangi durasinya */

void CekSeat(Ride *R);
/* I.S. R terdefinisi
   F.S. Jika customer pertama (yang datang paling awal) pada wahana R sudah habis durasinya, maka akan dikeluarkan.
        Jika terdapat wahana lain yang dipesan, maka akan kembali ke antrean
        Jika wahananya sudah dilayani semua, maka akan dikeluarkan dari taman bermain */

void Broke(Ride *R);
/* Wahana Rusak */
/* I.S. R terdefinisi
   F.S. Pengunjung yang sedang bermain wahana akan dikembalikan ke antrian dengan prioritas yang lebih tinggi */

void Repair (Ride *R);
/* I.S. R terdefinisi
   F.S. Wahana Rusak diperbaiki */

void SetBroke(Ride *R, long time);

void Detail(Ride R);

void Report(Ride R);

#endif
