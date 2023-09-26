#include <bits/stdc++.h>
using namespace std;

class head
{
	char Iname[50][50];

public:
	int totalitems;
	float Qty[3];
	float price[3];
	int gstprice[3];
	int tprice[3];
	void input();
	void output();
};
class gst : public head
{
	float gst;

public:
	void gstcal();
	void outputs();
	void sum();
};

//******************************************************************
//	    INPUT FUNCTION
//******************************************************************

void head::input()
{
	system("CLS");
	cout << "\nEnter number of items = ";
	cin >> totalitems;

	for (int i = 0; i < totalitems; i++)
	{
		cout << "\nEnter name of item " << i + 1 << ": ";
		cin >> Iname[i];
		cout << "Enter quantity: ";
		cin >> Qty[i];
		cout << "Enter price of item " << i + 1 << ": ";
		cin >> price[i];
		tprice[i] = Qty[i] * price[i];
	}
}

//******************************************************************
//	   OUTPUT FUNCTION
//******************************************************************

void head::output()
{
	int a;

	ifstream infile("COUNT.TXT");
	infile >> a;

	ofstream outfile("COUNT.TXT");
	a += 1;
	outfile << a;
	outfile.close();

	{
		ofstream outfile("HIS.TXT", ios::app);
		outfile << endl
				<< "Bill No.: " << a << endl;
		outfile << "------------------------------------------------------------------------" << endl;
		cout << "\n";
		cout << "Name of Item\tQuantity   Price  Total Price\n";
		for (int i = 0; i < totalitems; i++)
		{
			outfile << "Name: " << Iname[i] << " Qty: " << Qty[i] << " Price: " << tprice[i] << endl;
			cout << Iname[i] << "\t\t" << Qty[i] << "\t   " << price[i] << "\t   " << tprice[i] << '\n';
		}

		outfile << "------------------------------------------------------------------------" << endl;
		outfile.close();
	}
}

//******************************************************************
//	   GST CALCULATION
//******************************************************************

void gst::gstcal()
{
	input();
	for (int i = 0; i < totalitems; i++)
	{
		if (price[i] <= 100.00)
		{
			gstprice[i] = tprice[i] + (0.05 * tprice[i]);
		}
		else
		{
			gstprice[i] = tprice[i] + (0.05 * tprice[i]);
		}
	}
}
//******************************************************************
//	    GST OUTPUTS
//******************************************************************

void gst::outputs()
{
	output();

	float cash = 0, sum = 0, qty = 0, sumt = 0;

	for (int i = 0; i < totalitems; i++)
	{
		sumt += tprice[i];
		sum += gstprice[i];
		qty += Qty[i];
	}
	cout << "\nTotal:";
	cout << "\n------------------------------------------------------------------------------";
	cout << "\n\tQuantity= " << qty << "\t\t Sum= " << sumt << "\tWith Gst:" << sum;
	cout << "\n------------------------------------------------------------------------------";

pay:

	cout << "\n\n\t\t\t****PAYMENT SUMMARY****\n";
	cout << "\n\t\t\tTotal cash given: ";
	cin >> cash;

	if (cash >= sum)
		cout << "\n\t\t\tTotal cash repaid: " << cash - sum << '\n';

	else
	{
		cout << "\n\t\t\tCash given is less than total amount!!!";

		goto pay;
	}
}

//******************************************************************
//	    PROTECTION PASSWORD
//******************************************************************

int passwords()
{

	char p1, p2, p3;

	cout << "\n\n\n\n\n\n\t\t\tENTER THE PASSWORD: ";

	cin >> p1;
	cout << "*";
	cin >> p2;
	cout << "*";
	cin >> p3;
	cout << "*";

	if ((p1 == 'm' || p1 == 'M') && (p2 == 'a' || p2 == 'A') && (p3 == 'h' || p3 == 'H'))

		return 1;

	else
		return 0;
}


//****************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	gst obj;
	char opt, ch;
	int a = 1;
	ifstream fin;

	a = passwords();
	if (!a)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "\nWrong password try once more\n";
			if (passwords())
			{
				goto last;
			}
			else
			{
				cout << "\n\n\t\t\t all attempts failed.....";
				cout << "\n\n\n\t\t\t see you.................. ";
				exit(0);
			}
		}
		cout << "\t\t\t sorry all attempts failed............. \n \t\t\tinactive";
	}
	else
	{
	last:;

		do
		{
		start:
			system("PAUSE");
			system("CLS");
			cout << "\n\n\t\t\t------------------------------";
			cout << "\n\t\t\tShop Billing Management System";
			cout << "\n\t\t\t------------------------------";
			cout << "\n\n\t\t\tWhat you want to do?";
			cout << "\n\t\t\t1.\tTo enter new entry\n\t\t\t2.\tTo view previous entries\n\t\t\t3.\tExit\n";
			cout << "\n\nEnter your option: ";
			cin >> opt;
			switch (opt)
			{
			case '1':
				obj.gstcal();

				obj.outputs();
				goto start;
			case '2':

				fin.open("HIS.TXT", ios::in);
				while (fin.get(ch))
				{
					cout << ch;
				}
				fin.close();

				goto start;
			case '3':
				exit(0);
			default:
				cout << "\a";
			}

		} while (opt != 3);
	}
	return 0;
}
