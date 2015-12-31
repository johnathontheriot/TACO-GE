/**
---------------------------------  T A C O  --------------------------------------------
Technically A Completely Operational Game Engine:
An OpenGL based Experimental Game Engine

-------------------------------  A U T H O R S  ----------------------------------------

Lead Design & Management (Hunnit Club):
Johnathon Theriot
Matthew Wallace

Grunt Work (The Help):
Sam Ekong
Ian Calaway

Pending:
John Patterson
Ryan Adair

----------------------------------------------------------------------------------------
**/



/*
---------------------------  I N C L U D E S  ------------------------------------------
Imported:
	glew:		OpenGL Extension Wrangler
	glm:		Temporary Includes pending the bmvl library completion

Core:

Geometry:

---------------------------------------------------------------------------------------
*/

//------------------------------  C O R E  --------------------------------------------

#include "components\engine\core\system\defaults\Constants.h"


//-------------------------  I M P O R T E D  -----------------------------------------



//-------------------------  G E O M E T R Y  -----------------------------------------

//-------------------------    S Y S T E M    -----------------------------------------

#include "components\engine\core\system\h\DirectiveParser.h"
#include "components\engine\core\system\h\Response.h"


/*
--------------------------  F R E E   F U N C T I O N S  ------------------------------

---------------------------------------------------------------------------------------
*/




void animationLoop(){
	glutPostRedisplay();
}

/*
------------------------------  M A I N  ----------------------------------------------

---------------------------------------------------------------------------------------
*/

int main(int argc, char** argv){

	glutInit(&argc, argv);
	DirectiveParser::Parse();
	glutInitWindowSize(W, H);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutIdleFunc(animationLoop);
	glutCreateWindow("OpenGL EGE");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glewExperimental = GL_TRUE;
	if (glewInit())
		exit(EXIT_FAILURE);
#ifndef MONOSCOPIC
	glutFullScreen();
#endif
	glutMainLoop();
	return 0;
}