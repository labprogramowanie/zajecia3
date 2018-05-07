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
}
void main() {
	unsigned short z = 44153;

	printf("Rozmiar unsigned short to: %hu \n", IleBitowUnsignedShort());

	printf("Liczba %d bitowo to: \t",z);
	WypiszBitowo(44153); // Przeliczenie liczby na binarna

	PodstawoweOperacjeBitowe(z, z);

	printf("Liczba %d po negacji to %hu", z, Zmien(z));






}