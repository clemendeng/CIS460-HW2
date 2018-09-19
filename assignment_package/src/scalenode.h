#ifndef SCALENODE_H
#define SCALENODE_H

#include "node.h"

class ScaleNode : public Node
{
private:
    float x, y;
    float offsetx, offsety;
public:
    ScaleNode();
    ScaleNode(float x, float y);
    ScaleNode(float x, float y, QString n);
    ScaleNode(float x, float y, QString n, Polygon2D* g);
    ScaleNode(float x, float y, QString n, Polygon2D* g, vec3 c);

    ~ScaleNode();

    void addX(double x);
    void addY(double y);

    mat3 transform();
};

#endif // SCALENODE_H
