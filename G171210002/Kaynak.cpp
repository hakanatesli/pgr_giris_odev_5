/************************************************************
**                   SAKARYA �N�VERS�TES�
**          B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**              B�LG�SAYAR M�HEND�SL��� B�L�M�
**                 PROGRAMLAMAYA G�R�� DERS�
**
**      �DEV NUMARASI....:5
**      ��RENC� ADI......:HAKAN ATE�L�
**      ��RENC� NUMARASI.:G171210002
**      DERS GRUBU.......:2/A
************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct kisi//bu yap�y� m��terileri olu�tururken bana kolayl�k sa�lamas� daha kolay ula�mak i�in olu�turdum. 
{
	string ad;
	string soyad;
	string TCno;
	int no;
}musteri;
struct mekan//bu yap�y� odalar� daha kolay eri�ip eleman eklemek i�in olu�turdum.
{
	int no;
	float fiyat;
}oda;
int main() {
	int secim = 1;
	int secim1 = 1;
	int secim2 = 1;
	int secim3 = 1;
	char devam;
	do//bu do while d�ng�s�n� e�er kullan�c� i�ini bitiridkten sonra ilk sayfaya gitmek istiyorsa 99 say�s�na bas�nca ilk sayfaya ula�t�rmak i�in olu�turdum.
	{
		//---------------------------------------------------------------------------------
		do//bu do while yap�s�n� e�er kullan�c� istenilen de�erler d���nda de�er girerse uyar� verip tekrar ayn� sayfaya d�nmek i�in olu�turduk.
		{
			if (secim != 1 && secim != 2 && secim != 3 && secim != 99)//e�er se�im istenilen gibi yap�lmazsa ekrana uyar� yaz�p tekrar ba�a d�nmemizi sa�lamak i�in if kulland�m.
			{
				system("cls");
				cout << "hatali secim" << endl;
				system("pause");
				system("cls");
			}
			cout << "Otel islemleri" << endl;
			cout << "------------------" << endl;
			cout << "1-Oda islemleri" << endl;
			cout << "2-Musteri islemleri" << endl;
			cout << "3-Oda kayit islemleri" << endl;
			cout << "99-Cikis" << endl;
			cout << "Seciminiz:";
			cin >> secim;
		} while (secim != 1 && secim != 2 && secim != 3 && secim != 99);
		//-----------------------------------------------------------------------------------
		if (secim == 99)//e�er kullan�c� i�lem yapmak istemeyip programdan ��kmak isterse if karar yap�s�yla sa�lad���m �ekilde 99 say�s�n� tu�layarak bu i�lemi ger�ekle�tirebilir.
			return 0;
		//-----------------------------------------------------------------------------------
		do//bu d�ng�y� her yapt��� i�lemden sonra �st men�ye ��kamas�n� sa�lamk i�in olu�turdum.
		{
			devam = 'h';
			if (secim == 1)//e�er kullan�c�n�n se�imi 1 olursa a�a��daki i�lemleri yapmas� i�in bu karar yap�s�n� kulland�m.
			{
				system("cls");
				do//oda ile alakal� i�lmelerden hangisini yapmak istedi�i ile alakal� men� olu�turdum e�er istenileni se�mezse hata verip tekrar g�sterilecek.
				{
					if (secim1 != 1 && secim1 != 2 && secim1 != 3 && secim1 != 99)//istenileni de�eri se�medi�i zaman hata yaz�s� verip tekrar ba�a d�nmek i�in kulland�m.
					{
						system("cls");
						cout << "hatal� secim" << endl;
						system("pause");
						system("cls");
					}
					cout << "Oda islemleri" << endl;
					cout << "------------------" << endl;
					cout << "1-Oda ekle" << endl;
					cout << "2-Oda sil" << endl;
					cout << "3-Odalari listele" << endl;
					cout << "99-ust menu" << endl;
					cout << "Seciminiz:";
					cin >> secim1;
				} while (secim1 != 1 && secim1 != 2 && secim1 != 3 && secim1 != 99);
				//-----------------------------------------------------------------------------------
				if (secim1 == 1)//e�er kullan�c� oda eklemek isteniyorsa 1 rakam�n� tu�lay�p s�ral� i�lemleri ger�ekle�tirecek.
				{
					ofstream dosyaYaz1("odalar.txt");
					do//e�er �st �ste oda eklemek istedi�imizde e harfi ile bu i�lemi yapmak i�in do while ile yapt�k.
					{
						system("cls");
						cout << "Oda no:";
						cin >> oda.no;
						cout << "Oda fiyati:";
						cin >> oda.fiyat;
						dosyaYaz1 << oda.no << " " << oda.fiyat << endl;
						cout << "yeni oda kaydi yapacak misiniz(e/h)(ust menu icin u)?";
						cin >> devam;
					} while (devam == 'e');
					dosyaYaz1.close();
				}
				//-----------------------------------------------------------------------------------
				if (secim1 == 2)//e�er oda silme i�lemi yapmak istiyorsak 2 harfine bast�r�nca oda silme i�lemi yapmak i�in karar yap�s� kulland�k.
				{
					system("cls");
					int nu;
					cout << "silinecek odanin numarasi:";
					cin >> nu;
					ifstream dosyaOku1("odalar.txt");
					ofstream dosyaYaz3("odalar.tmp");
					while (!dosyaOku1.eof()) {//burada dosya sonu kontol� ile dosyadan istedi�imiz de�eri bulup onu yedek dosyaya yazd�rm�yoruz bu �ekilde oday� silmi� oluyoruz.
						dosyaOku1 >> oda.no >> oda.fiyat;
						if (dosyaOku1.eof())//sonda de�er bulamay�p son de�eri bast�r�yor. bu i�lemi �nlemek i�in bu karar yap�s�n� kulland�m.
							break;
						if (nu != oda.no)//e�er arad���m�z de�eri bulamad�ysa yedek dosyaya tekrardan yaz�yor.daha sonra dosya ismini de�i�tirerek veriyi silmi� oluyoruz.
							dosyaYaz3 << oda.no << " " << oda.fiyat << endl;
					}
					dosyaOku1.close();
					dosyaYaz3.close();
					remove("odalar.txt");
					rename("odalar.tmp", "odalar.txt");
					cout << "ust menu icin u tusuna basiniz.";
					cin >> devam;
				}
				//-----------------------------------------------------------------------------------
				if (secim1 == 3)//e�er odalar� listelemek istiyorsa kullan�c� 3 say�s�n� kullanarak bu i�lemi ger�ekle�tirebilir.
				{
					system("cls");
					ifstream dosyaOku1("odalar.txt");
					while (!dosyaOku1.eof())//dosya sonu kontrol� ile dosyadaki veriler ekrana yazd�rmak �zere okunacak. 
					{
						dosyaOku1 >> oda.no >> oda.fiyat;
						if (dosyaOku1.eof())//e�er okunacak veri kalmazsa son okunan� tekrar basmamas� i�in if karar yap�s�n� kulland�m.
							break;
						cout << left << setw(5) << oda.no;
						cout << left << setw(5) << oda.fiyat;
						cout << endl;
					}
					dosyaOku1.close();
					cout << "ust menu icin u tusuna basiniz.";
					cin >> devam;
				}
			}
		} while (devam == 'u');
		//-----------------------------------------------------------------------------------
		do//m��teri i�lemleri yaparken �st men�ye ��kmak i�in do while yap�s�n� kulland�m.
		{
			devam = 'h';
			if (secim == 2)//m��teri i�lemleri i�in yap�lacak i�lemler i�in olan karar yap�s�.
			{
				system("cls");
				do//e�er kullan�c� istenilenin d���nda say� girerse hata verip tekrar men� g�stermesi i�in.
				{
					if (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 99)//yanl�� say�da hata vermek i�in.
					{
						system("cls");
						cout << "hatali secim" << endl;
						system("pause");
						system("cls");
					}
					cout << "Musteri islemleri" << endl;
					cout << "------------------" << endl;
					cout << "1-Musteri ekle" << endl;
					cout << "2-Musteri sil" << endl;
					cout << "3-Musterileri listele" << endl;
					cout << "99-ust menu" << endl;
					cout << "Seciminiz:";
					cin >> secim2;
				} while (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 99);
				//--------------------------------------------------------------------------------
				if (secim2 == 1)//m��teri eklemek i�in kullan�lan karar yap�s�.
				{
					ofstream dosyaYaz("musteriler.txt");
					do//ba�ka m��teri eklemek i�in kullan�lan do while yap�s�.
					{
						system("cls");
						cout << "musteri no:";
						cin >> musteri.no;
						cout << "musteri TC no:";
						cin >> musteri.TCno;
						cout << "musteri adini giriniz:";
						cin >> musteri.ad;
						cout << "musteri soyadini giriniz:";
						cin >> musteri.soyad;
						dosyaYaz << musteri.no << " " << musteri.TCno << " " << musteri.ad << " " << musteri.soyad << endl;
						cout << "yeni musteri kaydi yapacak misiniz(e/h)(ust menu icin u)?";
						cin >> devam;
					} while (devam == 'e');
					dosyaYaz.close();
				}
				//-----------------------------------------------------------------------------------
				if (secim2 == 2)//m��teri silmek i�in kullan�lan karar yap�s�
				{
					system("cls");
					int musterino;
					cout << "silinecek kisinin musteri numarasi:";
					cin >> musterino;
					ifstream dosyaOku("musteriler.txt");
					ofstream dosyaYaz2("musteriler.tmp");
					while (!dosyaOku.eof())//dosya sonu kontrol� ile m��teri silmek i�in kullan�lan while d�ng�s�.
					{
						dosyaOku >> musteri.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku.eof())//dosya sonu geldi�inde d�ng�den ��kmak i�in karar yap�s�.
							break;
						if (musterino != musteri.no)//aran�lan TC ile kontrol edilen e�it de�ilse yedek dosyaya kaydetmek i�in karar yap�s�.
							dosyaYaz2 << musteri.no << " " << musteri.TCno << " " << musteri.ad << " " << musteri.soyad << endl;
					}
					dosyaOku.close();
					dosyaYaz2.close();
					remove("musteriler.txt");
					rename("musteriler.tmp", "musteriler.txt");
					cout << "ust menu icin u tusuna basiniz.";
					cin >> devam;
				}
				//-----------------------------------------------------------------------------------
				if (secim2 == 3)//m��terileri listelemk i�in kullan�lan karar yap�s�.
				{
					system("cls");
					ifstream dosyaOku("musteriler.txt");
					while (!dosyaOku.eof())//dosya sonu kontrol� ile m��terileri listelemek i�in while d�ng�s�.
					{
						dosyaOku >> musteri.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku.eof())//dosya sonu geldi�inde d�ng�den ��kmak i�in karar yap�s�.
							break;
						cout << left << setw(5) << musteri.no;
						cout << left << setw(15) << musteri.TCno;
						cout << left << setw(15) << musteri.ad;
						cout << left << setw(15) << musteri.soyad;
						cout << endl;
					}
					dosyaOku.close();
					cout << "ust menu icin u tusuna basiniz.";
					cin >> devam;
				}
			}
			if (devam == 'u')//�st men�ye ��kmak i�in kullan�lan karar yap�s�.
				system("cls");
		} while (devam == 'u');
		//-----------------------------------------------------------------------------------
		do//oda kay�t i�lemlemlerinde �st men�ye ��kmak i�in kullan�lan do while d�ng�s�.
		{
			devam = 'h';
			if (secim == 3)//oda kay�t i�lemleri yapmak i�in kullan�lan karar yap�s�.
			{
				system("cls");
				do//istenilenin d���nda girilen say� olursa hata vermek i�in kullan�lan do while d�ng�s�
				{
					if (secim3 != 1 && secim3 != 2 && secim3 != 3 && secim3 != 99)//istenilenin d���nda girilen say� olursa hata vermek i�in kullan�lan karar yap�s�. 
					{
						system("cls");
						cout << "hatali secim" << endl;
						system("pause");
						system("cls");
					}
					cout << "Oda kayit islemleri" << endl;
					cout << "------------------" << endl;
					cout << "1-Odaya kayit ekle" << endl;
					cout << "2-Odadan kayit sil" << endl;
					cout << "3-Oda kayitlarinini listele" << endl;
					cout << "99-ust menu" << endl;
					cout << "Seciminiz:";
					cin >> secim3;
				} while (secim3 != 1 && secim3 != 2 && secim3 != 3 && secim3 != 99);
				//------------------------------------------------------------------------------------
				if (secim3 == 1)// odaya kay�t i�lemi i�in kullan�lan karar yap�s�
				{
					ofstream dosyaYaz4("odakayit.txt");
					ifstream dosyaOku("musteriler.txt");
					ifstream dosyaOku1("odalar.txt");
					do//ba�ka oda kay�t i�lemi yapmak i�in kullan�lan do while yap�s�.
					{
						system("cls");
						int odano, musterino;
						dosyaOku >> musteri.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						dosyaOku1 >> oda.no >> oda.fiyat;
						cout << "Oda numarasini giriniz:";
						cin >> odano;
						cout << "musteri nosunu giriniz:";
						cin >> musterino;
						if (odano == oda.no)//aran�lan oda no ile okunan de�er ayn�ysa dosyaya yazmak i�in kullan�lan karar yap�s�.
							dosyaYaz4 << oda.no << " ";
						if (musterino == musteri.no)//aran�lan TC ile okunan de�er ayn�ysa dosyaya yazmak i�in kullan�lan karar yap�s�.
							dosyaYaz4 << musteri.TCno << " " << musteri.ad << " " << musteri.soyad << endl;
						cout << "yeni oda kaydi yapacak misiniz(e/h)(ust menu icin u)?";
						cin >> devam;
					} while (devam == 'e');
					dosyaYaz4.close();
					dosyaOku.close();
					dosyaOku1.close();
				}
				//-----------------------------------------------------------------------------------
				if (secim3 == 2)//odadan kay�t silmek i�in kullan�lan karar yap�s�.
				{
					ifstream dosyaOku2("odakayit.txt");
					ofstream dosyaYaz5("odakayit.tmp");
					system("cls");
					int odano;
					cout << "Silmek istediginiz oda numarasini giriniz:";
					cin >> odano;
					while (!dosyaOku2.eof())//dosya sonu kontrol� ile de�er okumak i�in kullan�lan while d�ng�s�.
					{
						dosyaOku2 >> oda.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku2.eof())//dosya sonu geldi�inde dosyadan ��kmak i�in kullan�lan karar yap�s�.
							break;
						if (odano != oda.no)//aran�lan de�er ile okunan ayn� de�ilse yedek dosyaya yazd�rmak i�in kullan�lan karar yap�s�.
							dosyaYaz5 << oda.no << " " << musteri.TCno << " " << musteri.ad << " " << musteri.soyad << endl;
					}
					dosyaOku2.close();
					dosyaYaz5.close();
					remove("odakayit.txt");
					rename("odakayit.tmp", "odakayit.txt");
					cout << "ust menu icin u tusuna basiniz.";
					cin >> devam;
				}
				//-----------------------------------------------------------------------------------
				if (secim3 == 3)//oda kay�tlar�n� listelemek i�in kullan�lan karar yap�s�.
				{
					system("cls");
					ifstream dosyaOku2("odakayit.txt");
					while (!dosyaOku2.eof())//dosya sonu kontrol� ile de�er okumak i�in kullan�lan d�ng�.
					{
						dosyaOku2 >> oda.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku2.eof())//dosya sonu gelince d�ng�den ��kmak i�in kullan�lan karar yap�s�.
							break;
						cout << left << setw(5) << oda.no;
						cout << left << setw(15) << musteri.TCno;
						cout << left << setw(15) << musteri.ad;
						cout << left << setw(15) << musteri.soyad;
						cout << endl;
					}
					dosyaOku2.close();
					cout << "ust menu icin u tusuna basiniz.";
					cin >> devam;
				}
			}
			if (devam == 'u')
				system("cls");
		} while (devam == 'u');
		//-----------------------------------------------------------------------------------
		if (secim1 == 99 || secim2 == 99 || secim3 == 99)//�st men�ye ��kmak i�in kullan�lan karar yap�s�.
			system("cls");
	} while (secim1 == 99 || secim2 == 99 || secim3 == 99);
	system("pause");
	return 0;
}