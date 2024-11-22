#include "surface.h"

#include <QColor>
#include <QSGFlatColorMaterial>
#include <QSGGeometryNode>

Surface::Surface(QQuickItem* parent) : QQuickItem(parent) {
    setFlag(QQuickItem::ItemHasContents, true);
}

Surface::~Surface() {
}

void Surface::componentComplete() {
    QQuickItem::componentComplete();
}

QSGNode* Surface::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* data) {
    QSGGeometryNode* node = nullptr;
    QSGGeometry* geometry = nullptr;

    if (!oldNode) {
        node = new QSGGeometryNode();
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 4);
        geometry->setDrawingMode(QSGGeometry::DrawTriangleStrip);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGFlatColorMaterial* material = new QSGFlatColorMaterial();
        material->setColor(QColor("lightblue"));
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    } else {
        node = static_cast<QSGGeometryNode*>(oldNode);
        geometry = node->geometry();
    }

    // Define the rectangle's vertices
    QRectF bounds = boundingRect();
    QSGGeometry::Point2D* vertices = geometry->vertexDataAsPoint2D();
    vertices[0].set(bounds.left(), bounds.top());
    vertices[1].set(bounds.right(), bounds.top());
    vertices[2].set(bounds.left(), bounds.bottom());
    vertices[3].set(bounds.right(), bounds.bottom());

    // Return the updated node
    return node;
}
