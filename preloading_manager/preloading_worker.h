#ifndef PreloadingWorker_H
#define PreloadingWorker_H

#include <QQmlApplicationEngine>
#include <QQmlEngine>

#include "qqmlcomponent.h"
#include "qtmetamacros.h"

class PreloadingWorker : public QObject {
    Q_OBJECT

  public:
    explicit PreloadingWorker(QQmlEngine* engine, QObject* parent = nullptr);

  public slots:
    void preload(const QString& componentName, const QUrl& url);

  signals:
    void componentPreloaded(const QString& componentName,QPointer<QQmlComponent> component);

  private:
    QQmlEngine* m_engine;
};

#endif
