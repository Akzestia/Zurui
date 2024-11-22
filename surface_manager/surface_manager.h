
#include <QList>
#include <QObject>
#include <QQmlListProperty>
#include <QQuickItem>
#include <cstddef>
#include "surface.h"

#include "qobject.h"
#include "qqmlengine.h"
#include "qqmlparserstatus.h"
#include "qtmetamacros.h"
#include "qtypes.h"

class SurfaceManager : public QObject, public QQmlParserStatus {
    Q_OBJECT
    Q_PROPERTY(QList<Surface*> surfaces READ surfaces NOTIFY surfaceChanged)
    QML_ELEMENT
  public:
    explicit SurfaceManager(QObject* parent = nullptr);

    void componentComplete() override;
    void classBegin() override {}

    QList<Surface*> surfaces() const;

    void addSurface(Surface* window);
    void removeSurface(Surface* window);
    void moveToSurface(Surface* window);

    ~SurfaceManager() { qDeleteAll(m_surfaces); }

  signals:
    void surfaceChanged();

  private:
    QQmlEngine* m_engine = nullptr;
    QList<Surface*> m_surfaces;
    QQuickItem* m_current_surface = nullptr;
};
