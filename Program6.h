/*--------------------------------------------------------------
#Name:         Jose Munoz
#NetID:        jam151830@utdallas.edu
#Class:        CS3377.501
#Project:      Program 6
#File:         Program6.h
--------------------------------------------------------------*/
#ifndef PROGRAM6_H_CC
#define PROGRAM6_H_CC
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#endif
const int maxRecordStringLength = 25;

//Object for File Header
class BinaryFileHeader
{
 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

//Object for data records
class BinaryFileRecord
{
 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

int displayCDK(BinaryFileHeader);
