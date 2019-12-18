TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

OTHER_FILES += \
    img/img1.jpg \
    img/img2.jpg \
    img/img3.jpg \
    img/img4.jpg \
    img/img5.jpg \
    img/img6.jpg \
    img/qt_ambassador_logo.png
