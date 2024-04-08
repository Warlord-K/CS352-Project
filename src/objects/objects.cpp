#include "objects.h"

void Objects::drawPool()
{
    //function to draw a swimming pool

    int tx = -115, ty = 5, tz = 15;

    // right side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(200, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(200, -40, 25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, -25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // left side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, 25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(175, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(175, -20, -25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // front side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, 25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, 25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, 25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // back side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, -25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, -25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, -25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // bottom
    // glColor4f(0.5,0.77,0.87,0.8);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -40, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, -25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -40, 25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // water
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[33]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -20, -25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -20, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, 25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Objects::bush()
{
    //function to draw a bush

    quad = gluNewQuadric();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[24]);
    glPushMatrix();
    gluQuadricTexture(quad, 1);
    gluSphere(quad, 1, 100, 100);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Objects::chair()
{
    //function to draw a chair

    // seat part
    glPushMatrix();
    glScalef(0.5, 0.05, 0.5);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat left back
    glPushMatrix();
    glTranslatef(0, -1.5, 0);
    glScalef(0.05, 1.4, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat right back
    glPushMatrix();
    glTranslatef(1.35, -1.5, 0);
    glScalef(0.05, 1.4, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(0.5, 0.05, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glScalef(0.5, 0.05, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScalef(0.5, 0.05, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat left front leg
    glPushMatrix();
    glTranslatef(0, -1.5, 1.3);
    glScalef(0.05, .55, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat right front leg
    glPushMatrix();
    glTranslatef(1.35, -1.5, 1.3);
    glScalef(0.05, .55, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();
}

void Objects::table()
{
    //function to draw a table

    // table
    glPushMatrix();
    glTranslatef(-2.5, 0, -2);
    glScalef(1.6, 0.3, 1.6);
    cubicalShape(0.8, 0.4, 0.00, 0.3, 0.5, 0.5);
    glPopMatrix();

    // stand
    glPushMatrix();
    glScalef(0.1, -1, -0.1);
    cubicalShape(0, 0, 0, 0.3, 0.5, 0.5);
    glPopMatrix();

    // stand bottom
    glPushMatrix();
    glTranslatef(0, -2.8, 0);
    glScalef(1, 0.2, 1);
    sphericalShape(1, 0.549, 0.00, 0.3, 0.5, 0.5);
    glPopMatrix();
}

void Objects::DrawUmbrella(void)
{
    //function to draw an umbrella

    GLUquadricObj *qobj;
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);

    glColor4ub(255, 20, 20, 255);

    // moving the umbrella 20 units above the table
    glTranslatef(0, 12.5, 0);

    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 1.0f, 0.0f);
    gluCylinder(qobj, 0, 6, 6, 10, 1);      // Canopy
    gluCylinder(qobj, 0.2, 0.5, 45, 10, 1); // Pole

    gluDeleteQuadric(qobj);
}

void Objects::teapot(void)
{
    //function to draw a teapot

    glColor3f(1, 0.9725, 0.9059);
    glPushMatrix();
    glTranslatef(1,1,11);
    glScaled(10, 10, 10);
    glRotatef(90, -1, 0, 0);
    glutSolidTeapot(0.1);
    glPopMatrix();
}

void Objects::diningTables()
{
    //function to draw a dining set with a table, chairs, umbrella and teapot

    glPushMatrix();
    glTranslatef(0, -16, 0);
    table();
    glTranslatef(0, 12.5, 0);

    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 1.0f, 0.0f);
    teapot();
    glPopMatrix();

    for (int i = 0; i <= 360; i += 90)
    {
        glPushMatrix();
        glRotatef(i, 0, 1, 0);
        glTranslatef(-0.75, -17, -4);
        chair();
        glPopMatrix();
    }
}

void Objects::house()
{
    //function to draw a house

    materialProperty();
    glEnable(GL_TEXTURE_2D);

    // Front
    glBindTexture(GL_TEXTURE_2D, ID2[34]);
    glPushMatrix();
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    // Top
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(0, 11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.25, 1);
    quadricShape1();
    glPopMatrix();

    // Back
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(0, 0, -10);
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    // MIddle
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 2, 1);
    quadricShape4();
    glPopMatrix();

    // Left
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(0, 0, -7);
    quadricShape3();
    glPopMatrix();

    // Right
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(10, 0, -7);
    quadricShape3();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
}

void Objects::fence()
{
    //function for the cafeteria fence

    for (float i = -12; i <= 24; i += 4)
    {
        glPushMatrix();
        glTranslatef(-15.5, -17, i);
        glScalef(1, 2, 1);
        bush();
        glPopMatrix();
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[25]);

    glPushMatrix();
    glTranslatef(-17, -20, -16.5);
    glScalef(1, 0.5, 15);
    boxShape();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void Objects::diningSet()
{
    //function for the dining table
    glPushMatrix();
    glTranslatef(8, 10, 64);
    glScalef(1, 1.5, 1);
    diningTables();
    glPopMatrix();

}

void Objects::wall()
{
    //function to draw the single unit of the wall

    materialProperty();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[31]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(10, 10, 3);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 10, 3);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0, 3);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(10, 0, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Objects::walls()
{
    //function to draw the wall boundary

    //first part in front
    for (float i = -120; i <= -10; i += 10)
    {
        glPushMatrix();
        glTranslatef(i, -20, 80);
        wall();
        glPopMatrix();
    }

    //second part in front
    for (float i = 20; i <= 120; i += 10)
    {
        glPushMatrix();
        glTranslatef(i, -20, 80);
        wall();
        glPopMatrix();
    }

    
    //back part
    for (float i = -120; i <= 120; i += 10)
    {
        glPushMatrix();
        glTranslatef(i, -20, -100);
        wall();
        glPopMatrix();
    }

    //left side
    for (float i = -87; i <= 87; i += 10)
    {
        glPushMatrix();
        glTranslatef(-123, -20, i);
        glRotatef(90, 0, 1, 0);
        wall();
        glPopMatrix();
    }

    //right side
    for (float i = -87; i <= 87; i += 10)
    {
        glPushMatrix();
        glTranslatef(127, -20, i);
        glRotatef(90, 0, 1, 0);
        wall();
        glPopMatrix();
    }
}

void Objects::streetLampbody()
{
    //function to draw the body of the lamp post

    //top of the lamp
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2, 0.2, 0.2);
    toroidShape(0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 2, 5, 32, 64);
    glPopMatrix();

    //cylindrical rod of the lamp
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glScalef(0.5, 0.5, 1);
    cylindricalShape(0.1, 0.1, 0.1, 0.05, 0.05, 0.05);
    glPopMatrix();

    //bottom of the lamp
    glPushMatrix();
    glTranslatef(0, -19, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2, 0.2, 0.2);
    toroidShape(0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 2, 5, 32, 64);
    glPopMatrix();
}

void Objects::lampPost1()
{

    GLfloat no_mat[] = {0.4, 0.3, 0.2, 1.0};
    GLfloat mat_ambient[] = {0.5, 0.2, 0.6, 1.0};
    GLfloat mat_ambient_color[] = {0.2, 0.5, 0.4, 1.0};
    GLfloat mat_diffuse[] = {1.000, 0.443, 0.100, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchOne == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}

void Objects::lampPost2()
{
    GLfloat no_mat[] = {0.4, 0.2, 0.0, 1.0};
    GLfloat mat_ambient[] = {0.3, 0.3, 0.5, 1.0};
    GLfloat mat_ambient_color[] = {0.5, 0.5, 0.0, 1.0};
    GLfloat mat_diffuse[] = {0.000, 0.543, 0.100, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchTwo == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}

void Objects::lampPost3()
{

    GLfloat no_mat[] = {0.0, 1.0, 0.4, 1.0};
    GLfloat mat_ambient[] = {0.2, 0.2, 0.1, 1.0};
    GLfloat mat_ambient_color[] = {0.4, 0.6, 0.5, 1.0};
    GLfloat mat_diffuse[] = {0.000, 0.843, 0.000, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchThree == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}

void Objects::lampPost4()
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
    GLfloat mat_diffuse[] = {1.000, 0.843, 0.000, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchFour == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}



void Objects::setNormal(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2 - x1;
    Uy = y2 - y1;
    Uz = z2 - z1;

    Vx = x3 - x1;
    Vy = y3 - y1;
    Vz = z3 - z1;

    Nx = Uy * Vz - Uz * Vy;
    Ny = Uz * Vx - Ux * Vz;
    Nz = Ux * Vy - Uy * Vx;

    glNormal3f(-Nx, -Ny, -Nz);
}

long long Objects::nCr(int n, int r)
{
    if (r > n / 2)
        r = n - r; 
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void Objects::BezierCurve(double t, float xy[2], int L, GLfloat ctrlpoints[][3])
{
    double y = 0;
    double x = 0;
    t = t > 1.0 ? 1.0 : t;
    for (int i = 0; i <= L; i++)
    {
        int ncr = nCr(L, i);
        double oneMinusTpow = pow(1 - t, double(L - i));
        double tPow = pow(t, double(i));
        double coef = oneMinusTpow * tPow * ncr;
        x += coef * ctrlpoints[i][0];
        y += coef * ctrlpoints[i][1];
    }
    xy[0] = float(x);
    xy[1] = float(y);
}

void Objects::showControlPoints(int L, GLfloat ctrlpoints[][3])
{
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i <= L; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();
}

void Objects::balloonBezier()
{
    int L = 5;
    GLfloat balloonctrlpoints[6][3] = {{0.0, 0.0, 0.0}, {0.7, 0.8, 0}, {2, 0.9, 0}, {2.3, 0.5, 0}, {2.5, 0.1, 0}, {2.4, 0, 0}};

    int i, j;
    float x, y, z, r;     // current coordinates
    float x1, y1, z1, r1; // next coordinates
    float theta;

    const float startx = 0, endx = balloonctrlpoints[L][0];
    // number of angular slices
    const float dx = (endx - startx) / nt; // x step size
    const float dtheta = 2 * PI / ntheta;  // angular step size

    float t = 0;
    float dt = 1.0 / nt;
    float xy[2];
    BezierCurve(t, xy, 5, balloonctrlpoints);
    x = xy[0];
    r = xy[1];
    // rotate about z-axis
    float p1x, p1y, p1z, p2x, p2y, p2z;
    for (i = 0; i < nt; ++i) // step through x
    {
        theta = 0;
        t += dt;
        BezierCurve(t, xy, 5, balloonctrlpoints);
        x1 = xy[0];
        r1 = xy[1];

        // draw the surface composed of quadrilaterals by sweeping theta
        glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= ntheta; ++j)
        {
            theta += dtheta;
            double cosa = cos(theta);
            double sina = sin(theta);
            y = r * cosa;
            y1 = r1 * cosa; // current and next y
            z = r * sina;
            z1 = r1 * sina; // current and next z

            // edge from point at x to point at next x
            glVertex3f(x, y, z);

            if (j > 0)
            {
                setNormal(p1x, p1y, p1z, p2x, p2y, p2z, x, y, z);
            }
            else
            {
                p1x = x;
                p1y = y;
                p1z = z;
                p2x = x1;
                p2y = y1;
                p2z = z1;
            }
            glVertex3f(x1, y1, z1);
            // forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } 

    if (controlPointsFlag == true)
    {
        showControlPoints(L, balloonctrlpoints);
    }
}

void Objects::balloon()
{
    //function to draw a balloon
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glScalef(2, 2.5, 2);
    balloonBezier();
    glPopMatrix();
}

void Objects::balloonLine()
{
    //function to draw the rope attached to the balloon
    materialCurve(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(1, 10);
    glVertex2f(1, 1);
    glEnd();
}



