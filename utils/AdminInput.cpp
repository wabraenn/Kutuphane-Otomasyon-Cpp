#include "Helper.h"
#include "Admin.h"
#include "AdminInput.h"

#include <iostream>

using namespace std;

//----admin kullanici adi alma fonksiyonu----//
unsigned long long adminKullaniciAdiAl() {
    string kullaniciAdi;

    do {
        cout << "Kullanıcı Adını Giriniz: ";
        cin >> kullaniciAdi;

        if (kullaniciAdi.length() != 6 || !sadeceRakamMi(kullaniciAdi)) {
            cout << "HATALI KULLANICI ADI! Sadece 6 haneli rakam giriniz.\n";
        }

    } while (kullaniciAdi.length() != 6 || !sadeceRakamMi(kullaniciAdi));

    return stoull(kullaniciAdi);
}

//----admin sifre alma fonksiyonu----//
string adminSifreAl() {
    string sifre;

    cout << "ŞİFRENİZİ GİRİNİZ: ";

    do {
        cin >> sifre;

        if (sifre.length() != 4) {
            cout << "HATALI ŞİFRE! Şifreniz 4 haneli olmalıdır.\nTekrar giriniz: ";
        }
        else if (!sadeceRakamMi(sifre)) {
            cout << "HATALI! Şifre sadece rakamlardan oluşmalıdır.\nTekrar giriniz: ";
        }

    } while (sifre.length() != 4 || !sadeceRakamMi(sifre));

    return sifre;
}

//----Admin Giriş Fonksiyonu----//
int adminLogin() {
    Admin adminGiris;
    int hak = 3;

    while (hak > 0) {
        unsigned long long ad = adminKullaniciAdiAl();
        string sifre = adminSifreAl();

        if (adminGirisKontrol(adminGiris, ad, sifre)) {
            cout << "Admin girisi basarili!\n";
            return 1;   // ✅ BURASI ÖNEMLİ
        }
        else {
            hak--;
            cout << "Hatali giris! Kalan hak: " << hak << "\n";
        }
    }

    cout << "3 kez hatali giris yapildi. Cikis yapiliyor...\n";
    return 0;
    // buradan ya ana menüye dönersin ya da program biter

}

//----admin sifre ve kullanici adi kontrol fonksiyonu----//
bool adminGirisKontrol(const Admin& admin, unsigned long long kullaniciAdi, const string& sifre) {
    return (admin.kullaniciAdi == kullaniciAdi && admin.adminSifre == sifre);
}
