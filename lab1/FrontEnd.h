//---------------------------------------------------------------------------

#ifndef FrontEndH
#define FrontEndH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "cspin.h"

#include "BackEnd.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPaintBox *PaintBox;
	TButton *BtCreate;
	TButton *btByDefault;
	TCSpinEdit *seMoveX;
	TButton *btMove;
	TButton *btRotate;
	TCSpinEdit *seMoveY;
	TCSpinEdit *seMoveZ;
	TMemo *Memo1;
	void __fastcall btCreateClick(TObject *Sender);
	void __fastcall btByDefaultClick(TObject *Sender);
	void __fastcall btMoveClick(TObject *Sender);
private:	// User declarations
   void DrawTetrahedron(const int (&coords)[LINES_COUNT][D2]);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
