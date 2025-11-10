#include "Association.h"
#include <iostream>
using namespace std;

void Association::Show()
{
	cout << name.get_string() << endl;
	L.display_all();
	return;
}