#include "rotatenode.h"
#include <cmath>

# define M_PI           3.14159265358979323846

RotateNode::RotateNode(float deg) : Node("r"), deg(deg * M_PI / 180)
{}

RotateNode::RotateNode(float deg, QString n) : Node(n), deg(deg * M_PI / 180)
{}

RotateNode::RotateNode(float deg, QString n, Polygon2D* g) :
    Node(n, g), deg(deg * M_PI / 180)
{}

RotateNode::RotateNode(float deg, QString n, Polygon2D* g, vec3 c) :
    Node(n, g, c), deg(deg * M_PI / 180)
{}

RotateNode::~RotateNode() {
    for(Node* c : child) {
        delete c;
    }
}

void RotateNode::rotate(double d) {
    offset = d * M_PI / 180;
}

mat3 RotateNode::transform() {
    return mat3(cos(deg + offset), sin(deg + offset), 0,
                -sin(deg + offset), cos(deg + offset), 0,
                0, 0, 1);
}
