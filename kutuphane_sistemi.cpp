#include "Kullanici.h"
#include "Kitap.h"
#include "Admin.h"
#include "Helper.h"
#include "Dosya.h"
#include "KitapService.h"
#include "KitapKontrol.h"
#include "KullaniciService.h"
#include "KullaniciKontrol.h"
#include "Input.h"
#include "AnaMenu.h"
#include "UyeMenu.h"
#include "AdminMenu.h"
#include "AdminInput.h"

#include <clocale>

int main()
{
	vector<Kullanici> kullanicilar;
	vector<Admin> admin_x;
	vector<Kitap> kitaplar;
	vector<string> oduncAlinanKitaplar;
	vector<time_t> kitapAlinmaTarihleri;

	setlocale(LC_ALL, "Turkish");

	dosyadanOku(kullanicilar);
	kitapDosyadanOku(kitaplar);
	AnaMenu(kullanicilar, kitaplar);

	return 0;
}


