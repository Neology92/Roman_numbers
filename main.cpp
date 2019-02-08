#include <iostream>

using namespace std;

int odszyfruj(string s);
string zaszyfruj(int x);

int main()
{


	return 0;
}


string zaszyfruj(int a)
{
	string str = "";

	// int i,v,x,l,c,d,m;

	int t,s,d,j;

	t = a/1000;
	s = (a%1000)/100;
	d = (a%100)/10;
	j = (a%10);


	// tysiące
	while(t--)
	{
		str += "M";
	}

	// setki
	if(s == 9)
	{
		str += "CM";
	}
	else if (s >= 5)
	{
		str += "D";
		s -= 5;
		while(s--)
		{
			str += "C";
		}
	}
	else if( s == 4 )
	{
		str += "CD";
	}
	else
	{
		while(s--)
		{
			str += "C";
		}
	}

	// dziesiątki
	if(d == 9)
	{
		str += "XC";
	}
	else if (d >= 5)
	{
		str += "L";
		d -= 5;
		while(d--)
		{
			str += "X";
		}
	}
	else if( d == 4 )
	{
		str += "XL";
	}
	else
	{
		while(d--)
		{
			str += "X";
		}
	}

	// jednostki
	if(j == 9)
	{
		str += "IX";
	}
	else if (j >= 5)
	{
		str += "V";
		j -= 5;
		while(j--)
		{
			str += "I";
		}
	}
	else if( j == 4 )
	{
		str += "IV";
	}
	else
	{
		while(j--)
		{
			str += "I";
		}
	}


	return str;
}


int odszyfruj(string s)
{
	int tab[12];
	char *ptr = &s[0];
	int i = -1;
	int result;

	while(*ptr)
	{
		i++;
		switch(*(ptr++))
		{
			case 'I' : tab [i] = 1;
				break;

			case 'V' : tab [i] = 5;
				break;

			case 'X' : tab [i] = 10;
				break;

			case 'L' : tab [i] = 50;
				break;

			case 'C' : tab [i] = 100;
				break;

			case 'D' : tab [i] = 500;
				break;

			case 'M' : tab [i] = 1000;
				break;
		}
	}

	while(true)
	{

		int max_i=-1, max_v=0, sec_i=-1, sec_v=0;

			for (int j=0; j <= i; j++)
			{
				if(tab[j] > max_v)
				{
					max_v = tab[j];
					max_i = j;
				}
			// cout << "| max_v:" << max_v << "/" << max_i << ", sec_v:" << sec_v << "/" << sec_i << endl;
			}
			// cout << endl;
			for (int j=i; j >=0; j--)
			{
				if(tab[j] >= sec_v && tab[j] < max_v)
				{
					sec_v = tab[j];
					sec_i = j;	
				}
				else if( tab[j] == max_v && j != max_i)
				{
					sec_v = max_v;
					sec_i = j;
				}			
			// cout << "| max_v:" << max_v << "/" << max_i << ", sec_v:" << sec_v << "/" << sec_i << endl;
			}
			// cout << endl;
			/////////////
			// for (int j=0; j <= i; j++)
			// {
			// 	cout << "tab[" << j << "]:" << tab[j] << ", ";
			// }
			// cout << endl;



			if(sec_i > max_i || sec_v == max_v)
			{
				tab[sec_i] = max_v + sec_v;
				tab[max_i] = 0;
			}
			else if(sec_i < max_i)
			{
				tab[max_i] = max_v - sec_v;
				tab[sec_i] = 0;
			}

			/////////////
			// for (int j=0; j <= i; j++)
			// {
			// 	cout << "tab[" << j << "]:" << tab[j] << ", ";
			// }
			// cout << endl;


			if(sec_v == 0)
			{
				result = max_v;	
				break;
			}
		// cout << endl << endl;
	}

	return result;
}
