#include "key_binding_manager.h"

#include "qdebug.h"
#include "qqml.h"

void w1() {
    qDebug() << "Switched to workspace 1";
}
void w2() {
    qDebug() << "Switched to workspace 2";
}
void w3() {
    qDebug() << "Switched to workspace 3";
}
void w4() {
    qDebug() << "Switched to workspace 4";
}
void w5() {
    qDebug() << "Switched to workspace 5";
}
void w6() {
    qDebug() << "Switched to workspace 6";
}
void w7() {
    qDebug() << "Switched to workspace 7";
}
void w8() {
    qDebug() << "Switched to workspace 8";
}
void w9() {
    qDebug() << "Switched to workspace 9";
}
void w10() {
    qDebug() << "Switched to workspace 10";
}

void KeyBindingManager::checkFocusedElement() {
    QQmlContext* context = m_engine->rootContext();
}

void KeyBindingManager::setFocusedItem(QQuickItem* item) {
    if (item) {
        const char* className = item->metaObject()->className();
        // qDebug() << "Focused item type:" << className;

        m_canBlur =
            std::none_of(FocusTargets::nonBlurPrefixes.begin(),
                         FocusTargets::nonBlurPrefixes.end(),
                         [className](const std::string& prefix) {
                             return std::string(className).find(prefix) == 0;
                         });

        // qDebug() << (m_canBlur ? "Blur is enabled." : "Blur is disabled.");
    } else {
        // qDebug() << "No item is currently focused.";
        m_canBlur = true;
    }
}

void KeyBindingManager::toggle_blur() {
    checkFocusedElement();
    m_isBlured = !m_isBlured;
    qDebug() << "Blur toggled" << m_isBlured;
    if (m_canBlur)
        emit toggleBlur();
}

KeyBindingManager::KeyBindingManager(QQmlEngine* engine, QObject* parent)
    : m_engine(engine), QObject(parent) {
    m_keyBindings.insert(
        QList<int>(Bindings::workspace_1.begin(), Bindings::workspace_1.end()),
        w1);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_2.begin(), Bindings::workspace_2.end()),
        w2);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_3.begin(), Bindings::workspace_3.end()),
        w3);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_4.begin(), Bindings::workspace_4.end()),
        w4);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_5.begin(), Bindings::workspace_5.end()),
        w5);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_6.begin(), Bindings::workspace_6.end()),
        w6);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_7.begin(), Bindings::workspace_7.end()),
        w7);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_8.begin(), Bindings::workspace_8.end()),
        w8);

    m_keyBindings.insert(
        QList<int>(Bindings::workspace_9.begin(), Bindings::workspace_9.end()),
        w9);

    m_keyBindings.insert(QList<int>(Bindings::workspace_10.begin(),
                                    Bindings::workspace_10.end()),
                         w10);

    m_keyBindings.insert(
        QList<int>(Bindings::toggle_blur.begin(), Bindings::toggle_blur.end()),
        [this]() { this->toggle_blur(); });
}

bool KeyBindingManager::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        // qDebug() << "Key released:" << keyEvent->key();
        if (keyEvent->key() == Qt::Key_Control && m_isCtrlPressed)
            m_isCtrlPressed = false;
    }
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        // qDebug() << "Key pressed:" << keyEvent->key();

        if (keyEvent->key() == Qt::Key_Control)
            m_isCtrlPressed = true;

        if (m_sequence.empty() || m_sequence.back() != keyEvent->key()) {
            m_sequence.push_back(keyEvent->key());
        }

        if (m_sequence.size() > Bindings::MAX_KEYBINDING_LENGTH) {
            m_sequence.pop_front();
        }

        if (m_isCtrlPressed) {
            m_sequence.pop_front();
            m_sequence.push_front(Qt::Key_Control);
        }

        auto it = m_keyBindings.find(m_sequence);

        if (it != m_keyBindings.end()) {
            it.value()();
            m_sequence.clear();
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}
