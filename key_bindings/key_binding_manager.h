#ifndef KeyBindingManager_H
#define KeyBindingManager_H

#include <QDebug>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QThread>
#include <array>
#include <deque>
#include <queue>
#include <set>
#include <vector>

#include "key_binding_worker.h"
#include "qlist.h"
#include "qnamespace.h"
#include "qobject.h"
#include "qobjectdefs.h"
#include "qqmlengine.h"

namespace Bindings {
constexpr std::array<int, 2> workspace_1 = {Qt::Key_Control, Qt::Key_1};
constexpr std::array<int, 2> workspace_2 = {Qt::Key_Control, Qt::Key_2};
constexpr std::array<int, 2> workspace_3 = {Qt::Key_Control, Qt::Key_3};
constexpr std::array<int, 2> workspace_4 = {Qt::Key_Control, Qt::Key_4};
constexpr std::array<int, 2> workspace_5 = {Qt::Key_Control, Qt::Key_5};
constexpr std::array<int, 2> workspace_6 = {Qt::Key_Control, Qt::Key_6};
constexpr std::array<int, 2> workspace_7 = {Qt::Key_Control, Qt::Key_7};
constexpr std::array<int, 2> workspace_8 = {Qt::Key_Control, Qt::Key_8};
constexpr std::array<int, 2> workspace_9 = {Qt::Key_Control, Qt::Key_9};
constexpr std::array<int, 2> workspace_10 = {Qt::Key_Control, Qt::Key_0};
constexpr std::array<int, 2> toggle_blur = {Qt::Key_Control, Qt::Key_X};
constexpr int MAX_KEYBINDING_LENGTH = 2;
}  // namespace Bindings

namespace FocusTargets {
const std::set<std::string> nonBlurPrefixes = {"TextField", "TextEdit",
                                               "ComboBox"};
}

class KeyBindingManager : public QObject {
    Q_OBJECT
    QThread workerThread;

  public:
    explicit KeyBindingManager(QQmlEngine* engine, QObject* parent = nullptr);

    Q_INVOKABLE void setFocusedItem(QQuickItem* item);

  private:
    QQmlEngine* m_engine = nullptr;
    QList<int> m_sequence;
    QMap<QList<int>, std::function<void()>> m_keyBindings;

    bool m_isCtrlPressed = false;
    bool m_isBlured = false;
    bool m_canBlur = true;

    void toggle_blur();
    void checkFocusedElement();

  protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

  signals:
    void toggleBlur();
};

#endif
