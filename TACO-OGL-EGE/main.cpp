/**
---------------------------------  T A C O  --------------------------------------------
Technically A Completely Operational Game Engine:
An OpenGL based Experimental Game Engine

-------------------------------  A U T H O R S  ----------------------------------------

Lead Design & Management (Hunnit Club):
Johnathon Theriot
Sam Ekong

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
#include "components\engine\core\core\h\SceneManager.h"

//-------------------------  I M P O R T E D  -----------------------------------------

//-------------------------  G E O M E T R Y  -----------------------------------------

#include "components\engine\geometry\h\BufferObject.h"
#include "components\engine\geometry\h\Geometry.h"

//-------------------------    S Y S T E M    -----------------------------------------

#include "components\engine\core\system\h\DirectiveParser.h"
#include "components\engine\core\system\h\Response.h"

SceneManager * _sceneManager = NULL;

void _animate();
void _display();
void InitializeSystem();
void InitializeCallbacks();
void genTexMap();

/*
--------------------------  F R E E   F U N C T I O N S  ------------------------------

---------------------------------------------------------------------------------------
*/

void _animate(){

}

void _display(){
	/**
		We should probably do something like this:

		call SceneManager::display();

		display() should just iterate through the 
		scenes. Here we have to talk about how we re going to 
		actually display. I'd like the Scene to know nothing about displaying itself,
		but if there isn't a sensible way out of this, then I can deal.

		Whatever we decide, we need to make the display generic. There should be no
		difference between rendering to texture and rendering to frame 0.
	**/
}

void InitializeSystem(){
	DirectiveParser::Parse();
	glGetIntegerv(GL_MAX_TEXTURE_UNITS, &MaxTextureUnits);
	genTexMap();
	_sceneManager = SceneManager::getInstance();
}

void initializeCallbacks(){
	glutIdleFunc(_animate);
	glutDisplayFunc(_display);
}

void genTexMap(){
	textureUnits = new std::unordered_map<std::string, GLenum>();
	GLenum en = GL_TEXTURE0;
	for (int i = 0; i < MaxTextureUnits; i++){
		textureUnits->insert({ "GL_TEXTURE" + std::to_string(i), en++ });
	}
}

/*
------------------------------  M A I N  ----------------------------------------------

---------------------------------------------------------------------------------------
*/

int main(int argc, char** argv){
	std::unordered_map<GeometryAttribute, BufferObject *> buffers;
	BufferObjectTemplate<int> * ob = new BufferObjectTemplate<int>();
	ob->Size = 0;
	ob->Buffer = new int[];
	buffers.insert({INDEX, ob});
	auto item = buffers.at(INDEX);
	item->Size;
	vector<BufferObjectTemplate> a;

	glutInit(&argc, argv);
	InitializeSystem();
	glutInitWindowSize(W, H);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("OpenGL EGE");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glewExperimental = GL_TRUE;
	if (!glewInit())
		exit(EXIT_FAILURE);
#ifndef MONOSCOPIC
	glutFullScreen();
#endif
	glutMainLoop();
	return 0;
}