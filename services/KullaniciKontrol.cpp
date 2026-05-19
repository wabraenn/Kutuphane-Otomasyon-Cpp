
#include "KullaniciKontrol.h"

using namespace std;


//----Ayni tc var mi kontrol fonksiyonu----//
bool tcVarMi(const vector<Kullanici>& kullanicilar, unsigned long long tc) {
	for (int i = 0; i < kullanicilar.size(); i++) {
		if (kullanicilar[i].tcKimlik == tc) {
			return true;
		}
	}
	return false;
}
