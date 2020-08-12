TARGET = helper
TEMPLATE = lib
CONFIG += shared c++14 x86_64
QT += xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH +=
DEPENDPATH  +=
LIBS +=
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
HEADERS += newsvalidator.h
SOURCES += newsvalidator.cpp
HEADERS += vehiclevalidator.h
SOURCES += vehiclevalidator.cpp
HEADERS += vehiclemodelvalidator.h
SOURCES += vehiclemodelvalidator.cpp
HEADERS += makevalidator.h
SOURCES += makevalidator.cpp
HEADERS += gradevalidator.h
SOURCES += gradevalidator.cpp
HEADERS += fueltypevalidator.h
SOURCES += fueltypevalidator.cpp
HEADERS += drivetypevalidator.h
SOURCES += drivetypevalidator.cpp
HEADERS += colorvalidator.h
SOURCES += colorvalidator.cpp
HEADERS += bodytypevalidator.h
SOURCES += bodytypevalidator.cpp








