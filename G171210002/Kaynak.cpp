/************************************************************
**                   SAKARYA ÜNÝVERSÝTESÝ
**          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**              BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                 PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**      ÖDEV NUMARASI....:5
**      ÖÐRENCÝ ADI......:HAKAN ATEÞLÝ
**      ÖÐRENCÝ NUMARASI.:G171210002
**      DERS GRUBU.......:2/A
************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct kisi//bu yapýyý müþterileri oluþtururken bana kolaylýk saðlamasý daha kolay ulaþmak için oluþturdum. 
{
	string ad;
	string soyad;
	string TCno;
	int no;
}musteri;
struct mekan//bu yapýyý odalarý daha kolay eriþip eleman eklemek için oluþturdum.
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
	do//bu do while döngüsünü eðer kullanýcý iþini bitiridkten sonra ilk sayfaya gitmek istiyorsa 99 sayýsýna basýnca ilk sayfaya ulaþtýrmak için oluþturdum.
	{
		//---------------------------------------------------------------------------------
		do//bu do while yapýsýný eðer kullanýcý istenilen deðerler dýþýnda deðer girerse uyarý verip tekrar ayný sayfaya dönmek için oluþturduk.
		{
			if (secim != 1 && secim != 2 && secim != 3 && secim != 99)//eðer seçim istenilen gibi yapýlmazsa ekrana uyarý yazýp tekrar baþa dönmemizi saðlamak için if kullandým.
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
		if (secim == 99)//eðer kullanýcý iþlem yapmak istemeyip programdan çýkmak isterse if karar yapýsýyla saðladýðým þekilde 99 sayýsýný tuþlayarak bu iþlemi gerçekleþtirebilir.
			return 0;
		//-----------------------------------------------------------------------------------
		do//bu döngüyü her yaptýðý iþlemden sonra üst menüye çýkamasýný saðlamk için oluþturdum.
		{
			devam = 'h';
			if (secim == 1)//eðer kullanýcýnýn seçimi 1 olursa aþaðýdaki iþlemleri yapmasý için bu karar yapýsýný kullandým.
			{
				system("cls");
				do//oda ile alakalý iþlmelerden hangisini yapmak istediði ile alakalý menü oluþturdum eðer istenileni seçmezse hata verip tekrar gösterilecek.
				{
					if (secim1 != 1 && secim1 != 2 && secim1 != 3 && secim1 != 99)//istenileni deðeri seçmediði zaman hata yazýsý verip tekrar baþa dönmek için kullandým.
					{
						system("cls");
						cout << "hatalý secim" << endl;
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
				if (secim1 == 1)//eðer kullanýcý oda eklemek isteniyorsa 1 rakamýný tuþlayýp sýralý iþlemleri gerçekleþtirecek.
				{
					ofstream dosyaYaz1("odalar.txt");
					do//eðer üst üste oda eklemek istediðimizde e harfi ile bu iþlemi yapmak için do while ile yaptýk.
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
				if (secim1 == 2)//eðer oda silme iþlemi yapmak istiyorsak 2 harfine bastýrýnca oda silme iþlemi yapmak için karar yapýsý kullandýk.
				{
					system("cls");
					int nu;
					cout << "silinecek odanin numarasi:";
					cin >> nu;
					ifstream dosyaOku1("odalar.txt");
					ofstream dosyaYaz3("odalar.tmp");
					while (!dosyaOku1.eof()) {//burada dosya sonu kontolü ile dosyadan istediðimiz deðeri bulup onu yedek dosyaya yazdýrmýyoruz bu þekilde odayý silmiþ oluyoruz.
						dosyaOku1 >> oda.no >> oda.fiyat;
						if (dosyaOku1.eof())//sonda deðer bulamayýp son deðeri bastýrýyor. bu iþlemi önlemek için bu karar yapýsýný kullandým.
							break;
						if (nu != oda.no)//eðer aradýðýmýz deðeri bulamadýysa yedek dosyaya tekrardan yazýyor.daha sonra dosya ismini deðiþtirerek veriyi silmiþ oluyoruz.
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
				if (secim1 == 3)//eðer odalarý listelemek istiyorsa kullanýcý 3 sayýsýný kullanarak bu iþlemi gerçekleþtirebilir.
				{
					system("cls");
					ifstream dosyaOku1("odalar.txt");
					while (!dosyaOku1.eof())//dosya sonu kontrolü ile dosyadaki veriler ekrana yazdýrmak üzere okunacak. 
					{
						dosyaOku1 >> oda.no >> oda.fiyat;
						if (dosyaOku1.eof())//eðer okunacak veri kalmazsa son okunaný tekrar basmamasý için if karar yapýsýný kullandým.
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
		do//müþteri iþlemleri yaparken üst menüye çýkmak için do while yapýsýný kullandým.
		{
			devam = 'h';
			if (secim == 2)//müþteri iþlemleri için yapýlacak iþlemler için olan karar yapýsý.
			{
				system("cls");
				do//eðer kullanýcý istenilenin dýþýnda sayý girerse hata verip tekrar menü göstermesi için.
				{
					if (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 99)//yanlýþ sayýda hata vermek için.
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
				if (secim2 == 1)//müþteri eklemek için kullanýlan karar yapýsý.
				{
					ofstream dosyaYaz("musteriler.txt");
					do//baþka müþteri eklemek için kullanýlan do while yapýsý.
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
				if (secim2 == 2)//müþteri silmek için kullanýlan karar yapýsý
				{
					system("cls");
					int musterino;
					cout << "silinecek kisinin musteri numarasi:";
					cin >> musterino;
					ifstream dosyaOku("musteriler.txt");
					ofstream dosyaYaz2("musteriler.tmp");
					while (!dosyaOku.eof())//dosya sonu kontrolü ile müþteri silmek için kullanýlan while döngüsü.
					{
						dosyaOku >> musteri.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku.eof())//dosya sonu geldiðinde döngüden çýkmak için karar yapýsý.
							break;
						if (musterino != musteri.no)//aranýlan TC ile kontrol edilen eþit deðilse yedek dosyaya kaydetmek için karar yapýsý.
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
				if (secim2 == 3)//müþterileri listelemk için kullanýlan karar yapýsý.
				{
					system("cls");
					ifstream dosyaOku("musteriler.txt");
					while (!dosyaOku.eof())//dosya sonu kontrolü ile müþterileri listelemek için while döngüsü.
					{
						dosyaOku >> musteri.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku.eof())//dosya sonu geldiðinde döngüden çýkmak için karar yapýsý.
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
			if (devam == 'u')//üst menüye çýkmak için kullanýlan karar yapýsý.
				system("cls");
		} while (devam == 'u');
		//-----------------------------------------------------------------------------------
		do//oda kayýt iþlemlemlerinde üst menüye çýkmak için kullanýlan do while döngüsü.
		{
			devam = 'h';
			if (secim == 3)//oda kayýt iþlemleri yapmak için kullanýlan karar yapýsý.
			{
				system("cls");
				do//istenilenin dýþýnda girilen sayý olursa hata vermek için kullanýlan do while döngüsü
				{
					if (secim3 != 1 && secim3 != 2 && secim3 != 3 && secim3 != 99)//istenilenin dýþýnda girilen sayý olursa hata vermek için kullanýlan karar yapýsý. 
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
				if (secim3 == 1)// odaya kayýt iþlemi için kullanýlan karar yapýsý
				{
					ofstream dosyaYaz4("odakayit.txt");
					ifstream dosyaOku("musteriler.txt");
					ifstream dosyaOku1("odalar.txt");
					do//baþka oda kayýt iþlemi yapmak için kullanýlan do while yapýsý.
					{
						system("cls");
						int odano, musterino;
						dosyaOku >> musteri.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						dosyaOku1 >> oda.no >> oda.fiyat;
						cout << "Oda numarasini giriniz:";
						cin >> odano;
						cout << "musteri nosunu giriniz:";
						cin >> musterino;
						if (odano == oda.no)//aranýlan oda no ile okunan deðer aynýysa dosyaya yazmak için kullanýlan karar yapýsý.
							dosyaYaz4 << oda.no << " ";
						if (musterino == musteri.no)//aranýlan TC ile okunan deðer aynýysa dosyaya yazmak için kullanýlan karar yapýsý.
							dosyaYaz4 << musteri.TCno << " " << musteri.ad << " " << musteri.soyad << endl;
						cout << "yeni oda kaydi yapacak misiniz(e/h)(ust menu icin u)?";
						cin >> devam;
					} while (devam == 'e');
					dosyaYaz4.close();
					dosyaOku.close();
					dosyaOku1.close();
				}
				//-----------------------------------------------------------------------------------
				if (secim3 == 2)//odadan kayýt silmek için kullanýlan karar yapýsý.
				{
					ifstream dosyaOku2("odakayit.txt");
					ofstream dosyaYaz5("odakayit.tmp");
					system("cls");
					int odano;
					cout << "Silmek istediginiz oda numarasini giriniz:";
					cin >> odano;
					while (!dosyaOku2.eof())//dosya sonu kontrolü ile deðer okumak için kullanýlan while döngüsü.
					{
						dosyaOku2 >> oda.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku2.eof())//dosya sonu geldiðinde dosyadan çýkmak için kullanýlan karar yapýsý.
							break;
						if (odano != oda.no)//aranýlan deðer ile okunan ayný deðilse yedek dosyaya yazdýrmak için kullanýlan karar yapýsý.
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
				if (secim3 == 3)//oda kayýtlarýný listelemek için kullanýlan karar yapýsý.
				{
					system("cls");
					ifstream dosyaOku2("odakayit.txt");
					while (!dosyaOku2.eof())//dosya sonu kontrolü ile deðer okumak için kullanýlan döngü.
					{
						dosyaOku2 >> oda.no >> musteri.TCno >> musteri.ad >> musteri.soyad;
						if (dosyaOku2.eof())//dosya sonu gelince döngüden çýkmak için kullanýlan karar yapýsý.
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
		if (secim1 == 99 || secim2 == 99 || secim3 == 99)//üst menüye çýkmak için kullanýlan karar yapýsý.
			system("cls");
	} while (secim1 == 99 || secim2 == 99 || secim3 == 99);
	system("pause");
	return 0;
}