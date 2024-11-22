
#ifndef Surface_H
#define Surface_H

#include <QtQml/qqmlregistration.h>

#include <QQuickItem>
#include <set>

class Surface : public QQuickItem {
    Q_OBJECT
    QML_ELEMENT
  public:
    explicit Surface(QQuickItem* parent = nullptr);
    QSGNode* updatePaintNode(QSGNode* oldNode,
                             UpdatePaintNodeData* data) override;
    ~Surface();

  protected:
    void componentComplete() override;
  signals:

  private slots:

  private:
};

#endif
