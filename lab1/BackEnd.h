//---------------------------------------------------------------------------

#ifndef BackEndH
#define BackEndH


const int LINES_COUNT=4;

const int D3=3; //e.g. 3D
const int D2=2;


enum OperationType{
	INIT_TETRAHEDRON=0,
	MOVE_TETRAHEDRON,
	ROTATE_TETRAHEDRON,
	SCALE_TETRAHEDRON
};

struct InputBackEnd {
   OperationType operationType;
   float move[D3];      //веществ
   float rotate[D3];
   float scale[D3];
   //int borders[D2];
   // коэф масштабир.
};


enum ErrorCode{
	OK=0,
	FIGURE_OUT_OF_BORDER,
	UNKNOWN_COMMAND//todo add try-catch
};

struct OutputBackEnd{
	int coords[LINES_COUNT][D2];
	ErrorCode errorCode;
};


OutputBackEnd BackEndMain(const InputBackEnd *pibe);

void InitTetrahedron(float (&tetrahedron3d)[LINES_COUNT][D3]);
void MoveTetrahedron(float (&tetrahedron3d)[LINES_COUNT][D3], const float (&move3d)[D3]);
void RotateTetrahedron(float (&tetrahedron3d)[LINES_COUNT][D3]);
void ScaleTetrahedron(float (&tetrahedron3d)[LINES_COUNT][D3]);

void ConvertTo2D( const float (&tetrahedron3d)[LINES_COUNT][D3], int (&tetrahedron2d)[LINES_COUNT][D2]);

//---------------------------------------------------------------------------
#endif
