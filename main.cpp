#include "main.h"

int main()
{
	int choose = 0;
	int arabic = 0;
	string roman = "";

	cout << "===========================" << endl;
	cout << "1. Arabic to Roman numerals" << endl;
	cout << "2. Roman to Arabic numerals" << endl;
	cout << "===========================" << endl;
	cout << "Choose: ";
	cin >> choose;

	switch (choose)
	{
		case 1:	
			cout << "Enter arabic number [1-4999]: ";
			cin >> arabic;

			if(arabic > 0 && arabic < 5000)
				roman = arab_to_rom(arabic);
				cout << "In roman numerals: " << roman << endl;
			else
				cout << "The number must be more than 0, and less than 5000!" << endl;

			break;
		
		case 2:
			cout << "Enter roman number [I - MMMMCMXCIX]: ";
			cin >> roman;

				arabic = rom_to_arab(roman);

			cout << "In arabic numerals: " << arabic << endl;
			break;

		default:
			cout << "Incorret option" << endl;
	}

	return 0;
}



