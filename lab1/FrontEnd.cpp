//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrontEnd.h"
//#include <System.Math.hpp>
#include <math.h>
#include "BackEnd.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
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

  float tetrahedron3D[LINES_COUNT][3] = {
  {0, 0, 0},
  {150, 0, 300},
  {300,0,0},
  {150,-300,150},
  };

  int tetrahedron2D[LINES_COUNT][2];

  int distanceToEyes=500;

  float halfXYWidth[2];
  halfXYWidth[0]=PaintBox->Height/2.0;
  halfXYWidth[1]=PaintBox->Width/2.0;
  //Memo1->Lines->Add(String(halfXYWidth[0]));
  //Memo1->Lines->Add(String(halfXYWidth[1]));



 //https://ru.wikipedia.org/wiki/Тетраэдр#Формулы_тетраэдра_в_декартовых_координатах_в_пространстве
  int center[3];
  for (int coordInd = 0; coordInd < 3; coordInd++) {
	float coordsSum=0.0;
	   for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
		  coordsSum+=tetrahedron3D[lineInd][coordInd];
	   }
	center[coordInd]=coordsSum/LINES_COUNT;
  }

   float angle= -17.0;
   float rad = (3.141592 / 180.0) * angle;
  for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
  //rotateY
//   int coordInd=0;
//   float rotatePart1=(tetrahedron3D[lineInd][coordInd]-center[coordInd])*cos(rad);
//   coordInd=2;
//   float rotatePart2=(tetrahedron3D[lineInd][coordInd]-center[coordInd])*sin(rad);
//   tetrahedron3D[lineInd][coordInd] = center[coordInd]+rotatePart1-rotatePart2;

   float x=tetrahedron3D[lineInd][0];
   float z=tetrahedron3D[lineInd][2];
   float x0=center[0];
   float z0=center[2];

   tetrahedron3D[lineInd][0]= x0+(x-x0)*cos(rad)-(z-z0)*sin(rad);
   tetrahedron3D[lineInd][0]=z0+(x-x0)*sin(rad)+(z-z0)*cos(rad);
  }



  float moveZ=140.0;
  for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
	 tetrahedron3D[lineInd][2]+= moveZ;
  }


//  for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
//  Memo1->Lines->Add(String(""));
//
//	float tempZ=(float)PaintBox->Width/(float)(distanceToEyes + tetrahedron3D[lineInd][2]);
//	Memo1->Lines->Add(String(tempZ));
//	for (int coordInd = 0; coordInd < 2; coordInd++) {
//	  tetrahedron2D[lineInd][coordInd]=(int)(tetrahedron3D[lineInd][coordInd]*tempZ+halfXYWidth[coordInd]);
//	  Memo1->Lines->Add(String(tetrahedron2D[lineInd][coordInd]));
//	}
//  }


  for (int i = 0; i < LINES_COUNT-1; i++) {
	  for (int j = 1; j < LINES_COUNT; j++) {
		PaintBox->Canvas->MoveTo(tetrahedron2D[i][0], tetrahedron2D[i][1]);
		PaintBox->Canvas->LineTo(tetrahedron2D[j][0], tetrahedron2D[j][1]);
	  }
  }




}
//---------------------------------------------------------------------------

void __fastcall TForm1::btByDefaultClick(TObject *Sender)
{
   InputBackEnd ibe;
   ibe.operationType=INIT_TETRAHEDRON;

   OutputBackEnd obe=BackEndMain(&ibe);

  for (int i = 0; i < LINES_COUNT; i++) {
	  Memo1->Lines->Add(String(obe.coords[i][0])+" "+String(obe.coords[i][1]));
  }


  for (int i = 0; i < LINES_COUNT-1; i++) {
	  for (int j = 1; j < LINES_COUNT; j++) {
		PaintBox->Canvas->MoveTo(obe.coords[i][0], obe.coords[i][1]);
		PaintBox->Canvas->LineTo(obe.coords[j][0], obe.coords[j][1]);
	  }
  }
}
//---------------------------------------------------------------------------

