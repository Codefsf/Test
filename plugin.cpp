#include <iostream>

#include "plugin.h"

using namespace std;

Plugin::Plugin()
{
    cout << __func__ << endl;
}

Plugin::~Plugin()
{
    cout << __func__ << endl;
}