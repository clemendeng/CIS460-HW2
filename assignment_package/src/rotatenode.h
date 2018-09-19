#ifndef ROTATENODE_H
#define ROTATENODE_H

#include "node.h"

class RotateNode : public Node {
private:
    float deg;
    float offset;
public:
    RotateNode(float deg);
    RotateNode(float deg, QString n);
    RotateNode(float deg, QString n, Polygon2D* g);
    RotateNode(float deg, QString n, Polygon2D* g, vec3 c);

    ~RotateNode();

    void rotate(double deg);

    mat3 transform();
};

#endif // ROTATENODE_H
