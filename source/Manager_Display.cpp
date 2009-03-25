#include "Manager_Display.h"


Manager_Display::Manager_Display()
{
    //ctor
}

Manager_Display::~Manager_Display()
{
    //dtor
}

void Manager_Display::init()
{

	// initialize gl
	glInit();

	//enable textures
	glEnable(GL_TEXTURE_2D);

	// enable antialiasing
	glEnable(GL_ANTIALIAS);

	// setup the rear plane
	glClearColor(15,15,15,31); // BG must be opaque for AA to work
	glClearPolyID(63); // BG must have a unique polygon ID for AA to work
	glClearDepth(0x7FFF);

	glLight(0, RGB15(31,31,31) , 0,				  floattov10(-1.0),		 0);
	glLight(1, RGB15(31,31,31) , 0,				  0,	floattov10(-1.0));
	glLight(2, RGB15(31,31,31) , 0,				  0,	floattov10(1.0));

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);

	//need to set up some material properties since DS does not have them set by default
	glMaterialf(GL_AMBIENT, RGB15(31,31,31));
	glMaterialf(GL_DIFFUSE, RGB15(31,31,31));
	glMaterialf(GL_SPECULAR, BIT(15) | RGB15(8,8,8));
	glMaterialf(GL_EMISSION, RGB15(31,31,31));

	//ds uses a table for shinyness..this generates a half-ass one
	glMaterialShinyness();

	// Set our viewport to be the same size as the screen
	glViewport(0,0,255,191);
}

void Manager_Display::setup_screen()
{
/// @todo (kiniou#1#):Define screen modes identifier (3D Top - 2D Bottom , 3D bottom - 2D Top , dual 3D ...)

    //set mode 0, enable BG0 and set it to 3D
    videoSetMode(MODE_0_3D);
    vramSetBankA(VRAM_A_TEXTURE);


	//vramSetBankF(VRAM_F_TEX_PALETTE);
    //videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE); //sub bg 0 will be used to print text
    //vramSetBankC(VRAM_C_SUB_BG);
    //BG_PALETTE_SUB[0]=RGB15(0,0,0);
    //SUB_BG0_CR = BG_MAP_BASE(31);
    //BG_PALETTE_SUB[255] = RGB15(31,31,31);//by default font rendered with color 255
    //consoleInitDefault((u16*)SCREEN_BASE_BLOCK_SUB(31), (u16*)CHAR_BASE_BLOCK_SUB(0), 16);

    consoleDemoInit();

    //lcdMainOnBottom();
}


void Manager_Display::begin_3D()
{
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

		// set the projection matrix as either ortho or perspectiv
    gluPerspective(35, 256.0 / 192.0, 0.1, 100);

		// Set the current matrix to be the model matrix
	glMatrixMode(GL_MODELVIEW);

		//Push our original Matrix onto the stack (save state)
	glPushMatrix();




}

void Manager_Display::end_3D()
{
    glPopMatrix(1);
}

void Manager_Display::begin_2D()
{
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

		// set the projection matrix as either ortho or perspectiv
    glOrthof32(0, 256, 192, 0,0, 10);

		// Set the current matrix to be the model matrix
	glMatrixMode(GL_MODELVIEW);

		//Push our original Matrix onto the stack (save state)
	glPushMatrix();
}

void Manager_Display::end_2D()
{
    glPopMatrix(1);
}

void Manager_Display::flush_display()
{
    glFlush(0);
    swiWaitForVBlank();
}

void Manager_Display::display_3D()
{

/// @todo (kiniou#1#):Replace code below with code displaying a Model_Scene


}


void Manager_Display::display_2D()
{

}




void Manager_Display::display_all()
{


}
