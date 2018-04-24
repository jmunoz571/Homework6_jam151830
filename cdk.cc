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
#endif

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int displayCDK()
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
  setCDKMatrixCell(myMatrix, 1, 1, "Magic: ");
  setCDKMatrixCell(myMatrix, 1, 2, "Version: ");
  setCDKMatrixCell(myMatrix, 1, 3, "NumRecords: ");
  //print length of string and its value(s)
  setCDKMatrixCell(myMatrix, 2, 1, "strlen: ");
  setCDKMatrixCell(myMatrix, 2, 2, " ");
  

  drawCDKMatrix(myMatrix, true);    /* required  */

  /* So we can see results, pause until a key is pressed. */
  unsigned char x;
  cin >> x;

  // Cleanup screen
  endCDK();
  return 0;
}
