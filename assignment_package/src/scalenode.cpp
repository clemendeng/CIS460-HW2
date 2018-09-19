#include "scalenode.h"

ScaleNode::ScaleNode() : Node("s"), x(1), y(1)
{}

ScaleNode::ScaleNode(float x, float y) : Node("s"), x(x), y(y)
{}

ScaleNode::ScaleNode(float x, float y, QString n) : Node(n), x(x), y(y)
{}

ScaleNode::ScaleNode(float x, float y, QString n, Polygon2D* g) :
    Node(n, g), x(x), y(y)
{}

ScaleNode::ScaleNode(float x, float y, QString n, Polygon2D* g, vec3 c) :
    Node(n, g, c), x(x), y(y)
{}

ScaleNode::~ScaleNode() {
    for(Node* c : child) {
        delete c;
    }
}

void ScaleNode::addX(double x) {
    offsetx = x;
}

void ScaleNode::addY(double y) {
    offsety = y;
}

mat3 ScaleNode::transform() {
    return mat3(x + offsetx, 0, 0,
                0, y + offsety, 0,
                0, 0, 1);
}
