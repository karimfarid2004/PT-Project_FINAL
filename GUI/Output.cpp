#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
////////////////////////////////////////////	//////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SLCT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_SHAPES] = "images\\MenuItems\\shapes.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Color_Wheel.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Color_Fill.jpg";
	MenuItemImages[ITM_PLYMOD] = "images\\MenuItems\\Play_Mode.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_DLET] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_CLR] = "images\\MenuItems\\clear_all.jpg";
	MenuItemImages[ITM_REC] = "images\\MenuItems\\rec.jpg";
	MenuItemImages[ITM_END] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\download.jpg";
	MenuItemImages[ITM_EXIT_DRAWMODE] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;

	//pWind->DrawImage("images\\MenuItems\\background.jpg",UI.width,0,UI.ToolBarHeight,UI.width );
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_TYP_COLOR] = "images\\MenuItems\\Color_Wheel.jpg";
	MenuItemImages[ITM_TYP_SHAPE] = "images\\MenuItems\\shapes.jpg";
	MenuItemImages[ITM_TYP_BOTH] = "images\\MenuItems\\both.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT_PLAYMODE] = "images\\MenuItems\\Menu_Exit.jpg";


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateShapesToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = SHAPES_SELECTION;

	string MenuItemImages[SHAPES_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\ShapesItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\ShapesItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRI] = "images\\ShapesItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_SQU] = "images\\ShapesItems\\Menu_Squ.jpg";
	MenuItemImages[ITM_HEX] = "images\\ShapesItems\\Menu_Hex.jpg";


	for (int i = 0; i < SHAPES_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateColorsToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = COLOR_SELECTION;

	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK] = "images\\ColorItems\\Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\ColorItems\\Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\ColorItems\\Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\ColorItems\\Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\ColorItems\\Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\ColorItems\\Blue.jpg";


	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateFillColorsToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = FILL_COLOR_SELECTION;

	string MenuItemImages[FILL_COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK_FILL] = "images\\ColorItems\\Black.jpg";
	MenuItemImages[ITM_BLUE_FILL] = "images\\ColorItems\\Blue.jpg";
	MenuItemImages[ITM_GREEN_FILL] = "images\\ColorItems\\Green.jpg";
	MenuItemImages[ITM_ORANGE_FILL] = "images\\ColorItems\\Orange.jpg";
	MenuItemImages[ITM_RED_FILL] = "images\\ColorItems\\Red.jpg";
	MenuItemImages[ITM_YELLOW_FILL] = "images\\ColorItems\\Yellow.jpg";
	MenuItemImages[ITM_NO_FILL] = "images\\ColorItems\\No_Fill.jpg";

	for (int i = 0; i < FILL_COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
//////////////////////////////////////////////  yousef ADEL _start ....
void Output::DrawSq(Point Ctr, GfxInfo SqGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqGfxInfo.FillClr);  //Figure should be drawn filled
	}
	else
		style = FRAME;
	Point P1, P2;
	int length = 200;
	P1.x = Ctr.x - length / 2;
	P1.y = Ctr.y - length / 2;
	P2.x = Ctr.x + length / 2;
	P2.y = Ctr.y + length / 2;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}


void Output::DrawTgl(Point P1, Point P2, Point P3, GfxInfo TglGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;  //Figure should be drawn highlighted
	else
		DrawingClr = TglGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TglGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TglGfxInfo.FillClr);  //Figure should be drawn filled
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawHex(Point Ctr, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;  //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);  //Figure should be drawn filled
	}
	else
		style = FRAME;
	int vertices = 6;
	int length = 100;
	int* Px = new int[vertices];
	int* Py = new int[vertices];
	Px[0] = Ctr.x;
	Py[0] = Ctr.y - length;
	Px[1] = Ctr.x + (sqrt(3.0) * length) / 2;
	Py[1] = Ctr.y - length / 2;
	Px[2] = Ctr.x + (sqrt(3.0) * length) / 2;
	Py[2] = Ctr.y + length / 2;
	Px[3] = Ctr.x;
	Py[3] = Ctr.y + length;
	Px[4] = Ctr.x - (sqrt(3.0) * length) / 2;
	Py[4] = Ctr.y + length / 2;
	Px[5] = Ctr.x - (sqrt(3.0) * length) / 2;
	Py[5] = Ctr.y - length / 2;

	pWind->DrawPolygon(Px, Py, vertices, style);
	delete[]Px;
	delete[]Py;
	Px = NULL;
	Py = NULL;
}

void Output::DrawCir(Point Ctr, Point P2, GfxInfo CirGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;  //Figure should be drawn highlighted
	else
		DrawingClr = CirGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);  //Figure should be drawn filled
	}
	else
		style = FRAME;
	int Radius = sqrt(pow((P2.x - Ctr.x), 2) + pow((P2.y - Ctr.y), 2));

	pWind->DrawCircle(Ctr.x, Ctr.y, Radius, style);
}
//////////////////////////////////////////////  yousef ADEL _end ....

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
