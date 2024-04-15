#include "libs.h"
#include "index.h"

double degToRad(double angle)
{
    double pi = 3.14159265359;
    return (angle * (pi / 180));
}

//flags
GLboolean  day = true;

//variables to track the motion of mouse
double mouse_x = -1, mouse_y = -1;
double mouse_x_prev = -1, mouse_y_prev = -1;

static double windowHeight = 1000, windowWidth = 1000;

//intensity of the diffused light
float intensity = 0;

Human* human = new Human();
Objects* objects = new Objects();

struct Camera {
    
    double eyeX, eyeY, eyeZ; //looking from
    double refX, refY, refZ; //looking at
    int currView;

    Camera() {
        eyeX = -10;
        eyeY = 5.0;
        eyeZ = 100;
        refX = 0;
        refY = 0;
        refZ = 0;  
    }

    void setView(int view) {

        currView = view;

        if(view == 0) {
            //world view
            eyeX = -10;
            eyeY = 5.0;
            eyeZ = 100;
            refX = 0;
            refY = 0;
            refZ = 0;  
        }

        else if(view == 1) {
            //human view
            eyeX = human->human_x - 15*cos(degToRad(human->angle_x));
            eyeY = -5;
            eyeZ = human->human_z + 15*sin(degToRad(human->angle_x));
            refX = human->human_x + 15*cos(degToRad(human->angle_x));
            refY = -10;
            refZ = human->human_z - 15*sin(degToRad(human->angle_x));
        }
    }
};

Camera* camera = new Camera();

// Defining material properties
// ref. https://www.opengl.org/archives/resources/code/samples/glut_examples/examples/lightlab.c
GLfloat brass_ambient[] =
{0.33, 0.22, 0.03, 1.0}, brass_diffuse[] =
{0.78, 0.57, 0.11, 1.0}, brass_specular[] =
{0.99, 0.91, 0.81, 1.0}, brass_shininess = 27.8;

GLfloat red_plastic_ambient[] =
{0.0, 0.0, 0.0}, red_plastic_diffuse[] =
{0.5, 0.0, 0.0}, red_plastic_specular[] =
{0.7, 0.6, 0.6}, red_plastic_shininess = 32.0;

GLfloat emerald_ambient[] =
{0.0215, 0.1745, 0.0215}, emerald_diffuse[] =
{0.07568, 0.61424, 0.07568}, emerald_specular[] =
{0.633, 0.727811, 0.633}, emerald_shininess = 76.8;

GLfloat slate_ambient[] =
{0.02, 0.02, 0.02}, slate_diffuse[] =
{0.02, 0.01, 0.01}, slate_specular[] =
{0.4, 0.4, 0.4}, slate_shininess = .78125;

float diffuse_intensity = 0.5;
int select_material = 0;

// Selects material to be shown on the screen
void material(){
	if(select_material == 0){
		glMaterialfv(GL_FRONT, GL_AMBIENT, brass_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brass_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, brass_specular);
  		glMaterialf(GL_FRONT, GL_SHININESS, brass_shininess);
	}
	if(select_material == 1){
		glMaterialfv(GL_FRONT, GL_AMBIENT, emerald_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, emerald_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, emerald_specular);
  		glMaterialf(GL_FRONT, GL_SHININESS, emerald_shininess);
	}
	if(select_material == 2){
		glMaterialfv(GL_FRONT, GL_AMBIENT, red_plastic_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red_plastic_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, red_plastic_specular);
  		glMaterialf(GL_FRONT, GL_SHININESS, red_plastic_shininess);
	}
	if(select_material == 3){
		glMaterialfv(GL_FRONT, GL_AMBIENT, slate_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, slate_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, slate_specular);
  		glMaterialf(GL_FRONT, GL_SHININESS, slate_shininess);
	}
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 300);
    
    //set the view reference
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera->eyeX, camera->eyeY, camera->eyeZ, camera->refX, camera->refY, camera->refZ, 0, 1, 0);


	// material();	// selecting material

	// GLfloat light_diffuse[] = {diffuse_intensity, diffuse_intensity, diffuse_intensity, 1.0}; 	// Varing Diffuse light intersity
	
	// // Enabling Lights 
	// glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	// glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	// glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	// glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
	// glEnable(GL_LIGHT0);
	// glEnable(GL_LIGHT1);
	// glEnable(GL_LIGHT2);
	// glEnable(GL_LIGHT3);

    //enable lighting in the scene
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    //draw the sky
    glPushMatrix();
    sky(camera->eyeX + (0.05 * camera->refX), camera->eyeY + (0.05 * camera->refY), camera->eyeZ + (0.05 * camera->refZ), 250, 250, 250);
    glPopMatrix();

    glEnable(GL_DEPTH_TEST);


    // spotLight1();
    // spotLight2();
    // spotLight3();
    // spotLight4();

    camera->setView(1);

    //generate the ground
    ground();

    //draw the swimming pool
    glPushMatrix();
    glTranslatef(20, 0, -60);
    objects->drawPool();
    glPopMatrix();

    // Left Bush
    glPushMatrix();
    glTranslatef(-40, 0, -5);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-42, 0, -5);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-44, 0, -5);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-46, 0, -5);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-48, 0, -5);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-50, 0, -5);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-40, 0, -40);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-42, 0, -40);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-44, 0, -40);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-46, 0, -40);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-48, 0, -40);
    objects->fence();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-50, 0, -40);
    objects->fence();
    glPopMatrix();

    // Right Bush
    glPushMatrix();
    glTranslatef(50, 0, -5);
    objects->fence();
    glPopMatrix();
    // glPushMatrix();
    // glTranslatef(52, 0, -5);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(54, 0, -5);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(56, 0, -5);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(58, 0, -5);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(60, 0, -5);
    // objects->fence();
    // glPopMatrix();
    glPushMatrix();
    glTranslatef(50, 0, -40);
    objects->fence();
    glPopMatrix();
    // glPushMatrix();
    // glTranslatef(52, 0, -40);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(54, 0, -40);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(56, 0, -40);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(58, 0, -40);
    // objects->fence();
    // glPopMatrix();
    // glPushMatrix();
    // glTranslatef(60, 0, -40);
    // objects->fence();
    // glPopMatrix();

    //draw the dining table
    glPushMatrix();
    glTranslatef(5, 0, -40);
    objects->diningTables();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25, 0, -40);
    objects->diningTables();
    glPopMatrix();

    //draw the house
    glPushMatrix();
    glTranslatef(-40,-25, 0);
    glScalef(6,8,8);
    objects->house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(human->human_x, human->human_y, human->human_z);
    glScalef(0.3,0.3,0.3);
    glRotatef(-(90-human->angle_x), 0, 1, 0); // rotate w.r.t y axis to simulate orientation of human
    human->drawHuman();
    glPopMatrix();
    objects->walls();
    glPushMatrix();
    glTranslatef(-35, -20, 5);
    glScalef(1.5,3,2);
    glRotatef(90,0,1,0);
    objects->cupboard();
    glPopMatrix();
    glDisable(GL_LIGHTING);

    glFlush();
    glutSwapBuffers();
}


void mouseMove(int x, int y)
{
    //function to change the view reference according to mouse motion

    mouse_x = (double)x;
    mouse_y = (double)y;

    if (mouse_x_prev == -1)
        mouse_x_prev = mouse_x;
    if (mouse_y_prev == -1)
        mouse_y_prev = mouse_y;


    double delta_x = mouse_x - mouse_x_prev;
    double delta_y = mouse_y - mouse_y_prev;

    camera->eyeX += (-delta_x);
    camera->eyeY += (-delta_y);

    mouse_x_prev = mouse_x;
    mouse_y_prev = mouse_y;
}

void mouseButton(int button, int state, int x, int y)
{
    //function to handle mouse button press
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_UP)
        {
            mouse_x_prev = -1;
            mouse_y_prev = -1;
        }
    }

    //function to handle mousepad scroll for zoom functionality
    if(button == 3 || button == 4) 
    {
        if (state == GLUT_UP) return;

        if(button == 3) {
            //scroll up, i.e move fingers down hence zoom out
            camera->eyeZ += 1;
        }
        else {
            //scroll down, i.e move fingers up hence zoom in
            camera->eyeZ -= 1;
        }
    }
}



void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        camera->refX -= 1.0; //look left
        break;
    case 'd':
        camera->refX += 1.0; //look right
        break;
    case 'z':
        if (objects->controlPointsFlag == false)
        {
            objects->controlPointsFlag = true;
            break;
        }
        else if (objects->controlPointsFlag == true)
        {
            objects->controlPointsFlag = false;
            break;
        }
    case 'r':
        camera->setView(0); //reset view reference
        break;
    case 'c':
        if (day == false)
        {
            day = true;
            glEnable(GL_LIGHT0);
            glEnable(GL_LIGHT5);
            glEnable(GL_LIGHT6);
            glEnable(GL_LIGHT7);
            lighting1(-100, 100, 100, intensity);
            lighting2(100, 100, -100, intensity);
            lighting3(-100, 100, -100, intensity);
            lighting4(100, 100, 100, intensity);
            break;
        }
        else if (day == true)
        {
            day = false;
            glDisable(GL_LIGHT0);
            break;
        }
        // increase intensity
    case 'i':
        if (intensity < 1.0)
        {
            intensity += 0.1;
            lighting1(-100, 100, 100, intensity);
            lighting2(100, 100, -100, intensity);
            lighting3(-100, 100, -100, intensity);
            lighting4(100, 100, 100, intensity);
            break;
        }
        else
        {
            intensity = 1.0;
            break;
        }
        // decrease intensity
    case 'k':
        if (intensity > 0.0)
        {
            intensity -= 0.1;
            lighting1(100, 100, 100, intensity);
            lighting2(-100, 100, 100, intensity);
            lighting3(100, 100, -100, intensity);
            lighting4(-100, 100, -100, intensity);
            break;
        }
        else
        {
            intensity = 0.0;
            break;
        }
    case 27:
        exit(1);
    case 'v':
        select_material = 1;
        break;
    case 'b':
        select_material = 2;
        break;
    case 'n':
        select_material = 3;
        break;
    case 'm':
        select_material = 0;
        break;
    }

    glutPostRedisplay();
}

void specialKeyboardFunc(int key, int x, int y)
{
    human->move(key, x, y); //handle motion of the human
    
    if(camera->currView == 1){
        camera->setView(1);
    }

    glutPostRedisplay();
}

void fullScreen(int w, int h)
{
    if (h == 0)
        h = 1;
    float ratio = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluPerspective(60, ratio, 1, 500); //fov-y, aspect, zNear, zFar
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1080, 720);
    glutCreateWindow("3D House");
    // glutFullScreen(); 
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    light();

    LoadTexture("sgi images/whiteground.sgi", 2);
    LoadTexture("sgi images/whiteground.sgi", 3);
    LoadTexture("sgi images/pirate-copy.sgi", 4);
    LoadTexture("sgi images/blue_gradient.sgi", 5);
    LoadTexture("sgi images/wooden-textured-background.sgi", 8);

    LoadTexture("sgi images/scorchsky.sgi", 9);
    LoadTexture("sgi images/scorchsky.sgi", 12);
    LoadTexture("sgi images/scorchsky.sgi", 11);
    LoadTexture("sgi images/scorchsky.sgi", 10);
    LoadTexture("sgi images/scorchsky.sgi", 28);
    LoadTexture("sgi images/scorchsky.sgi", 29);

    LoadTexture("sgi images/skydrop.sgi", 13);
    LoadTexture("sgi images/skydroplogo.sgi", 14);
    LoadTexture("sgi images/green.sgi", 15);

    LoadTexture("sgi images/blue_gradient.sgi", 16);
    LoadTexture("sgi images/pinkblue.sgi", 17);
    LoadTexture("sgi images/baskin-robin-ad.sgi", 18);
    LoadTexture("sgi images/de5b9e.sgi", 19);
    LoadTexture("sgi images/retro-wooden-bedroom-furniture.sgi", 20);

    LoadTexture("sgi images/ff6d0d.sgi", 21);

    LoadTexture("sgi images/dd.sgi", 22);
    LoadTexture("sgi images/bush.sgi", 24);
    LoadTexture("sgi images/bushflower.sgi", 25);
    LoadTexture("sgi images/brickwall.sgi", 26);
    LoadTexture("sgi images/redwhite.sgi", 27);
    LoadTexture("sgi images/treebark.sgi", 30);
    LoadTexture("sgi images/bush.sgi", 31);

    LoadTexture("sgi images/brick_wall.sgi", 32);
    LoadTexture("sgi images/tiles.sgi", 33);
    LoadTexture("sgi images/water.sgi", 34);

    LoadTexture("sgi images/house2.sgi", 35);
    LoadTexture("sgi images/brick_wall.sgi", 35);


    glutReshapeFunc(fullScreen);
    glutKeyboardFunc(myKeyboardFunc);
    glutSpecialFunc(specialKeyboardFunc);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(display);
    glutMotionFunc(mouseMove);
    glutMouseFunc(mouseButton);
    glutMainLoop();

    return 0;
}
