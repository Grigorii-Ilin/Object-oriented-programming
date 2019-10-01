//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrontEnd.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btCreateClick(TObject *Sender)
{
const int LINES_COUNT=4;


  //Bitmap bitmap();
  //Canvas *pc; //= &Form1->PaintBox->Canvas;
  //PaintBox->Canvas->LineTo(250,250);
  int tetrahedron3D[LINES_COUNT][3] = {
  {0, 0, 0},
  {150, -100, 300},
  {300,0,0},
  {150,-300,150},
  };

  int tetrahedron2D[LINES_COUNT][2];

  int distanceToEyes=500;

  int halfXYWidth[2];
  halfXYWidth[0]=PaintBox->Height/2;
  halfXYWidth[1]=PaintBox->Width/2;
  Memo1->Lines->Add(String(halfXYWidth[0]));
  Memo1->Lines->Add(String(halfXYWidth[1]));

  for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
  Memo1->Lines->Add(String(""));

	float tempZ=(float)PaintBox->Width/(float)(distanceToEyes + tetrahedron3D[lineInd][2]);
	Memo1->Lines->Add(String(tempZ));
	for (int coordInd = 0; coordInd < 2; coordInd++) {
	  tetrahedron2D[lineInd][coordInd]=tetrahedron3D[lineInd][coordInd]*tempZ+halfXYWidth[coordInd];
	  Memo1->Lines->Add(String(tetrahedron2D[lineInd][coordInd]));
	}
	//tetrahedron2D[lineInd][0]=(int)tetrahedron3D[lineInd][0]*tempZ+PaintBox->Canvas->Heigth/2;
  }

  for (int i = 0; i < LINES_COUNT-1; i++) {
	  for (int j = 1; j < LINES_COUNT; j++) {
		PaintBox->Canvas->MoveTo(tetrahedron2D[i][0], tetrahedron2D[i][1]);
		PaintBox->Canvas->LineTo(tetrahedron2D[j][0], tetrahedron2D[j][1]);
	  }
  }



}
//---------------------------------------------------------------------------
