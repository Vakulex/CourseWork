QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddService/addservice.cpp \
    AddUserData/adduserdata.cpp \
    AdminPanel/adminpanel.cpp \
    DBOptions/databaseoptions.cpp \
    DatabaseManager/databasemanager.cpp \
    DeleteServices/deleteservices.cpp \
    main.cpp \

HEADERS += \
    AddService/addservice.h \
    AddUserData/adduserdata.h \
    AdminPanel/adminpanel.h \
    DBOptions/databaseoptions.h \
    DatabaseManager/databasemanager.h \
    DeleteServices/deleteservices.h

FORMS += \
    AddService/addservice.ui \
    AddUserData/adduserdata.ui \
    AdminPanel/adminpanel.ui \
    DBOptions/databaseoptions.ui \
    DeleteServices/deleteservices.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/

RESOURCES += \
    resources.qrc
