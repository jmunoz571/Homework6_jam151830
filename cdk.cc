/*--------------------------------------------------------------
#Name:         Jose Munoz
#NetID:        jam151830@utdallas.edu
#Class:        CS3377.501
#Project:      Program 6
#File:         cdk.cc
--------------------------------------------------------------*/
#ifndef CDK_CC
#define CDK_CC
#include "Program6.h"
#include <iostream>
#include "cdk.h"
#include <string>
#include <sstream>
#endif

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int displayCDK(BinaryFileHeader myRecord, BinaryFileRecord dataRecords[], int n )
{
  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  // Remember that matrix starts out at 1,1.
  // Since arrays start out at 0, the first entries
  // below ("R0", and "C0") are just placeholders
  // 
  // Finally... make sure your arrays have enough entries given the
  // values you choose to set for MATRIX_WIDTH and MATRIX_HEIGHT
  // above.

  const char 		*rowTitles[] = {"-", "a", "b", "c", "d", "e", "f"};
  const char 		*columnTitles[] = {"-", "a", "b", "c", "d", "e", "f"};
  int		boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);


  /*
   * Dipslay a message
   */
  //1st Row
  
  stringstream stream;
  string result = "";
  char const* s;

  stream << "Magic: 0x" << hex << uppercase <<  myRecord.magicNumber;
  result = stream.str();
  s = result.c_str();
  setCDKMatrixCell(myMatrix, 1, 1, s);
  stream.str("");
  
  stream << "Version: " << dec << myRecord.versionNumber;
  result = stream.str();
  s = result.c_str();
  setCDKMatrixCell(myMatrix, 1, 2, s);
  stream.str("");

  stream << "NumRecords: " << dec << myRecord.numRecords;
  result = stream.str();
  s = result.c_str();
  setCDKMatrixCell(myMatrix, 1, 3, s);

  //display length of string and its value(s)  
  int j = 2;
  for(int i = 0; i < n ; i++)
  {
    if(j+1 > MATRIX_WIDTH)
      break;
    //clear stream
    stream.str("");

    //conver stringLength to string
    stream << "strlen: " << dec <<(int) dataRecords[i].strLength;
    result = stream.str();
    s = result.c_str();
    
    //display content
    setCDKMatrixCell(myMatrix, j+i, 1, s);
    s = dataRecords[i].stringBuffer;
    setCDKMatrixCell(myMatrix, j+i, 2, s);
  }

  drawCDKMatrix(myMatrix, true);    /* required  */

  /* So we can see results, pause until a key is pressed. */
  unsigned char x;
  cin >> x;

  // Cleanup screen
  endCDK();
  return 0;
}
