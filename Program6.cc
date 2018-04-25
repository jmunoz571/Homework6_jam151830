/*--------------------------------------------------------------
#Name:         Jose Munoz
#NetID:        jam151830@utdallas.edu
#Class:        CS3377.501
#Project:      Program 6
#File:         Program6.cc
--------------------------------------------------------------*/
#ifndef PROGRAM6_CC
#define PROGRAM6_CC
#include <iostream>
#include "Program6.h"
#include <stdint.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#endif
using namespace std;

int main()
{
  //allocate memory for reading binary file
  BinaryFileHeader myRecord;
  
  //create input file stream 
  ifstream binInfile ("cs3377.bin", ios::in | ios::binary);
  //check to see if file opened correctly
  if(!binInfile)
  {
    cout << "Error - File did not open properly" << endl;
  }

  //read from input file 
  binInfile.read( (char*) &myRecord, sizeof(BinaryFileRecord));
 
  //Pass in value to CDK and display CDK matrix
  displayCDK(myRecord);
  //Close files
  binInfile.close();
 
  return 0;
}

