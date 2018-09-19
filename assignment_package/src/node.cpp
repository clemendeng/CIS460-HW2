#include "node.h"

Node::Node() : child{vector<Node*>()}, geo{nullptr}, col(vec3(2,2,2)), name("") {
    this->QTreeWidgetItem::setText(0, name);
}

Node::Node(QString n) : child{vector<Node*>()}, geo{nullptr}, col(vec3(2,2,2)), name(n) {
    this->QTreeWidgetItem::setText(0, name);
}

Node::Node(QString n, Polygon2D* g) : child{vector<Node*>()}, geo{g}, col(vec3(2,2,2)), name(n) {
    this->QTreeWidgetItem::setText(0, name);
}

Node::Node(QString n, Polygon2D* g, vec3 c) : child{vector<Node*>()}, geo{g}, col(c), name(n) {
    this->QTreeWidgetItem::setText(0, name);
}

Node::~Node() {
    for(Node* c : child) {
        delete c;
    }
}

void Node::addChild(Node* c) {
    child.push_back(c);
    this->QTreeWidgetItem::addChild(c);
}

void Node::addGeometry(Polygon2D* g) {
    geo = g;
}

void Node::changeColor(vec3 c) {
    col = c;
}

vector<Node*> Node::children() {
    return child;
}

Polygon2D* Node::geometry() {
    return geo;
}

vec3 Node::color() {
    return col;
}
