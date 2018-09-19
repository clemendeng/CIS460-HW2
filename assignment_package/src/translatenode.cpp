#include "translatenode.h"

TranslateNode::TranslateNode(float x, float y) : Node("t"), x(x), y(y)
{}

TranslateNode::TranslateNode(float x, float y, QString n) : Node(n), x(x), y(y)
{}

TranslateNode::TranslateNode(float x, float y, QString n, Polygon2D* g) :
    Node(n, g), x(x), y(y)
{}

TranslateNode::TranslateNode(float x, float y, QString n, Polygon2D* g, vec3 c) :
    Node(n, g, c), x(x), y(y)
{}

TranslateNode::~TranslateNode() {
    for(Node* c : child) {
        delete c;
    }
}

void TranslateNode::addX(double x) {
    offsetx = x;
}

void TranslateNode::addY(double y) {
    offsety = y;
}

mat3 TranslateNode::transform() {
    return mat3(1, 0, 0,
                0, 1, 0,
                x + offsetx, y + offsety, 1);
}
