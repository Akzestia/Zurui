#include "surface_manager.h"

SurfaceManager::SurfaceManager(QObject* parent) noexcept
    : m_engine(nullptr), QObject(parent) {
}

QList<Surface*> SurfaceManager::surfaces() const {
    return m_surfaces;
}

void SurfaceManager::componentComplete() {
    m_engine = qmlEngine(this);

    for (int i = 0; i < 10; ++i) {
        Surface* item = new Surface();
        item->setWidth(200);
        item->setHeight(200);
        m_surfaces.append(item);
    }

    qDebug() << "Initialized with 10 base surfaces";
}
