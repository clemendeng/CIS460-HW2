#pragma once

#include <openglcontext.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/grid.h>
#include <scene/polygon.h>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <node.h>

class MyGL
    : public OpenGLContext
{
    Q_OBJECT
private:
    ShaderProgram prog_flat;// A shader program that uses "flat" reflection (no shadowing at all)

    Grid m_geomGrid; // The instance of the object used to render the 5x5 grid
    Polygon2D m_geomSquare; // The singular instance of our square object that can be re-drawn with different colors
                         // to create the appearance of there being multiple squares

    Polygon2D m_geomCircle;
    bool m_showGrid; // Read in paintGL to determine whether or not to draw the grid.

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.

    Node* root;
    Node* current;

public:
    explicit MyGL(QWidget* parent = 0);
    ~MyGL();

    Node* constructGraph();

    void initializeGL();
    void resizeGL(int w, int h);
    void traverse(Node* n, mat3 t);
    void paintGL();

protected:
    void keyPressEvent(QKeyEvent* e);

public slots:
    void slot_currentNode(QTreeWidgetItem* curr);

    void slot_rotate(double deg);
    void slot_translate_x(double x);
    void slot_translate_y(double y);
    void slot_scale_x(double x);
    void slot_scale_y(double y);

    void slot_addSquare();
    void slot_addRotate();
    void slot_addScale();
    void slot_addTranslate();

signals:
    void sendRoot(QTreeWidgetItem* r);
};

