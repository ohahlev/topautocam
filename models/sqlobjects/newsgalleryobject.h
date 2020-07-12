#ifndef NEWSGALLERYOBJECT_H
#define NEWSGALLERYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT NewsGalleryObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString image;
    QString status;
    QDateTime created_at;
    QDateTime updated_at;

    enum PropertyIndex {
        Id = 0,
        Image,
        Status,
        CreatedAt,
        UpdatedAt,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("news_gallery"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString image READ getimage WRITE setimage)
    T_DEFINE_PROPERTY(QString, image)
    Q_PROPERTY(QString status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(QString, status)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
};

#endif // NEWSGALLERYOBJECT_H
