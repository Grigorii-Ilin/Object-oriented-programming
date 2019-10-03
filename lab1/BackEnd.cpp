//---------------------------------------------------------------------------

#pragma hdrstop

#include "BackEnd.h"

#include <stdio.h>
#include "FrontEnd.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)

const float PICTURE_BOX_LEN=400.0;

OutputBackEnd BackEndMain(const InputBackEnd *pibe){
	static float tetrahedron3d[LINES_COUNT][D3];  //tetrahedron 3D matr.
	OutputBackEnd obe;

	Form1->Memo1->Lines->Add("pibe->operationType "+ String(pibe->operationType));

	switch (pibe->operationType) {
	   case INIT_TETRAHEDRON:{
			Form1->Memo1->Lines->Add("pibe->INIT_TETRAHEDRON ");
		   InitTetrahedron( tetrahedron3d);
	   }

	   case MOVE_TETRAHEDRON:{
		   MoveTetrahedron(tetrahedron3d, pibe->move);
	   }
	}


	  for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
		 Form1->Memo1->Lines->Add("t3d x "+ String(tetrahedron3d[lineInd][0]));

      }
	ConvertTo2D(tetrahedron3d, obe.coords);

	return obe;
}


void InitTetrahedron(float (&tetrahedron3d)[LINES_COUNT][D3]){
Form1->Memo1->Lines->Add("InitTetrahedron ");

	tetrahedron3d[0][0]=0;
	tetrahedron3d[0][1]=0;
	tetrahedron3d[0][2]=0;

	tetrahedron3d[1][0]=150;
	tetrahedron3d[1][1]=0;
	tetrahedron3d[1][2]=300;

	tetrahedron3d[2][0]=300;
	tetrahedron3d[2][1]=0;
	tetrahedron3d[2][2]=0;

	tetrahedron3d[3][0]=150;
	tetrahedron3d[3][1]=-300;
	tetrahedron3d[3][2]=150;

	 Form1->Memo1->Lines->Add("t3d 3 x0 "+ String(tetrahedron3d[3][0]));
}


void MoveTetrahedron(float (&tetrahedron3d)[LINES_COUNT][D3], const float (&move3d)[D3]){
  for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
	for (int coordInd = 0; coordInd < D3; coordInd++) {
	  tetrahedron3d[lineInd][coordInd]+=move3d[coordInd];
    }
  }
}


void ConvertTo2D(const float (&tetrahedron3d)[LINES_COUNT][D3], int (&tetrahedron2d)[LINES_COUNT][D2]){
  //float minWidth=borders[0]<borders[1]?(float)borders[0]:(float)borders[1];

//  float halfXYWidth[2];
//  for (int i = 0; i < D2; i++) {
//	  halfXYWidth[i]= borders[i]/2.0;
//  }

  const float DISTANCE_TO_EYES=500.0;

  float pictureBoxHalfLen= PICTURE_BOX_LEN/2.0;


  for (int lineInd = 0; lineInd < LINES_COUNT; lineInd++) {
	Form1->Memo1->Lines->Add("t3d z"+ String(tetrahedron3d[lineInd][2]));

	float tempZ=PICTURE_BOX_LEN/(DISTANCE_TO_EYES + tetrahedron3d[lineInd][2]);


//	printf("%f", tempZ);
//	char buf;
//	scanf("%c", &buf);

	Form1->Memo1->Lines->Add("tempZ "+ String(tempZ));
//	String s=String(tempZ);
//	s.sprintf(L"Бла-бла-бла %s бла-бла-бла %d", Edit1->Text, x);
	//ShowMessage(L"Welcome to the Sellers Bank.");

	for (int coordInd = 0; coordInd < D2; coordInd++) {
	Form1->Memo1->Lines->Add("t3d "+ String(tetrahedron3d[lineInd][coordInd]));

	  tetrahedron2d[lineInd][coordInd]=(int)(tetrahedron3d[lineInd][coordInd]*tempZ+pictureBoxHalfLen);
	}
  }


}

