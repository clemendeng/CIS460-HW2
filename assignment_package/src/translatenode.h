#ifndef TRANSLATENODE_H
#define TRANSLATENODE_H

#include "node.h"

class TranslateNode : public Node
{
private:
    float x, y;
    float offsetx, offsety;
public:
    TranslateNode(float x, float y);
    TranslateNode(float x, float y, QString n);
    TranslateNode(float x, float y, QString n, Polygon2D* g);
    TranslateNode(float x, float y, QString n, Polygon2D* g, vec3 c);

    ~TranslateNode();

    void addX(double x);
    void addY(double y);

    mat3 transform();
};

#endif // TRANSLATENODE_H
