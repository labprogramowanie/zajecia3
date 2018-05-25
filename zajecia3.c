#include <stdio.h>

unsigned short IleBitowUnsignedShort() {
	unsigned short s = sizeof(unsigned short) * 8;
	return s;

}

void WypiszBitowo(unsigned short liczba) {
	unsigned short maska = 0x8000;
	while (maska != 0) {
		if ((liczba&maska) != 0) { printf("1"); }
		else { printf("0"); }
		maska = maska >> 1;
	}
	printf("\n");
}

void PodstawoweOperacjeBitowe(unsigned short a, unsigned short b) {
	printf("Liczba a do operacji: %hu to \t", a);
	WypiszBitowo(a);
	printf("Liczba b do operacji: %hu to \t", b);
	WypiszBitowo(b);

	unsigned short c, d, e;

	c = a&b;
	printf("Wynik a&b to: %hu czyli \t", c);
	WypiszBitowo(c);

	d = a|b;
	printf("Wynik a|b to: %hu czyli \t", d);
	WypiszBitowo(d);

	e = a^b;
	printf("Wynik a^b to: %hu czyli \t", e);
	WypiszBitowo(e);

	printf("Wynik a<<1 to: %hu czyli \t", a<<1);
	WypiszBitowo(a<<1);

	printf("Wynik b<<1 to: %hu czyli \t", b << 1);
	WypiszBitowo(b << 1);

	printf("Wynik a>>1 to: %hu czyli \t", a << 1);
	WypiszBitowo(a >> 1);

	printf("Wynik b>>1 to: %hu czyli \t", b << 1);
	WypiszBitowo(b >> 1);

	printf("Wynik ~a to: %hu czyli \t", ~a);
	WypiszBitowo(~a);

	printf("Wynik ~b to: %hu czyli \t", ~b);
	WypiszBitowo(~b);
}

unsigned short Zmien(unsigned short liczba) {
	printf("Wynik ~%hu to: %hu czyli \t", liczba, ~liczba);
	WypiszBitowo(~liczba);
	return ~liczba;
}

unsigned short ZamienPrzedzial (unsigned short liczba, int start, int koniec){
	unsigned short maska = (~0);
	maska = (~(maska<<(koniec-start+1)))<<(start-1);
// WypiszBitowo(maska);

	printf("Wprowadzona liczba bitowo to: \t");
	WypiszBitowo(liczba);

    liczba = liczba^maska;

    printf("Liczba po negacji bitowej: \t");
	WypiszBitowo(liczba);

 return liczba;
}

unsigned short ROR(unsigned short liczba, int n){
    int end = (16/n)+1;

    printf("\nWPROWADZONA LICZBA: \n");
    WypiszBitowo(liczba);

for (int i=1;i<end;i++){
    unsigned short templiczba= liczba << (i*n);
    unsigned short tempmaska= liczba >> (16-(n*i));
    unsigned short wynik= templiczba|tempmaska;
    WypiszBitowo(wynik);
}
    WypiszBitowo(liczba);
}

void main() {
    char c;
	unsigned short zmienna1;
	unsigned short zmienna2;
	int liczba1;
	int liczba2;




		while(5){
    printf("********************** MENU *********************\n");
    printf("1. Sprawdzenie rozmiaru Unsigned Short\n");
	printf("2. Zamiana liczby dziesietnej na bitowa\n");
	printf("3. Operacje bitowe na dwoch liczbach dziesietnych\n");
	printf("4. Negacja bitowa liczby dziesietnej\n");
	printf("5. Negacja bitowa liczby w przedziale bitow\n");
	printf("6. Cykliczne przesuwanie bitow liczby dziesietnej\n");
    scanf("%s",&c);

            switch(c){



                case '1':
                        printf("Rozmiar unsigned short to: %hu \n", IleBitowUnsignedShort());
                        break;

                case '2':
                    	printf("Podaj liczbe do zamiany na bity: ");
                        scanf("%hu",&zmienna1);
                        printf("Liczba %d bitowo to: \t",zmienna1);
                        WypiszBitowo(zmienna1);
                        break;
                case '3':
                    	printf("Podaj pierwsza liczbe do operacji bitowych: ");
                        scanf("%hu",&zmienna1);
                        printf("Podaj druga do operacji bitowych: ");
                        scanf("%hu",&zmienna2);
                        PodstawoweOperacjeBitowe(zmienna1, zmienna2);
                        break;
                case '4':
                    	printf("Podaj liczbe do negacji bitowej: ");
                        scanf("%hu",&zmienna1);
                        printf("Liczba %d po negacji to %hu \n", zmienna1, Zmien(zmienna1));
                        break;
                case '5':
                        printf("Podaj liczbe do negacji bitowej: ");
                        scanf("%hu",&zmienna1);
                        printf("Podaj poczatkowy bit (najmniej znaczacy to 1): ");
                        scanf("%hu",&liczba1);
                        printf("Podaj koncowy bit negacji: ");
                        scanf("%hu",&liczba2);
                        printf("Negacja liczby: %hu w wybranym przedziale przedziale to: %hu \n",zmienna1, ZamienPrzedzial(zmienna1,liczba1, liczba2));
                        break;
                case '6':
                        printf("Podaj liczbe do cyklicznego przesuwania: ");
                        scanf("%hu",&zmienna1);
                        printf("Podaj ilosc cyklicznie przesuwanych bitow: ");
                        scanf("%hu",&liczba1);
                        printf("\n");
                        ROR(zmienna1,liczba1);
                        break;
                default:
                        printf("Brak opcji");
                        break;



            }

		}
}
