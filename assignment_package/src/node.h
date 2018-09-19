#ifndef NODE
#define NODE

#include <QTreeWidgetItem>
#include <vector>
#include <QString>
#include "scene/polygon.h"

using namespace glm;
using namespace std;

class Node : public QTreeWidgetItem {
protected:
    vector<Node*> child;
    Polygon2D* geo;
    vec3 col;
public:
    QString name;

    //constructors
    Node();
    Node(QString n);
    Node(QString n, Polygon2D* g);
    Node(QString n, Polygon2D* g, vec3 c);

    virtual ~Node();

    //functions
    virtual mat3 transform() = 0;
    void addChild(Node* c);
    void addGeometry(Polygon2D* g);
    void changeColor(vec3 c);

    vector<Node*> children();
    Polygon2D* geometry();
    vec3 color();
};

#endif
