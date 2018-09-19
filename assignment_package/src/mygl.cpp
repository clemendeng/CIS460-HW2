#include "mygl.h"
#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>
#include "rotatenode.h"
#include "scalenode.h"
#include "translatenode.h"


MyGL::MyGL(QWidget* parent)
    : OpenGLContext(parent),
      prog_flat(this),
      m_geomGrid(this), m_geomSquare(this, {glm::vec3(0.5f, 0.5f, 1.f),
                                     glm::vec3(-0.5f, 0.5f, 1.f),
                                     glm::vec3(-0.5f, -0.5f, 1.f),
                                     glm::vec3(0.5f, -0.5f, 1.f)}),
      m_geomCircle(this, 20),
      m_showGrid(true), root(nullptr), current(nullptr)
{
    setFocusPolicy(Qt::StrongFocus);
}

MyGL::~MyGL()
{
    makeCurrent();

    glDeleteVertexArrays(1, &vao);
    m_geomSquare.destroy();
    m_geomCircle.destroy();
    m_geomGrid.destroy();
}

Node* MyGL::constructGraph() {
    //Rotation angles
    float hRotation = 0;
    float rLegRotation = 10;
    float lLegRotation = -10;
    float rArmRotation = 10;
    float lArmRotation = -10;

    //Geometries
    Node* box = new ScaleNode(1, 1, "Box", &m_geomSquare, vec3(0.7, 0.7, 0));
    Node* circle = new ScaleNode(1, 1, "Circle", &m_geomCircle, vec3(1, 1, 0));

    //Root
    Node* r = new RotateNode(0, "Root");

    //Body
    Node* base = new ScaleNode(2, 4, "Base");
    base->addChild(box);
    r->addChild(base);

    //Head
    Node* rHead1 = new TranslateNode(0, .5, "Head");
    Node* rHead2 = new RotateNode(hRotation);
    Node* rHead3 = new TranslateNode(0, -0.5);
    rHead1->addChild(circle);
    rHead2->addChild(rHead1);
    rHead3->addChild(rHead2);
    Node* tHead = new TranslateNode(0, 2.5);
    tHead->addChild(rHead3);
    r->addChild(tHead);

    //Legs
    //Right leg rotation
    Node* srLeg = new ScaleNode(1, 3, "Right Leg");
    Node* rrLeg1 = new TranslateNode(0, -1.5);
    Node* rrLeg2 = new RotateNode(rLegRotation);
    Node* rrLeg3 = new TranslateNode(0, 1.5);
    srLeg->addChild(box);
    rrLeg1->addChild(srLeg);
    rrLeg2->addChild(rrLeg1);
    rrLeg3->addChild(rrLeg2);

    //Translation
    Node* trLeg = new TranslateNode(0.75, -3.5);
    trLeg->addChild(rrLeg3);

    //Left leg rotation
    Node* slLeg = new ScaleNode(1, 3, "Left Leg");
    Node* rlLeg1 = new TranslateNode(0, -1.5);
    Node* rlLeg2 = new RotateNode(lLegRotation);
    Node* rlLeg3 = new TranslateNode(0, 1.5);
    slLeg->addChild(box);
    rlLeg1->addChild(slLeg);
    rlLeg2->addChild(rlLeg1);
    rlLeg3->addChild(rlLeg2);

    //Translation
    Node* tlLeg = new TranslateNode(-0.75, -3.5);
    tlLeg->addChild(rlLeg3);

    //Add legs to root
    r->addChild(trLeg);
    r->addChild(tlLeg);

    //Right Arm

    //Upper arm
    Node* srArm = new ScaleNode(1.5, 1, "Right Upper Arm");
    Node* rrArm1 = new TranslateNode(.75, 0);
    Node* rrArm2 = new RotateNode(rArmRotation);
    Node* rrArm3 = new TranslateNode(-.75, 0);
    srArm->addChild(box);
    rrArm1->addChild(srArm);
    rrArm2->addChild(rrArm1);
    rrArm3->addChild(rrArm2);
    Node* trUpperArm = new TranslateNode(1.75, 1);
    trUpperArm->addChild(rrArm3);
    r->addChild(trUpperArm);

    //Forearm
    Node* srForearm = new ScaleNode(1.5, 1, "Right Forearm");
    Node* rrForearm1 = new TranslateNode(.75, 0);
    Node* rrForearm2 = new RotateNode(rArmRotation);
    Node* rrForearm3 = new TranslateNode(-.75, 0);
    srForearm->addChild(box);
    rrForearm1->addChild(srForearm);
    rrForearm2->addChild(rrForearm1);
    rrForearm3->addChild(rrForearm2);

    Node* trForearm1 = new TranslateNode(1.5, 0);
    trForearm1->addChild(rrForearm3);
    Node* rrForearm4 = new TranslateNode(.75, 0);
    Node* rrForearm5 = new RotateNode(rArmRotation);
    Node* rrForearm6 = new TranslateNode(-.75, 0);
    rrForearm4->addChild(trForearm1);
    rrForearm5->addChild(rrForearm4);
    rrForearm6->addChild(rrForearm5);

    Node* trForearm2 = new TranslateNode(1.75, 1);
    trForearm2->addChild(rrForearm6);
    r->addChild(trForearm2);

    //Left arm

    //Upper arm
    Node* slArm = new ScaleNode(1.5, 1, "Left Upper Arm");
    Node* rlArm1 = new TranslateNode(-.75, 0);
    Node* rlArm2 = new RotateNode(lArmRotation);
    Node* rlArm3 = new TranslateNode(.75, 0);
    slArm->addChild(box);
    rlArm1->addChild(slArm);
    rlArm2->addChild(rlArm1);
    rlArm3->addChild(rlArm2);
    Node* tlUpperArm = new TranslateNode(-1.75, 1);
    tlUpperArm->addChild(rlArm3);
    r->addChild(tlUpperArm);

    //Forearm
    Node* slForearm = new ScaleNode(1.5, 1, "Left Forearm");
    Node* rlForearm1 = new TranslateNode(-.75, 0);
    Node* rlForearm2 = new RotateNode(lArmRotation);
    Node* rlForearm3 = new TranslateNode(.75, 0);
    slForearm->addChild(box);
    rlForearm1->addChild(slForearm);
    rlForearm2->addChild(rlForearm1);
    rlForearm3->addChild(rlForearm2);

    Node* tlForearm1 = new TranslateNode(-1.5, 0);
    tlForearm1->addChild(rlForearm3);
    Node* rlForearm4 = new TranslateNode(-.75, 0);
    Node* rlForearm5 = new RotateNode(lArmRotation);
    Node* rlForearm6 = new TranslateNode(.75, 0);
    rlForearm4->addChild(tlForearm1);
    rlForearm5->addChild(rlForearm4);
    rlForearm6->addChild(rlForearm5);

    Node* tlForearm2 = new TranslateNode(-1.75, 1);
    tlForearm2->addChild(rlForearm6);
    r->addChild(tlForearm2);

    return r;
}

void MyGL::initializeGL()
{
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    //    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    glGenVertexArrays(1, &vao);

    //Create the scene geometry
    m_geomGrid.create();
    m_geomSquare.create();
    m_geomCircle.create();

    // Create and set up the flat lighting shader
    prog_flat.create(":/glsl/flat.vert.glsl", ":/glsl/flat.frag.glsl");

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    glBindVertexArray(vao);

    root = constructGraph();
    sendRoot(root);
}

void MyGL::resizeGL(int w, int h)
{
    glm::mat3 viewMat = glm::scale(glm::mat3(), glm::vec2(0.2, 0.2)); // Screen is -5 to 5

    // Upload the view matrix to our shader (i.e. onto the graphics card)
    prog_flat.setViewMatrix(viewMat);

    printGLErrorLog();
}

void MyGL::traverse(Node* n, mat3 t) {
    t = t * n->transform();
    for(Node* child : n->children()) {
        traverse(child, t);
    }
    if(n->geometry() != nullptr) {
        if(n->color() != vec3(2,2,2)) {
            n->geometry()->setColor(n->color());
        }
        prog_flat.setModelMatrix(t);
        prog_flat.draw(*this, *(n->geometry()));
    }
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function updateGL is called, paintGL is called implicitly.
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (m_showGrid)
    {
        prog_flat.setModelMatrix(glm::mat3());
        prog_flat.draw(*this, m_geomGrid);
    }

    // Scene graph traversal
    traverse(root, mat3(1,0,0,
                        0,1,0,
                        0,0,1));
}

void MyGL::keyPressEvent(QKeyEvent *e)
{
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    switch(e->key())
    {
    case(Qt::Key_Escape):
        QApplication::quit();
        break;

    case(Qt::Key_G):
        m_showGrid = !m_showGrid;
        break;
    }
}

void MyGL::slot_currentNode(QTreeWidgetItem* curr) {
    current = (Node*) curr;
}

void MyGL::slot_rotate(double deg) {
    if(RotateNode* r = dynamic_cast<RotateNode*>(current)) {
        r->rotate(deg);
    }
}

void MyGL::slot_translate_x(double x) {
    if(TranslateNode* t = dynamic_cast<TranslateNode*>(current)) {
        t->addX(x);
    }
}

void MyGL::slot_translate_y(double y) {
    if(TranslateNode* t = dynamic_cast<TranslateNode*>(current)) {
        t->addY(y);
    }
}

void MyGL::slot_scale_x(double x) {
    if(ScaleNode* s = dynamic_cast<ScaleNode*>(current)) {
        s->addX(x);
    }
}

void MyGL::slot_scale_y(double y) {
    if(ScaleNode* s = dynamic_cast<ScaleNode*>(current)) {
        s->addY(y);
    }
}

void MyGL::slot_addSquare() {
    if(current->geometry() == nullptr) {
        current->addGeometry(&m_geomSquare);
    }
}

void MyGL::slot_addRotate() {
    current->addChild(new RotateNode(0));
}

void MyGL::slot_addScale() {
    current->addChild(new ScaleNode(0,0));
}

void MyGL::slot_addTranslate() {
    current->addChild(new TranslateNode(0,0));
}
